#include <stdio.h>
#include <stdlib.h>
#include "cadastro_produto.h"
#include "cadastrocliente.h"
//#include "vendas.h"

int main() {
    int op, cont;
    do{
    printf("escolha uma opcao \n");
    printf("1 - cadastro usuario \n");
    printf("2 - Cadastro queijos \n");
    printf("3 - realizar pedidos \n");
        scanf("%i", &op);

        switch (op){

        case 1:
            menucad();
            break;

        case 2:
            menu();
            break;

        // case 3:
        //     pedido();
        //     break;

        default:
            printf("Opcao incorreta\n");
            break;
        }
        
        printf("Deseja utilizar o menu novamente?\n");
        printf("1 - Sim\n");
        printf("0 - Não\n");
            scanf("%i", &cont);
    }while (cont == 1);
    return 0;
}
