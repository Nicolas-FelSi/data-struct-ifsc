#include <stdio.h>
#include <stdlib.h>

int main()
{
    int uni, dez;

    dez = 0;
    while (dez <= 9){
        uni = 0;
        while(uni<=9){
            printf("%d %d\n", dez, uni);
            uni++;
        }
        dez++;
    }
}
