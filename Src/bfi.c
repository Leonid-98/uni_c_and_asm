#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bfi.h"
#include "mem.h"
#include "stack.h"

// ############################################################################
// Increment/decrement instr
// ############################################################################

/*
    ;;;; + or -
    mov al, [esi]
    inc al / dec al
    mov [esi], al
*/
void BF_increment_printAsm(struct BF_instruction_st *instruction, int *index)
{
    for (int i = 0; i < abs(instruction->numberOfPositions); i++)
    {
        if (instruction->numberOfPositions > 0)
        {
            printf("    ; +\n");
            printf("    mov al, [esi]\n");
            printf("    inc al\n");
            printf("    mov [esi], al\n\n");
        }
        else
        {
            printf("    ; -\n");
            printf("    mov al, [esi]\n");
            printf("    dec al\n");
            printf("    mov [esi], al\n\n");
        }
    }
}

void BF_increment_run(struct BF_instruction_st *instruction, int *index)
{
    mem_add(instruction->increment);
    (*index)++;
}

struct BF_instruction_st *BF_increment_new(int increment)
{
    struct BF_instruction_st *new = NULL;
    if (increment == 0)
    {
        printf("Liitmisinstruktsiooni parameeter ei saa olla 0!");
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }
    new->increment = increment;
    new->run = BF_increment_run;
    new->printAsm = BF_increment_printAsm;
cleanup:
    return new;
}

// #######################
// Move left/right instr #
// #######################

/*
    ;;;; > or <
    call mem_right / mem_left
*/
void BF_move_printAsm(struct BF_instruction_st *instruction, int *index)
{
    for (int i = 0; i < abs(instruction->numberOfPositions); i++)
    {
        if (instruction->numberOfPositions > 0)
        {
            printf("    ; >\n");
            printf("    inc esi\n\n");
        }
        else
        {
            printf("    ; <\n");
            printf("    dec esi\n\n");
        }
    }
}

void BF_move_run(struct BF_instruction_st *instruction, int *index)
{
    mem_move(instruction->numberOfPositions);
    (*index)++;
}

struct BF_instruction_st *BF_move_new(int numberOfPositions)
{
    struct BF_instruction_st *new = NULL;
    if (numberOfPositions == 0)
    {
        printf("R/L instruktsiooni parameeter ei saa olla 0!");
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }
    new->numberOfPositions = numberOfPositions;
    new->run = BF_move_run;
    new->printAsm = BF_move_printAsm;
cleanup:
    return new;
}

// ##################
// Begin loop instr #
// ##################

/*
    ;;;; Instruktsioon [
silt_<BEGIN>:
    call mem_get
    cmp eax, 0
    je silt_<END>
*/
void BF_beginLoop_printAsm(struct BF_instruction_st *instruction, int *index)
{
    printf(";[\n");
    printf("silt_%d:\n", *index);
    printf("    mov eax, 0\n");
    printf("    mov al, [esi]\n");
    printf("    cmp eax, 0\n");
    printf("    je silt_%d\n\n", instruction->loopBackIndex);
}

void BF_beginLoop_run(struct BF_instruction_st *instruction, int *index)
{
    int val = mem_get();

    if (instruction->loopForwardIndex < 0)
    {
        printf("Tsükli algus algväärtustamata!\n");
        return;
    }

    if (val == 0)
    {
        *index = instruction->loopForwardIndex + 1;
    }
    else
    {
        ++*index;
    }
}

struct BF_instruction_st *BF_beginLoop_new(void)
{
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->loopForwardIndex = -1;
    new->run = BF_beginLoop_run;
    new->printAsm = BF_beginLoop_printAsm;
cleanup:
    return new;
}

// ################
// End loop instr #
// ################

/*
    ;;;; Instruktsioon ]
    jmp silt_<BEGIN>
silt_<END>
*/
void BF_endLoop_printAsm(struct BF_instruction_st *instruction, int *index)
{
    printf("    ; ]\n");
    printf("    jmp silt_%d\n", instruction->loopBackIndex);
    printf("silt_%d:\n\n", *index);
}

void BF_endLoop_run(struct BF_instruction_st *instruction, int *index)
{
    int val = mem_get();

    if (instruction->loopBackIndex < 0)
    {
        printf("Tsükli lõpp algväärtustamata!\n");
        return;
    }

    if (val == 0)
    {
        ++*index;
    }
    else
    {
        *index = instruction->loopBackIndex;
    }
}

struct BF_instruction_st *BF_endLoop_new(int loopBackIndex)
{
    struct BF_instruction_st *new = NULL;
    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->loopBackIndex = loopBackIndex;
    new->run = BF_endLoop_run;
    new->printAsm = BF_endLoop_printAsm;
cleanup:
    return new;
}

// #############
// Print instr #
// #############

/*
    ;;; Instruktsioon .
    call mem_get
    push eax
    call putchar
    add esp, 4
*/
void BF_print_printAsm(struct BF_instruction_st *instruction, int *index)
{
    printf("    ; .\n");
    printf("    mov eax, 0\n");
    printf("    mov al, [esi]\n");
    printf("    push eax\n");
    printf("    call putchar\n");
    printf("    add esp, 4\n\n");
}

void BF_print_run(struct BF_instruction_st *instruction, int *index)
{
    char c = mem_get();
    printf(PRINT_PARAMS);
    (*index)++;
}

