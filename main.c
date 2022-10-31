#include <stdio.h>

#include "mem.h"
#include "stack.h"

int main() {
    int input;

    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            stack_print();
            break;
        }
        if (stack_isEmpty()) {
            stack_push(input);
            continue;
        }

        if (input > 0 && stack_peek() > 0) {
            stack_push(input);

        } else if ((input > 0 && stack_peek() < 0 || input < 0)) {
            int sum = stack_peek() + input;
            if (sum != 0) {
                stack_peek();
                stack_push(sum);
            }
        }
    }

    return 0;
}