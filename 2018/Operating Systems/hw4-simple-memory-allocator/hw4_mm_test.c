#include "hw4_mm_test.h"

int main(int argc, char *argv[])
{
    char input[30];
    while(!feof(stdin)) {
        if(fgets(input, 30, stdin) != NULL) {
            // get elements in command, to simulate argc & argv
            int argc = 1;	// initialize to 1 for "add"
            char *findSpace = strchr(input, ' ');
            while(findSpace != NULL && strcmp(findSpace, " ")) {
                ++argc;
                findSpace = strchr(findSpace+1, ' ');
            }
            char *argv[argc], *eachElement = strtok(input, " ");
            for(int i = 0; i < argc && eachElement != NULL; ++i) {
                argv[i] = malloc(strlen(eachElement) + 1);
                strcpy(argv[i], eachElement);
                eachElement = strtok(NULL, " ");
            }

            if(!strncmp(argv[0], "alloc", 5)) {
                if(argc == 2) {
                    int64_t mem_need = atoll(argv[1]);
                    void* ptr = hw_malloc(mem_need);
                    if(ptr != NULL)
                        printf("0x%012lx\n", (uint64_t)ptr);
                    else
                        printf("NULL\n");
                }
            } else if(!strncmp(argv[0], "free", 4)) {
                if(argc == 2) {
                    void *free_mem = (void *)strtol(argv[1], NULL, 16);
                    printf("%s\n", hw_free(free_mem) == 1 ? "success" : "fail");
                }
            } else if(!strncmp(argv[0], "print", 5)) {
                if(!strncmp(argv[1], "mmap_alloc_list", 15)) {
                    print_mmap();
                } else {
                    if(argc == 2) {
                        int bin_num = atoi(argv[1]+4);
                        if(bin_num < 0 || bin_num > 10)
                            printf("ERROR BIN NUMBER\n");
                        else
                            print_bin(bin_num);
                    }
                }
            }
        }
    }
    return 0;
}
