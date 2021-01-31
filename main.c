#include <stdio.h>
#include "RotaOnibus.c"
#include <string.h>

int main()
{
    Lista *list = cria_lista();
    int escolha = 0;
    int rotas = 0;
    int x = 0;
    do
    {
        printf("--- BEM VINDO A COMPANHIA INTERMUNICIPAL DO PARANA ---\n");
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
            rotas++;
            cadastrar_ponto(list, rotas);
            setbuf(stdin, NULL);
            break;
        case 2:
            x = excluir_rota(list);
            if (x == 0)
            {
                printf("ERRO AO EXCLUIR ROTA");
            }
            else
                printf("EXCLUIDO COM SUCESSO");
            break;
        case 3:
            imprime_lista(list);
            break;
        case 4:
            break;
        system("cls");
        }
    } while (escolha != 4);

    return 0;
}
