#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack_st {
    int len;
    int size;
    int* arr;
};

struct stack_st stack = {.len = 0, .size = 0, .arr = NULL};

void stack_push(int element) {
    printf("\n---\nstack len=%d stack size=%d arr=%x\n", stack.len, stack.size, stack.arr);
    if (stack.size == 0 || stack.arr == NULL) {
        stack.size = 1;
        stack.arr = malloc(sizeof(int) * stack.size);
        if (stack.arr == NULL) {
            printf("Mälu otsas!\n");
            return;
        }
        stack.len = 0;
    } else if (stack.len == stack.size) {
        int tmp_size = stack.size * 2;
        int* tmp_arr = NULL;

        tmp_arr = realloc(stack.arr, tmp_size);
        if (tmp_arr == NULL) {
            printf("Mäluala suuruse muutmine ebaõnnestus.\n");
            return;
        }
        stack.arr = tmp_arr;
        stack.size = tmp_size;
    }
    stack.arr[stack.len] = element;
    stack.len++;
    printf("stack len=%d stack size=%d arr=%x elem on top:%d\n---\n\n", stack.len, stack.size, stack.arr, *(stack.arr + stack.len - 1));
    stack_print();
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
    int* value_ptr = stack.arr + stack.len;
    for (int i = stack.len; i > 0; i--) {
        value_ptr--;
        printf("/ %d\n", *value_ptr);
    }
    printf("====\n");
}