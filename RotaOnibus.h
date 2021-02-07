typedef struct RotaOnibus* Lista;

typedef struct descritor ListaCidade;

//fun��o que cria o in�cio da lista de rotas de �nibus
Lista *cria_lista();

//fun��o que cria o in�cio da lista de cidades (n� descritor)
ListaCidade *cria_lista2();

//fun��o que cadastra uma rota na lista de rotas de �nibus
void cadastra_rota(Lista* list);

//fun��o que cadastra uma cidade na lista de cidades
void cadastra_ponto(Lista* list, int rotas);

//fun��o que exclui uma rota da lista de rotas de �nibus
int exlui_rota(Lista* list);

//fun��o que imprime uma rota de �nibus com suas cidades
void imprime_lista(Lista* list);

//fun��o que libera a lista de rotas de �nibus
void libera_lista(Lista* list);

//fun��o que libera a lista de cidades da rota de �nibus
void libera_lista2(ListaCidade* cidade);
