#ifndef __BFI_H__
#define __BFI_H__

#ifdef DEBUG
#define PRINT_PARAMS "'%c' (kood = %d)\n", c, c
#else
#define PRINT_PARAMS "%c", c
#endif

enum instructions_e
{
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

struct BF_instruction_st
{
    void (*run)(struct BF_instruction_st *instruction, int *index);
    void (*printAsm)(struct BF_instruction_st *instruction, int *index);

    union
    {
        int increment;
        int numberOfPositions;
        int loopForwardIndex;
        int loopBackIndex;
    };
};



#endif