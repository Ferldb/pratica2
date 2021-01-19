#include <stdio.h>
#include "RotaOnibus.c"

void main()
{
    printf("--- BEM VINDO A COMPANHIA INTERMUNICIPAL DO PARANA ---\n\n");
    Lista *list = cria_lista();
    int escolha = 0;
    do
    {
    	
    printf("1 - Cadastrar Rota\n");
    printf("2 - Excluir Rota\n");
    printf("3 - Visitar Rota\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
    scanf("%d",&escolha);
    switch (escolha)
    {
    case 1:
        cadastrar_rota(list);
        break;
    
    default:
        break;
    }
    } while (escolha != 4 );
}
