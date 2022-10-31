#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

void stack_push(int element);
int stack_pop(void);
int stack_isEmpty(void);
int stack_peek(void);
void stack_print(void);

#endif