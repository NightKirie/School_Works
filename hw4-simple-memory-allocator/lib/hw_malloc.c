#include "hw_malloc.h"

struct chunk_header bin[11], mmap_alloc_list;
static chunk_ptr_t start_brk = NULL;
static chunk_ptr_t end_brk = NULL;

void *hw_malloc(size_t bytes)
{
    int mem_need;
    if(bytes+24 <= 32768) {
        mem_need = pow(2, ceil(log2(bytes + sizeof(struct chunk_header))));
        if(mem_need < 32)
            mem_need = 32;
    } else {
        mem_need = bytes + 24;
    }
    //initialize bin
    for(int i = 0; i < 11; ++i) {
        if(bin[i].next == NULL && bin[i].prev == NULL) {
            bin[i].next = &bin[i];
            bin[i].prev = &bin[i];
            set_current_chunk_size(&bin[i], 0);
            set_prev_chunk_size(&bin[i], 0);
            set_allocated_flag(&bin[i], 0);
            set_mmap_flag(&bin[i], 0);
        }
    }
    //initialize mmap_alloc_list
    if(mmap_alloc_list.next == NULL && mmap_alloc_list.prev == NULL) {
        mmap_alloc_list.next = &mmap_alloc_list;
        mmap_alloc_list.prev = &mmap_alloc_list;
    }
    //alloc memory size <= 32kB, use heap
    if(mem_need <= 32768) {
        //for first time allocate memory
        if(start_brk == NULL) {
            //initialize heap
            start_brk = sbrk(65536);
            end_brk = start_brk + 65536;
            chunk_ptr_t start = create_chunk(get_start_sbrk(), 65536);
            chunk_ptr_t chunk = split(start, mem_need);
            return (void *)chunk - get_start_sbrk() + (void *)sizeof(struct chunk_header);
        } else {    //for other time allocate memory
            int bin_num = (int)log2(mem_need) - 5;
            for(int i = bin_num; i < 11; ++i) {
                if(bin[i].next != &bin[i]) {   //if bin contain free memory
                    chunk_ptr_t chunk = delete_bin(bin[i].next);   //take first one
                    chunk = split(chunk, mem_need);
                    chunk = create_chunk(chunk, mem_need);
                    return (void *)((uint64_t)chunk - (uint64_t)get_start_sbrk() + (uint64_t)sizeof(struct chunk_header));
                }
            }
            //if free memory not found
            printf("NO ENOUGH MEMORY IN HEAP\n");
            return NULL;
        }
    } else {    //alloc memory size > 32kB, use mmap
        chunk_ptr_t chunk = mmap(NULL, mem_need, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        if(chunk == (void *)-1) {
            printf("MMAP FAILED\n");
            return NULL;
        }
        set_current_chunk_size(chunk, mem_need);
        set_mmap_flag(chunk, 1);
        insert_mmap(chunk);
        return (void *)chunk;
    }
    return NULL;
}

int hw_free(void *mem)
{
    //mmap free
    if(start_brk == NULL || (uint64_t)mem >= 65536)
        return delete_mmap(mem);
    chunk_ptr_t free_mem = (chunk_ptr_t)((uint64_t)mem - (uint64_t)sizeof(struct chunk_header) + (uint64_t)start_brk);
    //address is not chunk or not freeable
    if(!check_chunk_freeable(free_mem))  {
        return 0;
    }
    //heap free
    if(free_mem >= start_brk && free_mem < end_brk) {
        insert_bin(free_mem);
        merge();
        return 1;
    }
    return 0;
}

void *get_start_sbrk(void)
{
    return start_brk;
}

void *get_end_sbrk(void)
{
    return end_brk;
}

void print_bin(int bin_number)
{
    chunk_ptr_t ptr = bin[bin_number].next;
    while(ptr != &bin[bin_number]) {
        printf("0x%012lx--------%ld\n", (uint64_t)ptr - (uint64_t)start_brk, get_current_chunk_size(ptr));
        ptr = ptr->next;
    }
}

void print_mmap()
{
    chunk_ptr_t ptr = mmap_alloc_list.next;
    while(ptr != &mmap_alloc_list) {
        printf("0x%012lx--------%ld\n", (uint64_t)ptr - (uint64_t)start_brk, get_current_chunk_size(ptr));
        ptr = ptr->next;
    }
}

chunk_ptr_t split(chunk_ptr_t chunk, uint64_t mem_need)
{
    while(get_current_chunk_size(chunk) != mem_need) {
        chunk_ptr_t low = chunk;
        chunk_ptr_t high = (chunk_ptr_t)((uint64_t)chunk + get_current_chunk_size(chunk) / 2);
        uint64_t half_size = get_current_chunk_size(chunk) / 2;

        low = create_chunk(low, half_size);
        high = create_chunk(high, half_size);

        insert_bin(high);
        chunk = low;
    }
    return chunk;
}

int check_chunk_freeable(chunk_ptr_t chunk)     //check chunk is freeable & is < 32kB
{
    if(chunk < start_brk || chunk >= end_brk) {    //chunk is not in heap, check for mmap
        chunk_ptr_t ptr = mmap_alloc_list.next;
        while(ptr != &mmap_alloc_list) {
            if(ptr == chunk)
                return 1;   //chunk in mmap_alloc_list
            ptr = ptr->next;
        }
        return 0;   //not in heap, and not in mmap_alloc_list, not freeable address
    }
    if(chunk >= start_brk && chunk < end_brk) { //find if in heap
        chunk_ptr_t ptr = start_brk;
        while(ptr < chunk) {
            ptr = (chunk_ptr_t)((uint64_t)ptr + (uint64_t)get_current_chunk_size(ptr));    //go through heap to find the chunk
        }
        if(ptr != chunk || !get_allocated_flag(ptr)) //if the nearest ptr to chunk is not itself, or this chunk is free
            return 0;
        else    //found chunk in heap, and is freeable
            return 1;
    }
    return 0;
}

void merge()
{
    int flag = 0;
    for(int i = 0; i < 10; ++i) {   //bin[10] don't need to merge
        chunk_ptr_t ptr = bin[i].next;
        while(ptr != &bin[i]) {
            if((uint64_t)ptr + get_current_chunk_size(ptr) == (uint64_t)ptr->next) {   //ptr & ptr.next are next to each other
                delete_bin(ptr->next);
                ptr = delete_bin(ptr);
                create_chunk(ptr, get_current_chunk_size(ptr)*2);
                insert_bin(ptr);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
    }
    if(flag == 1)
        merge();
    else
        return;
    return;
}

void insert_bin(chunk_ptr_t chunk)
{
    int bin_num = (int)log2(get_current_chunk_size(chunk)) - 5;
    chunk_ptr_t ptr = &bin[bin_num];
    while(ptr->next != &bin[bin_num] && ptr->next <= chunk)
        ptr = ptr->next;
    chunk->prev = ptr;
    chunk->next = ptr->next;
    ptr->next->prev = chunk;
    ptr->next = chunk;
    set_prev_chunk_size(chunk, get_current_chunk_size(ptr));
    set_allocated_flag(chunk, 0);
}

chunk_ptr_t delete_bin(chunk_ptr_t chunk)
{
    int bin_num = (int)log2(get_current_chunk_size(chunk)) - 5;
    chunk_ptr_t ptr = bin[bin_num].next;
    while(ptr != &bin[bin_num]) {
        if(ptr == chunk) {
            set_prev_chunk_size(ptr, 0);
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->next = NULL;
            ptr->prev = NULL;
            return chunk;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void insert_mmap(chunk_ptr_t chunk)
{
    chunk_ptr_t ptr = &mmap_alloc_list;
    while(ptr->next != &mmap_alloc_list && (uint64_t)get_current_chunk_size(ptr->next) <= (uint64_t)get_current_chunk_size(chunk))
        ptr = ptr->next;
    chunk->prev = ptr;
    chunk->next = ptr->next;
    ptr->next->prev = chunk;
    ptr->next = chunk;
    set_prev_chunk_size(chunk, get_current_chunk_size(ptr));
    set_allocated_flag(chunk, 0);
    set_mmap_flag(chunk, 1);
}

int delete_mmap(chunk_ptr_t chunk)
{
    chunk_ptr_t ptr = mmap_alloc_list.next;
    while(ptr != &mmap_alloc_list) {
        if(ptr == chunk) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            ptr->next = NULL;
            ptr->prev = NULL;
            set_prev_chunk_size(ptr, 0);
            munmap(ptr, get_current_chunk_size(ptr));
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

chunk_ptr_t create_chunk(chunk_ptr_t start, uint64_t mem_need)
{
    if((uint64_t)start - (uint64_t)get_start_sbrk() + mem_need > 65536) {
        printf("NO ENOUGH MEMORY IN HEAP\n");
        return NULL;
    }
    chunk_ptr_t chunk = start;
    chunk->next = NULL;
    chunk->prev = NULL;
    chunk->size_and_flag = 0;   //for reset the chunk, if it's in use
    set_current_chunk_size(chunk, mem_need);
    set_prev_chunk_size(chunk, 0);
    set_allocated_flag(chunk, 1);
    set_mmap_flag(chunk, 0);
    return chunk;
}

void set_current_chunk_size(chunk_ptr_t chunk, uint64_t size)
{
    chunk->size_and_flag += size << 2;
}

void set_prev_chunk_size(chunk_ptr_t chunk, uint64_t size)
{
    chunk->size_and_flag += size << 33;
}

void set_allocated_flag(chunk_ptr_t chunk, uint64_t flag)
{
    chunk->size_and_flag += flag << 1;
}

void set_mmap_flag(chunk_ptr_t chunk, uint64_t flag)
{
    chunk->size_and_flag += flag;
}

uint64_t get_current_chunk_size(chunk_ptr_t chunk)
{
    return (chunk->size_and_flag << 31) >> 33;
}

uint64_t get_prev_chunk_size(chunk_ptr_t chunk)
{
    return chunk->size_and_flag >> 33;
}

uint64_t get_allocated_flag(chunk_ptr_t chunk)
{
    return (chunk->size_and_flag << 62) >> 63;
}

uint64_t get_mmap_flag(chunk_ptr_t chunk)
{
    return (chunk->size_and_flag << 63) >> 63;
}
