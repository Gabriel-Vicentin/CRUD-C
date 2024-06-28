#include <stdio.h>
#include <stdlib.h>
#include "cadastro_queijo.c"
#include "cadastrocliente.h"
#include "vendas.h"

int main() {
    int op, cont;
    do{
    printf("escolha uma opcao \n");
    printf("1 - cadastro usuario \n");
    printf("2 - Cadastro queijos \n");
    printf("3 - realizar compra \n");
        scanf("%i", &op);

        switch (op){

        case 1:
            menucad();
            break;

        case 2:
            menu();
            break;
        
        case 3:
            menuCompras();
        break;

        default:
            printf("Opcao incorreta\n");
            break;
        }
        printf("|------------------------------------|\n");
        printf("|               MENU                 |\n");
        printf("| Deseja utilizar o menu novamente?  |\n");
        printf("| 1 - Sim                            |\n");
        printf("| 0 - Não                            |\n");
        printf("|------------------------------------|\n");
        printf("Escolha: ");
            scanf("%i", &cont);
    }while (cont == 1);
    return 0;
}
