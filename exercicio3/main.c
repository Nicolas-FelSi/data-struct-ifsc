#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int codigo;
    char descricao[100];
    float preco;
} tProduto;

int main()
{
    setlocale(LC_ALL, "");


    tProduto vProd[100];
    int qtd = 0, codigo;

    printf("Código: ");
    scanf("%d", &codigo);

    while(codigo != 0){
        vProd[qtd].codigo = codigo;

        fflush(stdin);
        printf("Descrição: ");
        gets(vProd[qtd].descricao);

        printf("Preço: ");
        scanf("%f", &vProd[qtd].preco);

        qtd++;

        printf("\nCódigo: ");
        scanf("%d", &codigo);
    }

    for(int i=0; i<qtd; i++){
        printf("%d %s R$%6.2f\n", vProd[i].codigo, vProd[i].descricao, vProd[i].preco);
    }

}
