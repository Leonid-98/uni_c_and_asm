#include <stdio.h>

#include "mem.h"
#include "stack.h"

int main() {
    int input;
    struct stack_st stack = EMPTY_STACK;

    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            stack_print(&stack);
            break;
        }
        

        if (input == -1) {
            stack_pop(&stack);
            continue;
        }
        if (input == 228) {
            stack_print(&stack);
            continue;
        }
        if (input == 322) {
            stack_free(&stack);
            continue;
        }
        if (stack_isEmpty(&stack)) {
            stack_push(&stack, input);
            continue;
        }

        if (input > 0 && stack_peek(&stack) > 0) {
            stack_push(&stack, input);

        } else if ((input > 0 && stack_peek(&stack) < 0 || input < 0)) {
            int sum = stack_peek(&stack) + input;
            if (sum != 0) {
                stack_peek(&stack);
                stack_push(&stack, sum);
            }
        }
    }

    return 0;
}