struct BF_instruction_st *BF_print_new()
{
    struct BF_instruction_st *new = NULL;
    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->run = BF_print_run;
    new->printAsm = BF_print_printAsm;
cleanup:
    return new;
}

// #############
// Debug instr #
// #############

/*
    NB! Asm code not implemented (and not required either)
*/

void BF_debug_run(struct BF_instruction_st *instruction, int *index)
{
    mem_printDebug();
    (*index)++;
}

struct BF_instruction_st *BF_debug_new()
{
    struct BF_instruction_st *new = NULL;
    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->run = BF_debug_run;
cleanup:
    return new;
}

// ############
// Read instr #
// ############

/*
    NB! Asm code not implemented (and not required either)
*/

void BF_read_run(struct BF_instruction_st *instruction, int *index)
{
    int c = getc(stdin);
    if (c == EOF)
    {
        printf("Sisendi lõpp!\n");
        return;
    }
    mem_set(c);
    (*index)++;
}

struct BF_instruction_st *BF_read_new()
{
    struct BF_instruction_st *new = NULL;
    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL)
    {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    new->run = BF_read_run;
cleanup:
    return new;
}

// ############################################################################
// Main related
// ############################################################################

void printAsm(struct BF_instruction_st **inst_arr, int inst_arr_len)
{

    printf("global main\n");
    printf("extern putchar\n\n");
    printf("section .data\n");
    printf("    bfmem: times 30000 db 0\n\n");
    printf("section .text\n");
    printf("main:\n");
    printf("    push esi\n");
    printf("    mov esi, bfmem\n");

    for (int i = 0; i < inst_arr_len; i++)
    {
        if (inst_arr[i] != NULL)
        {
            inst_arr[i]->printAsm(inst_arr[i], &i);
        }
    }

    printf("    pop esi\n");
    printf("    ret\n");
}

void parse(struct BF_instruction_st **inst_arr, char *program)
{
    int i = 0;

    struct stack_st loopStack = EMPTY_STACK;

    while (program[i] != 0)
    {
        inst_arr[i] = NULL;
        switch (program[i])
        {
        case BF_INCREASE:
            inst_arr[i] = BF_increment_new(1);
            break;

        case BF_DECREASE:
            inst_arr[i] = BF_increment_new(-1);
            break;

        case BF_START_LOOP:
            inst_arr[i] = BF_beginLoop_new();
            stack_push(&loopStack, i);
            break;

        case BF_END_LOOP:
        {
            int beginIndex = stack_pop(&loopStack);
            inst_arr[i] = BF_endLoop_new(beginIndex);

            inst_arr[beginIndex]->loopForwardIndex = i;

            break;
        }

        case BF_RIGHT:
            inst_arr[i] = BF_move_new(1);
            break;

        case BF_LEFT:
            inst_arr[i] = BF_move_new(-1);
            break;

        case BF_DEBUG:
            inst_arr[i] = BF_debug_new();
            break;

        case BF_PRINT:
            inst_arr[i] = BF_print_new();
            break;

        case BF_READ:
            inst_arr[i] = BF_read_new();
            break;

        default:;
            break;
        }

        i++;
    }
}

void run(struct BF_instruction_st **inst_arr, int inst_arr_len)
{
    int i = 0;
    while (1)
    {
        if (i < 0 || i >= inst_arr_len)
            break;
        if (inst_arr[i] != NULL)
        {
            inst_arr[i]->run(inst_arr[i], &i);
        }
        else
        {
            i++;
        }
    }
}

void interpret2(char *program)
{
    int program_len = strlen(program);
    struct BF_instruction_st **inst_arr = malloc(sizeof(struct BF_instruction_st *) * program_len);

    parse(inst_arr, program);
    // run(inst_arr, program_len);
    printAsm(inst_arr, program_len);
}

/**
 * Old interpreter
 */
void interpret1(char *program)
{
    int instruction_ptr = 0;
    int loop_counter = 0;

    while (program[instruction_ptr] != 0)
    {
        switch (program[instruction_ptr])
        {
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
        case BF_READ:
        {
            int c = getc(stdin);
            if (c == EOF)
            {
                printf("Sisendi lõpp!\n");
                return;
            }
            mem_set(c);
            break;
        }
        case BF_PRINT:
        {
            char c = mem_get();
            printf(PRINT_PARAMS);
            break;
        }
        case BF_START_LOOP:
        {
            if (mem_get() == 0)
            {
                while (1)
                {
                    instruction_ptr++;
                    if (program[instruction_ptr] == ']' && loop_counter == 0)
                    {
                        break;
                    }
                    else if (program[instruction_ptr] == ']')
                    {
                        loop_counter--;
                    }
                    else if (program[instruction_ptr] == '[')
                    {
                        loop_counter++;
                    }
                }
            }
            break;
        }
        case BF_END_LOOP:
        {
            if (mem_get() != 0)
            {
                instruction_ptr--;
                while (1)
                {
                    instruction_ptr--;
                    if ((program[instruction_ptr] == '[' && loop_counter == 0))
                    {
                        break;
                    }
                    else if (program[instruction_ptr] == '[')
                    {
                        loop_counter--;
                    }
                    else if (program[instruction_ptr] == ']')
                    {
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Programmil peab olema üks parameeter, milleks on BF programm!\n");
        return 1;
    }

    interpret2(argv[1]);
    return 0;
}