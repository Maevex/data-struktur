#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct coba
{
    char nama[50];
    int val;
};

struct coba a, *ptr;


int main(int argc, char const *argv[])
{
    ptr = &a;

    strcpy(a.nama, "Ilham");
    printf("Nama : %s\n", ptr->nama);

    printf("Masukkan Umur : \n");
    scanf("%d", &ptr->val);
    printf("Umur : %d \n", (*ptr).val);
    return 0;
}
