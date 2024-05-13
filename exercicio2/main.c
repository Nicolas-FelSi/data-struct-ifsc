#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");


    int vProd[100];
    int qtd = 0, codigo;

    scanf("%d", &codigo);

    while(codigo != 0){
        vProd[qtd] = codigo;
        qtd++;

        scanf("%d", &codigo);
    }

    for(int i=0; i<qtd; i++){
        printf("\n%d", vProd[i]);
    }

}
