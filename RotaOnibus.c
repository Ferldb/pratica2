#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "RotaOnibus.h"

/* STRUCTS */

//estrutura dos nodos da lista encadeada simples que armazenará rotas de ônibus
typedef struct RotaOnibus
{
    char nome_rota[50];
    ListaCidade *prox_cidade;
    struct RotaOnibus *prox;
} ElemR;

//estrutura dos nodos da lista duplamente encadeada que armazenará as cidades de uma rota de ônibus
typedef struct cidade
{
    char nome[30];
    char descricao[200];
    struct cidade *ant;
    struct cidade *prox;
} ElemC;

//nó descritor que será o início da lista duplamente encadeada de cidades
struct descritor
{
    struct cidade *inicio;
    struct cidade *final;
    int qtd;
};

/* FUNÇÕES */

//função que cria o início da lista de rotas de ônibus
Lista *cria_lista(){
    Lista *list = (Lista *)malloc(sizeof(Lista));

    if (list != NULL){
        *list = NULL;
    }
    return list;
}

//função que cria o início da lista de cidades (nó descritor)
ListaCidade *cria_lista2(){
    ListaCidade *list = (ListaCidade *)malloc(sizeof(ListaCidade));

    if (list != NULL){
        list->inicio = NULL;
        list->final = NULL;
        list->qtd = 0;
    }
    return list;
}

//função que cadastra uma rota na lista de rotas de ônibus
void cadastra_rota(Lista *list){
    system("cls");

    //aloca espaço para uma nova rota
    ElemR *no = (ElemR *)malloc(sizeof(ElemR));
    //aloca espaço para o primeiro elemento da lista de cidades da nova rota que SEMPRE será curitiba
    ElemC *curitiba = (ElemC *)malloc(sizeof(ElemC));

    //cria o início da lista de cidades da nova rota
    no->prox_cidade = cria_lista2();

    //define o nome da nova rota
    printf("Qual o nome da rota? ");
    setbuf(stdin, NULL);
    gets(no->nome_rota);
    //define as informações do primeiro elemento da lista de cidades da nova rota
    strcpy(curitiba->nome, "Curitiba");
    strcpy(curitiba->descricao, "Conhecida por ser a capital ecologica do Brasil");
    curitiba->ant = NULL;
    curitiba->prox = NULL;
    //define as informações do início da lista de cidades da nova rota (nó descritor)
    no->prox_cidade->inicio = curitiba;
    no->prox_cidade->final = curitiba;
    no->prox = NULL;

    //verifica se a lista de rotas de ônibus está vazia: se estiver, insere a nova rota no início
    if ((*list) == NULL){
        no->prox = (*list);
        *list = no;
    }
    //se não estiver vazia, percorre a lista de rotas para inserir a nova rota no final dela
    else{
        ElemR *aux;                     //define rota auxiliar para ajudar
        aux = *list;                    //rota auxiliar recebe o início
        while (aux->prox != NULL){      //percorre a lista até achar o final
            aux = aux->prox;            //enquanto não chega ao final, a rota auxiliar recebe a próxima rota da lista
        }
        no->prox_cidade->inicio = curitiba;
        aux->prox = no;                 //quando chega ao final, o campo prox da rota auxiliar recebe a nova rota
    }
}

//função que cadastra uma cidade na lista de cidades
void cadastra_ponto(Lista *list, int rotas){

    //aloca espaço para a nova cidade da lista de cidades
    ElemC *cidade = (ElemC *)malloc(sizeof(ElemC));

    ElemR *no = (*list);

    for (int i = 0; i < rotas - 1; i++){
        no = no->prox;
    }
    ElemC *aux;
    int escolha = 0;
    do{
        printf("\n1. Cadastrar ponto (paradas)");
        printf("\n2. Concluir cadastro de rota (ao chegar ao destino da rota)");
        printf("\n--> ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                cidade = (ElemC *)malloc(sizeof(ElemC));
                //define as informações da nova cidade
                printf("\nQual o nome do ponto? ");
                setbuf(stdin, NULL);
                gets(cidade->nome);
                printf("\nQual a descricao do ponto? ");
                setbuf(stdin, NULL);
                gets(cidade->descricao);
                cidade->prox = NULL;
                aux = no->prox_cidade->final;
                aux->prox = cidade;
                no->prox_cidade->final = cidade;
                cidade->ant = aux;
                system("cls");
                break;

            case 2:
                break;
        }
    } while (escolha != 2);
    system("cls");
}

