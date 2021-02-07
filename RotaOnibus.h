typedef struct RotaOnibus* Lista;

typedef struct descritor ListaCidade;

//função que cria o início da lista de rotas de ônibus
Lista *cria_lista();

//função que cria o início da lista de cidades (nó descritor)
ListaCidade *cria_lista2();

//função que cadastra uma rota na lista de rotas de ônibus
void cadastra_rota(Lista* list);

//função que cadastra uma cidade na lista de cidades
void cadastra_ponto(Lista* list, int rotas);

//função que exclui uma rota da lista de rotas de ônibus
int exlui_rota(Lista* list);

//função que imprime uma rota de ônibus com suas cidades
void imprime_lista(Lista* list);

//função que libera a lista de rotas de ônibus
void libera_lista(Lista* list);

//função que libera a lista de cidades da rota de ônibus
void libera_lista2(ListaCidade* cidade);
