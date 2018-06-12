#include <stdio.h>
#include <stdlib.h>

#define DESLIGAR 0
#define PEGAR_SENHA 1
#define CHAMAR_SENHA 2

typedef struct
{
    int dado;
    struct no *proximo;
} no;

typedef no *ptrNo;
ptrNo fila;
int acao = 99;
int senha = 0;

void inserirNovaSenha(ptrNo fila)
{
    senha++;
    while(fila->proximo != NULL)
    {
        fila = fila->proximo;
    }
    fila->proximo = (ptrNo) malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = senha; 
    fila->proximo = NULL;
};

void chamarSenha(ptrNo fila)
{
    ptrNo atual;
    atual = (ptrNo) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo != NULL)
    {
        fila = fila->proximo;
        atual->proximo = fila->proximo;
        printf("Chamando senha: %d\n", fila->dado);
    }
    else
    {
        printf("Fila vazia.\n");
    }
};

void exibirFila(ptrNo fila)
{
    printf("Fila: ");
    while(fila->proximo != NULL)
    {
        fila = fila->proximo;
        printf("%d ", fila->dado);
    };
    printf("\n\n");
};

//  Função que exibe o menu e obtém a ação escolhida pelo usuário.
void obterAcao()
{
    printf("\n||--------------------||\n");
    printf("||        Menu        ||\n");
    printf("|| (1) Pegar senha.   ||\n");
    printf("|| (2) Chamar senha.  ||\n");
    printf("|| (0) Desligar.      ||\n");
    printf("||--------------------||\n\n");
    exibirFila(fila);
    scanf("%d", &acao);
};

void tratarAcao()
{
    printf("\e[2J\e[H");
    switch (acao)
    {
        case DESLIGAR:
            if(fila->proximo == NULL)
            {
                printf("\nFinalizando o sistema...\n");
            }
            else
            {
                printf("\nOps! Não foi possível finalizar o sistema.");
                printf("\nÉ necessário chamar todas as senhas.\n");
                acao++;
            }
            break;

        case PEGAR_SENHA:
            inserirNovaSenha(fila);
            break;
    
        case CHAMAR_SENHA:
            chamarSenha(fila);
            break;

        default:
            printf("\nVocê selecionou uma opção inválida.");
            break;
    }
};

void iniciaFila()
{
    fila = (ptrNo) malloc(sizeof(no));
    fila->dado = senha;
    fila->proximo = NULL;
};

int main()
{
    iniciaFila();
    while(acao != 0)
    {
        obterAcao();
        tratarAcao();
    }
    return 0;
}
