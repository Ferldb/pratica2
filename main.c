#include <stdio.h>
#include "RotaOnibus.c"
#include <string.h>

int main()
{
    printf("--- BEM VINDO A COMPANHIA INTERMUNICIPAL DO PARANA ---\n");
    Lista *list = cria_lista();
    int escolha = 0;
    do
    {
        printf("\n1 - Cadastrar Rota\n");
        printf("2 - Excluir Rota\n");
        printf("3 - Visitar Rota\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            cadastrar_rota(list);
            cadastrar_ponto(list);
            setbuf(stdin, NULL);
            break;
        case 2:
            break;
        case 3:
            break;
        }
    
    } while (escolha != 4);
    imprime_lista(list);
    return 0;
}
