#include "mem.h"

#include <stdio.h>

struct memory_st {
    char arr[MEMORY_SIZE];
    int index;
};

struct memory_st memory = {.arr = {0}, .index = 0};

int mem_inc(void) {
    char given_elem = ++memory.arr[memory.index];
    return given_elem;
}

int mem_dec(void) {
    char given_elem = --memory.arr[memory.index];
    return given_elem;
}

int mem_left(void) {
    memory.index--;
    if (memory.index < 0) {
        memory.index = MEMORY_SIZE - 1;
    }
    return memory.index;
}

int mem_right(void) {
    memory.index++;
    if (memory.index > MEMORY_SIZE - 1) {
        memory.index = 0;
    }
    return memory.index;
}

int mem_get(void) {
    return memory.arr[memory.index];
}

int mem_set(char v) {
    memory.arr[memory.index] = v;
    return v;
}

void mem_printDebug() {
    printf("\nindex: %d mem[%d .. %d]: ",
           memory.index, memory.index, (memory.index + DEBUG_PRINT_SIZE - 1));
    for (int i = 0; i < DEBUG_PRINT_SIZE; i++)
        printf("%d ", memory.arr[memory.index + i]);
}