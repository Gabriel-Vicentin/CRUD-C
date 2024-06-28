#include <stdio.h>
#include <stdlib.h>
#include "cadastrocliente.h"
#include "vendas.h"
#include "vinho.h"

int nextVinhoId = 0;

void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void gerenciarVinhos(Vinho *vinhos) {
    limparTela();
    int opcao, id;
    char nome[50], tipo[30];
    float preco;

    while (1) {
        printf("\n=== Gerenciar Vinhos ===\n");
        printf("1. Cadastrar Vinho\n");
        printf("2. Atualizar Vinho\n");
        printf("3. Listar Vinhos\n");
        printf("4. Excluir Vinho\n");
        printf("5. Voltar ao menu principal\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        clearStdin();

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Tipo: ");
                fgets(tipo, sizeof(tipo), stdin);
                tipo[strcspn(tipo, "\n")] = '\0';
                printf("Preço: ");
                scanf("%f", &preco);
                clearStdin();
                cadastrarVinho(&vinhos[nextVinhoId], &nextVinhoId, nome, tipo, preco);
                break;

            case 2:
                printf("ID: ");
                scanf("%d", &id);
                clearStdin();
                if (id >= 0 && id < nextVinhoId && vinhos[id].ativo) {
                    printf("Novo nome: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = '\0';
                    printf("Novo tipo: ");
                    fgets(tipo, sizeof(tipo), stdin);
                    tipo[strcspn(tipo, "\n")] = '\0';
                    printf("Novo preço: ");
                    scanf("%f", &preco);
                    clearStdin();
                    atualizarVinho(&vinhos[id], nome, tipo, preco);
                } else {
                    printf("ID inválido ou vinho não encontrado!\n");
                }
                break;

            case 3:
                printf("=== Lista de Vinhos ===\n");
                listarVinhos(vinhos, nextVinhoId);
                break;

            case 4:
                printf("ID: ");
                scanf("%d", &id);
                clearStdin();
                excluirVinho(vinhos, id, nextVinhoId);
                break;

            case 5:
                return;

            default:
                printf("Opção inválida!\n");
        }
    }
}

int main() {
    limparTela();
    Vinho vinhos[5];
    int op, cont;
    
    do{
    printf("Escolha uma Opcao \n\n");
    printf("\t1 - Cadastro de Usuario \n");
    printf("\t2 - Gerenciar Sessao de Vinhos\n");
    printf("\t3 - Gerenciar Sessao de Queijos \n");
    printf("\t4 - Realizar uma Compra \n");
        scanf("%i", &op);

        switch (op){

        case 1:
            menucad();
            break;

        case 2:
            gerenciarVinhos(vinhos);
            break;

        case 3:
            menu();
            break;
        
        case 4:
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
        limparTela();
    }while (cont == 1);
    return 0;
}
