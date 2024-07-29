#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
} tProd;

int mostrar_menu(){
    int opcao;
    system("cls");
    printf("Menu Principal\n");
    printf(" 1. Incluir\n");
    printf(" 2. Listar\n");
    printf(" 3. Pesquisar\n");
    printf(" 4. Gravar Arquivo\n");
    printf(" 5. Ler Arquivo\n");
    printf(" 0. Sair\n");
    printf(" Tecle Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int inclusao(tProd* vProd, int qtd){
    system("cls");
    printf("Inclusao\n");
    //printf("codigo...:");
    //scanf("%d", &vProd[qtd].codigo);
    fflush(stdin);
    vProd[qtd].codigo = qtd+1;

    printf("descricao..:");
    fflush(stdin);

    gets(vProd[qtd].descricao);
    printf("preco...:");
    scanf("%f", &vProd[qtd].preco);

    printf("Registro Incluido!\n");
    system("pause");
    return qtd+1;
}

int listar(tProd* vProd, int qtd){
    int i;
    system("cls");
    printf("---------------------------------------------------\n");
    printf("|               Listagem de produtos              |\n");
    printf("---------------------------------------------------\n");
    for(i=0; i<qtd; i++){
        printf("| %5d | %-30s | %6.2f |\n", vProd[i].codigo, vProd[i].descricao, vProd[i].preco);
    }
    printf("---------------------------------------------------\n");
    printf("|              Total de Registros: %3d            |\n", qtd);
    printf("---------------------------------------------------\n");
    system("pause");
}

int pesquisar(tProd* vProd, int qtd){
    int i;
    int cont = 0;
    char buscar[50];
    system("cls");
    printf("Informe a expressao de busca:");
    fflush(stdin);
    gets(buscar);
    system("cls");
    printf("---------------------------------------------------\n");
    printf("|               Pesquisa de produtos              |\n");
    printf("---------------------------------------------------\n");
    for(i=0; i<qtd; i++){
        if(strstr(strlwr(vProd[i].descricao), strlwr(buscar)) != NULL){
            printf("| %5d | %-30s | %6.2f |\n", vProd[i].codigo, vProd[i].descricao, vProd[i].preco);
            cont++;
        }

    }
    printf("---------------------------------------------------\n");
    printf("|              Total de Registros: %3d            |\n", cont);
    printf("---------------------------------------------------\n");
    system("pause");
}

int gravar_arquivo(tProd* vProd, int qtd) {
    char nomeArquivo[] = "produtos.csv";
    FILE* file = fopen(nomeArquivo, "w");
    if(file == NULL) {
        printf("Erro ao tentar gravar o arquivo\n");
    } else {
        for(int i=0; i<qtd; i++){
            fprintf(file, "%d;%s;%f \n", vProd[i].codigo, vProd[i].descricao, vProd[i].preco);
        }
    }
    printf("Arquivo gravado com sucesso.\n");
    system("pause");
    fclose(file);
}

int ler_arquivo(tProd* vProd) {
    int cont = 0;
    char* token;
    char linha[256] = "";
    char nomeArquivo[] = "produtos.csv";
    FILE* file = fopen(nomeArquivo, "r");
    if(file == NULL) {
        printf("Erro ao tentar ler o arquivo\n");
    } else {
        while(fgets(linha, 256, file)) {
            printf("%s", linha);

            token = strtok(linha, ";\n");
            vProd[cont].codigo = atoi(token);

            token = strtok(NULL, ";\n");
            strcpy(vProd[cont].descricao, token);

            token = strtok(NULL, ";\n");
            vProd[cont].preco = atof(token);

            cont++;
        }
        printf("Registro lidos: %d\n", cont);
    }
    fclose(file);
    system("pause");
    return cont;
}

int main()
{
    tProd vProd[3];
    int qtd = 0;
    int opcao;

    do
    {
        opcao = mostrar_menu();
        switch(opcao){
            case 1:
                qtd = inclusao(vProd, qtd);
                break;
            case 2:
                listar(vProd, qtd);
                break;
            case 3:
                pesquisar(vProd, qtd);
                break;
            case 4:
                gravar_arquivo(vProd, qtd);
                break;
            case 5:
                qtd = ler_arquivo(vProd);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
            printf("Opcao Invalida\n");
            system("pause");
        }
    }while(opcao != 0);
}
