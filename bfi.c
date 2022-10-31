#include "bfi.h"

#include <stdio.h>

#include "mem.h"

enum instructions_e {
    BF_RIGHT = '>',
    BF_LEFT = '<',
    BF_INCREASE = '+',
    BF_DECREASE = '-',
    BF_READ = ',',
    BF_PRINT = '.',
    BF_START_LOOP = '[',
    BF_END_LOOP = ']',
    BF_DEBUG = '#'
};

void interpret(char* program) {
    int instruction_ptr = 0;
    int loop_counter = 0;

    while (program[instruction_ptr] != 0) {
        switch (program[instruction_ptr]) {
            case BF_INCREASE:
                mem_inc();
                break;
            case BF_DECREASE:
                mem_dec();
                break;
            case BF_RIGHT:
                mem_right();
                break;
            case BF_LEFT:
                mem_left();
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_READ: {
                int c = getc(stdin);
                if (c == EOF) {
                    printf("Sisendi lõpp!\n");
                    return;
                }
                mem_set(c);
                break;
            }
            case BF_PRINT: {
                char c = mem_get();
                printf(PRINT_PARAMS);
                break;
            }
            case BF_START_LOOP: {
                if (mem_get() == 0) {
                    while (1) {
                        instruction_ptr++;
                        if (program[instruction_ptr] == ']' && loop_counter == 0) {
                            break;
                        } else if (program[instruction_ptr] == ']') {
                            loop_counter--;
                        } else if (program[instruction_ptr] == '[') {
                            loop_counter++;
                        }
                    }
                }
                break;
            }
            case BF_END_LOOP: {
                if (mem_get() != 0) {
                    instruction_ptr--;
                    while (1) {
                        instruction_ptr--;
                        if ((program[instruction_ptr] == '[' && loop_counter == 0)) {
                            break;
                        } else if (program[instruction_ptr] == '[' && loop_counter == 0) {
                            break;
                        } else if (program[instruction_ptr] == '[') {
                            loop_counter--;
                        } else if (program[instruction_ptr] == ']') {
                            loop_counter++;
                        }
                    }
                }
                break;
            }
        }
        instruction_ptr++;
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Programmil peab olema üks parameeter, milleks on BF programm!\n");
        return 1;
    }

    interpret(argv[1]);
    return 0;
}