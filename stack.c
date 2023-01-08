#include <stdio.h>
#include <stdlib.h>

#include "stack.h"



struct stack_st stack = EMPTY_STACK;

void stack_push(struct stack_st *stack, int element)
{
    if (stack->size == 0 || stack->arr == NULL)
    {
        stack->size = 1;
        stack->arr = malloc(sizeof(int) * stack->size);
        if (stack->arr == NULL)
        {
            printf("Mälu otsas!\n");
            return;
        }
        stack->len = 0;
    }
    else if (stack->len == stack->size)
    {
        int tmp_size = stack->size * 2;
        int *tmp_arr = NULL;

        tmp_arr = realloc(stack->arr, sizeof(int) * tmp_size);
        if (tmp_arr == NULL)
        {
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

int stack_pop(struct stack_st *stack)
{
    stack->len--;
    int element = stack->arr[stack->len];
    

    if (stack->len <= 0)
    {
        stack_free(stack); // TODO check datatype
        return 0;
    }
    else
    {
        if (stack->len < stack->size / 4)
        {
            int tmp_size = stack->size / 2;
            int *tmp_arr = NULL;

            tmp_arr = realloc(stack->arr, sizeof(int) * tmp_size);
            if (tmp_arr == NULL)
            {
                printf("Mäluala suuruse vähendamine ebaõnnestus.\n");
                return 0;
            }
            stack->arr = tmp_arr;
            stack->size = tmp_size;
        }
        
    }
    return element;
}

int stack_peek(struct stack_st *stack)
{
    return stack->arr[stack->len - 1];
}

int stack_isEmpty(struct stack_st *stack)
{
    return stack->len == 0;
}

void stack_print(struct stack_st *stack)
{
    int *value_len = stack->arr + stack->len;
    // printf("== stack len: %d stack size %d==\n", stack->len, stack->size);
    for (int i = stack->len; i > 0; i--)
    {
        value_len--;
        printf("%d\n", *value_len);
    }
    // printf("==\n");
}

void stack_free(struct stack_st *stack)
{
    free(stack->arr);
    stack->arr = NULL;
    stack->len = 0;
    stack->size = 0;
}