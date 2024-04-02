#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int *pc, c;

    c= 5;

    pc = &c;

    c = 1;

    printf("%d", *pc);
    return 0;
}
