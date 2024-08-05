#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[4][4] = {2,4,6,8,1,3,5,7,8,6,4,2,7,5,3,1};
    int lin, col;
    int soma = 0;
    int vSomaCol[4] = {0,0,0,0};
    int vSomaLin[4] = {0,0,0,0};

    for(lin=0; lin<=3;lin++){
        for(col=0; col<=3;col++){
            printf("%d %d = %d\n", lin, col, matriz[lin][col]);
            soma += matriz[lin][col];
            vSomaCol[col] += matriz[lin][col];
            vSomaLin[lin] += matriz[lin][col];
        }

    }
    printf("\nsoma: %d", soma);
    for(int i=0;i<=3; i++){
        printf("\nsomalin %d = %d", i,vSomaLin[i]);
    }
    for(int i=0;i<=3; i++){
        printf("\nsomacol %d = %d", i,vSomaCol[i]);
    }

}
