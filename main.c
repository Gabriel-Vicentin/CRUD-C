#include <stdio.h>
#include <stdlib.h>
#include "cadastro_produto.h"
#include "cadastrocliente.h"

int main() {
    int op, cont;
    do{
    printf("escolha uma opcao \n");
    printf("1 - cadastro cliente \n");
    printf("2 - Cadastro produto \n");
        scanf("%i", &op);

        switch (op){

        case 1:
            menucad();
            break;

        case 2:
            menu();
            break;

        default:
            printf("Opcao incorreta\n");
            break;
        }

        
        printf("Deseja utilizar o menu novamente?\n");
        printf("1 - Continuar\n");
        printf("0 - Parar\n");
            scanf("%i", &cont);
    }while (cont == 1);
    return 0;
}
