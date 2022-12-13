#ifndef __MEM_H__
#define __MEM_H__

#define MEMORY_SIZE 30000
#define DEBUG_PRINT_SIZE 10

struct BF_instruction_st {
    void (*run)(struct BF_instruction_st *instruction, int *index);

    union {
        int increment;
        int numberOfPositions;
        int loopForwardIndex;

        int loopBackIndex;
    };
};

int mem_inc();
int mem_dec();
int mem_left();
int mem_right();
int mem_get();
int mem_set(char v);
int mem_add(int amount);
int mem_move(int numberOfPositions);
void mem_init();
void mem_printDebug();

#endif