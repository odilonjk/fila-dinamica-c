#include <stdio.h>
#include <stdlib.h>

/**
 * Atividade MAPA realizada para matéria Estrutura de Dados I (Unicesumar).
 * Autor: Odilon Jonathan Kröger
 * RA: 1715070-5
 * Professor: Marcelo Lessa
 * Módulo: 52-2018
 */

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
int listaVazia = 1;
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

//  Função que exibe o menu e obtém a ação escolhida pelo usuário.
void obterAcao()
{
    printf("\n||--------------------||\n");
    printf("||        Menu        ||\n");
    printf("|| (1) Pegar senha.   ||\n");
    printf("|| (2) Chamar senha.  ||\n");
    printf("|| (0) Desligar.      ||\n");
    printf("||--------------------||\n\n");
    printf("||  Chamando senha!   ||\n");
    // if(senha > 1)
    // {
    //     printf("|| Última atendida: %d ||\n", senha);
    // }
    // printf("|| Em atendimento: %d ||\n", senha);
    // printf("|| Senha seguinte: %d ||\n", senha);

  
  
    printf("\nEscolha sua ação: ");
    scanf("%d", &acao);  
};

void tratarAcao()
{
    
    switch (acao)
    {
        case DESLIGAR:
            if(listaVazia == 1)
            {
                printf("\nFinalizando o sistema...\n");
            }
            else
            {
                printf("\nOps! Não foi possível finalizar o sistema.");
                printf("\nÉ necessário chamar todas as senhas.\n");
            }

        case PEGAR_SENHA:
            inserirNovaSenha(fila);
            break;
    
        case CHAMAR_SENHA:
            printf("\nVocê chamou a próxima senha da fila.");
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
