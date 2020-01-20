#ifndef HW_MALLOC_H
#define HW_MALLOC_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct chunk_header* chunk_ptr_t;
typedef uint64_t chunk_info_t;

struct chunk_header {
    chunk_ptr_t prev;
    chunk_ptr_t next;
    chunk_info_t size_and_flag;
};


void *hw_malloc(size_t);
int hw_free(void *);
void *get_start_sbrk();
void *get_end_sbrk();
void print_bin(int);
void print_mmap();
chunk_ptr_t split(chunk_ptr_t, uint64_t);
void merge();
chunk_ptr_t create_chunk(chunk_ptr_t, uint64_t);
void insert_bin(chunk_ptr_t);
chunk_ptr_t delete_bin();
void insert_mmap(chunk_ptr_t);
int delete_mmap();
void set_current_chunk_size(chunk_ptr_t, uint64_t);
void set_prev_chunk_size(chunk_ptr_t, uint64_t);
void set_allocated_flag(chunk_ptr_t, uint64_t);
void set_mmap_flag(chunk_ptr_t, uint64_t);
uint64_t get_current_chunk_size(chunk_ptr_t);
uint64_t get_prev_chunk_size(chunk_ptr_t);
uint64_t get_allocated_flag(chunk_ptr_t);
uint64_t get_mmap_flag(chunk_ptr_t);
int check_chunk_freeable(chunk_ptr_t);



#endif
