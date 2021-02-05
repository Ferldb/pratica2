typedef struct RotaOnibus* Lista;
typedef struct descritor ListaCidade;


Lista* cria_lista();
void cadastrar_rota(Lista* list);
void cadastrar_ponto(Lista* list, int rotas);
int exluir_rota(Lista* list);
void imprime_lista(Lista* list);
