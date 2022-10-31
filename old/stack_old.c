#include "stack.h"

#include <stdio.h>

struct stack_st {
    int len;
    int arr[STACK_SIZE];
};

struct stack_st stack = {.len = 0};

void stack_push(int elem) {
    if (stack.len >= STACK_SIZE) {
        printf("Viga: pinusse rohkem elemente ei mahu\n");
    } else {
        stack.arr[stack.len] = elem;
        stack.len++;
    }
    return;
}

int stack_pop(void) {
    int element;
    if (stack.len == 0) {
        element = 0;
    } else {
        element = stack.arr[stack.len - 1];
        stack.len--;
    }
    return element;
}

int stack_peek(void) {
    return stack.arr[stack.len - 1];
}

int stack_isEmpty(void) {
    return stack.len == 0;
}

void stack_print(void) {
    printf("\n====\n");
    for (int i = stack.len - 1; i >= 0; i--) {
        printf("/ %d\n", stack.arr[i]);
    }
    printf("====\n");
}