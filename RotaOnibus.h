
struct cidade
{
    char nome[30];
    char descricao[200];
    struct cidade *ant;
    struct cidade *prox;
};

typedef struct RotaOnibus* Lista;
typedef struct Cidade* ListaCidade;

Lista* cria_lista();
void cadastrar_rota(Lista* list);
