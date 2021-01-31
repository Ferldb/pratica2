#include "RotaOnibus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct RotaOnibus
{
    char nome_rota[50];
    ListaCidade *prox_cidade;
    struct RotaOnibus *prox;
};

struct cidade
{
    char nome[30];
    char descricao[200];
    struct cidade *ant;
    struct cidade *prox;
};

typedef struct RotaOnibus ElemR;
typedef struct cidade ElemC;

Lista *cria_lista()
{
    Lista *list = (Lista *)malloc(sizeof(Lista));

    if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

ListaCidade *cria_lista2()
{
    ListaCidade *list = (ListaCidade *)malloc(sizeof(ListaCidade));
    if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

void cadastrar_rota(Lista *list)
{
    system("cls");
    ElemR *no = (ElemR *)malloc(sizeof(ElemR));
    ElemC *curitiba = (ElemC *)malloc(sizeof(ElemC));
    ElemR *aux;
    no->prox_cidade = cria_lista2();
    printf("Qual o nome da rota ?");
    setbuf(stdin, NULL);
    gets(no->nome_rota);
    curitiba->prox = NULL;
    strcpy(curitiba->nome, "Curitiba");
    strcpy(curitiba->descricao, "Conhecida por ser a capital ecologica do Brasil");
    curitiba->ant = NULL;
    *(no)->prox_cidade = curitiba;
    no->prox = NULL;
    if ((*list) == NULL)
    {
        no->prox = (*list);
        *list = no;
    }
    else
    {
        aux = *list;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        *(no)->prox_cidade = curitiba;
        aux->prox = no;
    }
}

void cadastrar_ponto(Lista *list, int rotas)
{
    ElemC *cidade = (ElemC *)malloc(sizeof(ElemC));
    ElemR *no = (*list);
    for (int i = 0; i < rotas - 1; i++)
    {
        no = no->prox;
    }
    ElemC *aux;
    int escolha = 0;
    do
    {
        printf("\n1 - Cadastrar Ponto\n");
        printf("2 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            cidade = (ElemC *)malloc(sizeof(ElemC));
            printf("Qual o nome do ponto ?");
            setbuf(stdin, NULL);
            gets(cidade->nome);
            printf("Qual a descricao do ponto ?");
            setbuf(stdin, NULL);
            gets(cidade->descricao);
            cidade->prox = NULL;
            aux = *(no)->prox_cidade;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = cidade;
            cidade->ant = aux;
            break;
        case 2:
            break;
        }
    } while (escolha != 2);
    system("cls");
}

int excluir_rota(Lista *list)
{
    ElemR *ant, *no = *list;
    char rota[50];
    int x = 1;
    printf("Qual a rota que deseja exluir ?");
    setbuf(stdin, NULL);
    gets(rota);
    x = strcmp(no->nome_rota, rota);
    while (no != NULL && x != 0)
    {
        ant = no;
        no = no->prox;
        x = strcmp(no->nome_rota, rota);
    }

    if (no == NULL) //não encontrado
        return 0;

    if (no == *list) //remover o primeiro?
        *list = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

void imprime_lista(Lista *list)
{
    char rota[50];
    int escolha, x = 1;
    if (list == NULL)
        return;
    ElemR *no = *list;
    ElemC *cidade;
    while (no->prox != NULL)
    {
        printf("%s\n",no->nome_rota);
        no = no->prox;
    }
    no = *list;
    printf("Qual a rota deseja visitar ?");
    setbuf(stdin, NULL);
    gets(rota);
    x = strcmp(no->nome_rota, rota);
    while (no->prox != NULL && x != 0)
    {
        if (no->prox == NULL)
        {
            printf("Rota não encontrada");
            return;
        }
        no = no->prox;
        x = strcmp(no->nome_rota, rota);
    }
    cidade = *(no)->prox_cidade;
    do
    {
        printf("-------------------------------\n");
        printf("Rota: %s\n", no->nome_rota);
        printf("Voce esta em %s\n", cidade->nome);
        printf("%s\n", cidade->descricao);
        printf("-------------------------------\n");
        printf("\n1 - Ir para proxima cidade\n");
        printf("2 - Voltar a cidade anterior\n");
        printf("3 - Sair da Rota\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (cidade->prox != NULL)
            {
                cidade = cidade->prox;
            }
            break;
        case 2:
            if (cidade->ant != NULL)
            {
                cidade = cidade->ant;
            }
            break;
        case 3:
            break;
        }
    } while (escolha != 3);
}