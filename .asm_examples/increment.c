#include <stdio.h>

unsigned int increment(unsigned int);

int main()
{
    unsigned int i = increment(10);
    printf("i = %d\n", i);

    return 0;
}