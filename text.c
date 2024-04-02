#include <stdio.h>

void swap(int *a, int *b){
    int c;
    c = *a;
    *a =  *b;
    *b = c;
}





int main(int argc, char const *argv[])
{
    int i = 5;
    int j = 4;

    printf("i = %d, j = %d\n", i, j);

    swap(&i, &j);

    printf("Now, i = %d, j = %d\n", i,j);

    int k = 6;
    int *ptr;
    ptr = &k;
    printf("k = %d\n", k);

    *ptr = 7;
    printf("Now, k = %d\n", k);

    int l[10] = {10,2,9,17,5,9,0,7,5,3};
    for (int k = 0; k < 10; k++)
    {
        printf("%d", *(l+k));
    }
    
    getchar();
    return 0;
}
