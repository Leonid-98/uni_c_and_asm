#ifndef __MEM_H__
#define __MEM_H__

#define MEMORY_SIZE 30000
#define DEBUG_PRINT_SIZE 10

int mem_inc();
int mem_dec();
int mem_left();
int mem_right();
int mem_get();
int mem_set(char v);
void mem_printDebug();

#endif