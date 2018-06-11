#include <stdio.h>
#include <stdlib.h>

/**
 * Atividade MAPA realizada para matéria Estrutura de Dados I (Unicesumar).
 * Autor: Odilon Jonathan Kröger
 * RA: 1715070-5
 * Professor: Marcelo Lessa
 * Módulo: 52-2018
 */

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

//  Função que exibe o menu e obtém a ação escolhida pelo usuário.
void obterAcao()
{
    printf("\n||--------------------||\n");
    printf("||        Menu        ||\n");
    printf("|| (1) Pegar senha.   ||\n");
    printf("|| (2) Chamar senha.  ||\n");
    printf("|| (0) Desligar.      ||\n");
    printf("||--------------------||\n");
    printf("\nEscolha sua ação: ");
    scanf("%d", &acao);  
};

void tratarAcao()
{
    
    switch (acao)
    {
        case PEGAR_SENHA:
            printf("\nVocê pegou uma senha.");
            break;
    
        case CHAMAR_SENHA:
            printf("\nVocê chamou a próxima senha da fila.");
            break;

        default:
            printf("\nVocê selecionou uma opção inválida.");
            break;
    }
};

int main()
{
    while(acao != 0)
    {
        obterAcao();
        tratarAcao();
    }
    return 0;
}