//função que exclui uma rota da lista de rotas de ônibus
int exclui_rota(Lista *list){

    int x = 1;
    char rota[50];

    //verifica se a lista é válida
    if(list == NULL)
        return 0;

    //define rotas auxiliares que recebem o conteúdo da lista de rotas
    ElemR *ant, *no = *list;

    //verifica se a lista está vazia
    if (no == NULL){
        printf("\n*ERRO! Nao existem rotas cadastradas...\n");
        system("pause;");
        return 0;
    }

    //imprime lista de rotas de ônibus
    printf("\n- - - - Rotas - - - -\n");
    while (no != NULL){
        printf("- %s\n", no->nome_rota);
        no = no->prox;
    }

    no = *list;
    printf("\nQual rota deseja exluir? ");
    setbuf(stdin, NULL);
    gets(rota);
    x = strcmp(no->nome_rota, rota);
    while (no != NULL && x != 0){
        ant = no;
        x = strcmp(no->nome_rota, rota);
        if (x != 0){
            no = no->prox;
        }
    }
    //rota não encontrada
    if (no == NULL){
        printf("\n*ERRO! Rota nao encontrada...\n");
        system("pause;");
        return 0;
    }
    if (no == *list) //remover o primeiro?
        *list = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    printf("\n*Rota excluida com sucesso!\n");
    system("pause;");
    return 1;
}

//função que imprime uma rota de ônibus com suas cidades
void imprime_lista(Lista *list){

    int escolha, x = 1;
    char rota[50];

    //define rotas auxiliar que recebe o conteúdo da lista de rotas
    ElemR *no = *list;
    //define cidade auxiliar
    ElemC *cidade;

    //verifica se a lista é válida
    if(list == NULL)
        return;

    //verifica se a lista está vazia
    if (no == NULL){
        printf("\n*ERRO! Nao existem rotas cadastradas...\n");
        system("pause;");
        return;
    }

    //imprime lista de rotas de ônibus
    printf("\n- - - - Rotas - - - -\n");
    while (no != NULL){
        printf("- %s\n", no->nome_rota);
        no = no->prox;
    }
    //rota auxiliar retorna a receber o início da lista
    no = *list;

    printf("\nQual a rota deseja visitar? ");
    setbuf(stdin, NULL);
    gets(rota);

    //percorre a lista de rotas de ônibus até encontrar o nome solicitado
    while (no != NULL && x != 0){
        x = strcmp(no->nome_rota, rota);
        if (x != 0){
            no = no->prox;
        }
    }
    //rota não encontrada
    if (no == NULL){
        printf("\n*ERRO! Rota nao encontrada...\n");
        system("pause;");
        return;
    }
    cidade = no->prox_cidade->inicio;
    //impressão da primeira cidade da lista de cidades da rota escolhida
    do{
        system("cls");
        printf("-------------------------------\n");
        printf("Rota: %s\n", no->nome_rota);
        printf("Voce esta em %s!\n", cidade->nome);
        printf("%s\n", cidade->descricao);
        printf("-------------------------------\n");
        //se não for a última cidade da lista de cidades da rota
        if (cidade->prox != NULL){
            printf("\n1. Avancar para a proxima cidade");
        }
        //se não for a primeira cidade da lista de cidades da rota
        if (cidade->ant != NULL){
             printf("\n2. Voltar para a cidade anterior");
        }
        printf("\n3. Sair da rota\n");
        printf("\n--> ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                if (cidade->prox != NULL){
                    cidade = cidade->prox;
                }
                break;
            case 2:
                if (cidade->ant != NULL){
                    cidade = cidade->ant;
                }
                break;
            case 3:
                break;
        }
    } while (escolha != 3);
}

//função que libera a lista de rotas de ônibus
void libera_lista(Lista* list){
    if(list != NULL){
        ElemR* no;
        while((*list) != NULL){
            no = *list;
            //função que libera a lista de cidades da rota de ônibus
            libera_lista2(no->prox_cidade);
            *list = (*list)->prox;
            free(no);
        }
        free(list);
    }
}

//função que libera a lista de cidades da rota de ônibus
void libera_lista2(ListaCidade* cidade){
    //lógica aqui pra liberar a lista de cidades da rota que está sendo liberada!!!
    ElemC* c;
    while (c != cidade->final)
    {
        c = cidade->inicio;
        cidade->inicio = c->prox;
        free(c);
    }
    free(cidade);
}
