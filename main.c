#include <stdio.h>
#include <string.h>
#include "RotaOnibus.c"

int main() {

    Lista *list = cria_lista(); //ponteiro para ponteiro que recebe o in�cio da lista de rotas de �nibus

    int escolha = 0, rotas = 0, x = 0;

    do {
        system("cls");
        printf("\n--- BEM VINDO A COMPANHIA INTERMUNICIPAL DO PARANA ---\n");
        printf("\n1. Cadastrar Rota");
        printf("\n2. Excluir Rota");
        printf("\n3. Visitar Rota");
        printf("\n4. Sair");
        printf("\n--> ");
        scanf("%d", &escolha);

        switch (escolha) {

            case 1:
                cadastra_rota(list);
                rotas++;
                cadastra_ponto(list, rotas);
                setbuf(stdin, NULL);
                break;

            case 2:
                x = exclui_rota(list);
                if (x == 1)
                {
                    rotas --;
                }
                
                break;

            case 3:
                imprime_lista(list);
                break;

            case 4:
                libera_lista(list);
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause;");

            system("cls");
        }
    } while (escolha != 4);

    return 0;
}
