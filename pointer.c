#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;

    //disini pinter p menunjuk alamat dari a, yang berisi nilai 10, maka nilai dari a dan pinter p sama, dan alamatnya juga sama

    printf("%d\n", *p);

    a = 17;
    //disini nilai a diubah menjadi 17, maka nilai pointer p berubah menjadi 17 juga

    
    *p = 20;
    //disini nilai dari ponter p diubah nilainya menjadi 20, maka nilai dari a juga menjadi 20

    

    printf("%d\n", a);
    return 0;
}
