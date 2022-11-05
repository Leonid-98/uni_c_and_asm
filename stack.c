#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack_st stack = EMPTY_STACK;

void stack_push(struct stack_st *stack, int element) {
    if (stack->size == 0 || stack->arr == NULL) {
        stack->size = 1;
        stack->arr = malloc(sizeof(int) * stack->size);
        if (stack->arr == NULL) {
            printf("Mälu otsas!\n");
            return;
        }
        stack->len = 0;
    } else if (stack->len == stack->size) {
        int tmp_size = stack->size * 2;
        int *tmp_arr = NULL;

        tmp_arr = realloc(stack->arr, sizeof(int) * tmp_size);
        if (tmp_arr == NULL) {
            printf("Mäluala suuruse muutmine ebaõnnestus.\n");
            return;
        }
        stack->arr = tmp_arr;
        stack->size = tmp_size;
    }
    stack->arr[stack->len] = element;
    stack->len++;
    return;
}

int stack_pop(struct stack_st *stack) {
    int element;
    if (stack->len <= 0) {
        stack->len = 0;
        stack->size = 0;
        stack->arr = NULL;
        element = 0;
    } else {
        element = stack->arr[--stack->len];
        free(stack->arr + stack->len);
        stack->size--;
    }
    return element;
}

int stack_peek(struct stack_st *stack) {
    return stack->arr[stack->len - 1];
}

int stack_isEmpty(struct stack_st *stack) {
    return stack->len == 0;
}

void stack_print(struct stack_st *stack) {
    printf("DEBUG: size=%d addr=%x\n", stack->size, stack->arr);
    int *value_ptr = stack->arr + stack->len;
    for (int i = stack->len; i > 0; i--) {
        value_ptr--;
        printf("| %d\n", *value_ptr);
    }
    printf("====\n");
}