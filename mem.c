#include "mem.h"

#include <stdio.h>

struct memory_st memory = {.arr = {0}, .index = 0};

int mem_add(int amount)
{
    char given_elem = memory.arr[memory.index] += amount;
    return given_elem;
}

int mem_move(int numberOfPositions)
{
    memory.index += numberOfPositions;
    if (memory.index < 0)
    {
        memory.index = MEMORY_SIZE - 1;
    }
    else if (memory.index > MEMORY_SIZE - 1)
    {
        memory.index = 0;
    }
    return memory.index;
}

int mem_inc(void)
{
    return mem_add(1);
}

int mem_dec(void)
{
    return mem_add(-1);
}

int mem_left(void)
{
    return mem_move(-1);
}

int mem_right(void)
{
    return mem_move(1);
}

int mem_get(void)
{
    return memory.arr[memory.index];
}

int mem_set(char v)
{
    memory.arr[memory.index] = v;
    return v;
}

void mem_init()
{
    for (int i = 0; i < MEMORY_SIZE; i++)
    {
        memory.arr[i] = 0;
    }
    memory.index = 0;
}

void mem_printDebug()
{
    printf("\nindex: %d mem[%d .. %d]: ",
           memory.index, memory.index, (memory.index + DEBUG_PRINT_SIZE - 1));
    for (int i = 0; i < DEBUG_PRINT_SIZE; i++)
    {
        printf("%d ", memory.arr[memory.index + i]);
    }
}