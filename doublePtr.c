#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 10;
    int *px, *ppx;
    px = &px;
    ppx = &px;
    return 0;
}
