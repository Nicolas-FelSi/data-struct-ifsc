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

    printf("Digite o c�digo do produto: ");
    scanf("%d", &p1.codigo);

    fflush(stdin);
    printf("\nDigite a descri��o do produto: ");
    gets(p1.descricao);

    printf("\nDigite o pre�o do produto: ");
    scanf("%f", &p1.preco);

    printf("C�digo: %d", p1.codigo);
    printf("\nDescri��o: %s", p1.descricao);
    printf("\nPre�o: R$%.2f ", p1.preco);
}
