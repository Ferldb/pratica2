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
    strcpy(curitiba->descricao, "Descricao de Curitiba");
    curitiba->ant = NULL;
    *(no)->prox_cidade = curitiba;
    no->prox = NULL;
    if ((*list) == NULL)
    {
        no->prox = (*list);
        *list = no;
    }else{
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
    for (int i = 0; i < rotas-1; i++)
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

void imprime_lista(Lista *list)
{
    if (list == NULL)
        return;
    ElemR *no = *list;
    ElemC *cidade;
    while (no != NULL)
    {
        printf("-------------------------------\n");
        printf("Rota: %s\n", no->nome_rota);
        cidade = *(no)->prox_cidade;
        while (cidade != NULL)
        {
            printf("Cidade: %s\n", cidade->nome);
            printf("Descricao: %s\n", cidade->descricao);
            cidade = cidade->prox;
        }
        printf("-------------------------------\n");
        no = no->prox;
    }
}
