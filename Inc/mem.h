#ifndef __MEM_H__
#define __MEM_H__

#define MEMORY_SIZE 30000
#define DEBUG_PRINT_SIZE 10

struct memory_st
{
    char arr[MEMORY_SIZE];
    int index;
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