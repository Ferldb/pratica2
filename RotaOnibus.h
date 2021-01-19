struct cidade
{
    char nome[30];
    char descricao[200];
    struct cidade *ant;
    struct cidade *prox;
};

typedef struct RotaOnibus* Lista;

Lista* cria_lista();