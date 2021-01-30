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

ListaCidade *cria_lista2(){
	ListaCidade *list = (ListaCidade *)malloc(sizeof(ListaCidade));
	if (list != NULL)
    {
        *list = NULL;
    }
    return list;
}

void cadastrar_rota(Lista* list)
{
    ElemR* no = (ElemR*) malloc(sizeof(ElemR));
    ElemC* cidade = (ElemC*) malloc(sizeof(ElemC));
    no->prox_cidade = cria_lista2();
    printf("Qual o nome da rota ?");
    setbuf(stdin, NULL);
    gets(no->nome_rota);
    strcpy(cidade->nome,"Curitiba");
    strcpy(cidade->descricao,"Descricao de Curitiba");
    cidade->prox = (*no->prox_cidade);
    cidade->ant = NULL;
    *no->prox_cidade = cidade;
    *list = no;
}

void imprime_lista(Lista *list){
	ElemC *cidade = *list->prox_cidade;
    if (list == NULL)
        return;
    ElemR* no = *list;
    while (no != NULL)
    {
        printf("-------------------------------\n");
        printf("Rota: %s\n", no->nome_rota);
        while (cidade != NULL)
        {
          	
        }
        
    }
    no = no->prox;
}
