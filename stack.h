#ifndef __STACK_H__
#define __STACK_H__

#define EMPTY_STACK (struct stack_st) { 0, 0, NULL }

struct stack_st {
    int len;
    int size;
    int *arr;
};

void stack_push(struct stack_st *stack, int element);
int stack_pop(struct stack_st *stack);
int stack_isEmpty(struct stack_st *stack);
int stack_peek(struct stack_st *stack);
void stack_print(struct stack_st *stack);

#endif