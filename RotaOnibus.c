#include "RotaOnibus.h"
#include <stdio.h>
#include <stdlib.h>

struct RotaOnibus
{
    char nome_rota[50];
    struct cidade cidade_info;
    struct RotaOnibus *prox;
};
typedef struct RotaOnibus Elemento;

Lista* cria_lista(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
    if (list != NULL)
    {
        *list = NULL;
    }
    return list; 
}

void cadastrar_rota(Lista *list){
    Elemento *no_final;
    Elemento *no_inicial;
    no_inicial->cidade_info.descricao = "Cidade que concentra grande numero de capivaras";

    no_final = (Elemento*) malloc(sizeof(Elemento));
    char nome[30];
    printf("Insira o ponto final da rota: ");
    scanf("%s",no_final->nome_rota);
    *list = no_final;

}

void cadastrar_ponto(){

}
