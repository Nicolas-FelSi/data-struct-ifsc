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

    tProduto p1;

    printf("Digite o código do produto: ");
    scanf("%d", &p1.codigo);

    fflush(stdin);
    printf("\nDigite a descrição do produto: ");
    gets(p1.descricao);

    printf("\nDigite o preço do produto: ");
    scanf("%f", &p1.preco);

    printf("Código: %d", p1.codigo);
    printf("\nDescrição: %s", p1.descricao);
    printf("\nPreço: R$%.2f ", p1.preco);
}
