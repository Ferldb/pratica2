typedef struct RotaOnibus* Lista;
typedef struct cidade* ListaCidade;

Lista* cria_lista();
void cadastrar_rota(Lista* list);
void cadastrar_ponto(Lista* list);