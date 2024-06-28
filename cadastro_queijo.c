#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_queijo.h"



Produto produtos[MAX_PRODUTOS]; // Array de produtos
int contador_produtos = 0; // Contador de produtos cadastrados

void menu() {
    int opcao;

    do {
        
        printf("\n==========================\n");
        printf("========  Bem vindo(a) =======\n");
        printf("======Sessão Cadastro de Queijo=====\n");

        printf("Selecione a opção desejada:\n");
        printf("1 - Cadastrar Queijo\n");
        printf("2 - Listar Queijos\n");
        printf("3 - Alterar Queijo\n");
        printf("4 - Apagar Queijo\n");
        printf("5 - Sair do Sistema\n");

        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                cadastrarQueijo();
                break;
            case 2:
                listarQueijos();
                break;
            case 3:
                alterarQueijo();
                break;
            case 4:
                apagarQueijo();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 5);
}

void cadastrarQueijo() {
    char resposta_cadastro = 's'; // Inicializa como 's' para entrar no loop

    while (contador_produtos < MAX_PRODUTOS && (resposta_cadastro == 's' || resposta_cadastro == 'S')) {
        
        printf("Cadastrar Queijo:\n");
        printf("Tipo de queijo: ");
        fgets(produtos[contador_produtos].nome, MAX_NOME, stdin);
        produtos[contador_produtos].nome[strcspn(produtos[contador_produtos].nome, "\n")] = '\0'; // Remove o caractere de nova linha
        printf("Preço: ");
        scanf("%f", &produtos[contador_produtos].preco);
        getchar(); // Limpa o buffer de entrada

        produtos[contador_produtos].codigo = contador_produtos + 1; // Novo código para o queijo

        printf("O queijo %s foi cadastrado com sucesso.\n\n", produtos[contador_produtos].nome);

        contador_produtos++;

        if (contador_produtos < MAX_PRODUTOS) {
            printf("Deseja cadastrar outro queijo? (s/n)\n");
            scanf(" %c", &resposta_cadastro);
            getchar(); // Limpa o buffer de entrada
        }
    }

    if (contador_produtos >= MAX_PRODUTOS) {
        printf("Limite alcançado. Não é possível cadastrar mais queijos.\n");
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void listarQueijos() {
    if (contador_produtos > 0) {
        printf("Lista De Queijos:\n");
        for (int i = 0; i < contador_produtos; i++) {
            printf("Código: %d | Nome: %s | Preço: %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
        }
    } else {
        printf("Não há queijos cadastrados.\n");
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void alterarQueijo() {

    if (contador_produtos == 0) {
        printf("Não há queijos cadastrados para alterar.\n");
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Espera uma entrada do usuário para prosseguir
        return;
    }

    int codigo;
    printf("Digite o código do queijo a ser alterado: ");
    scanf("%d", &codigo);
    getchar(); // Limpa o buffer de entrada

    for (int i = 0; i < contador_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Alterar Queijo (Código: %d):\n", codigo);

            char alterar_nome;
            printf("Deseja alterar o nome do queijo? (s/n): ");
            scanf(" %c", &alterar_nome);
            getchar(); // Limpa o buffer de entrada
            if (alterar_nome == 's' || alterar_nome == 'S') {
                printf("Novo nome do queijo: ");
                fgets(produtos[i].nome, MAX_NOME, stdin);
                produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; // Remove o caractere de nova linha
            }

            char alterar_preco;
            printf("Deseja alterar o preço do queijo? (s/n): ");
            scanf(" %c", &alterar_preco);
            getchar(); // Limpa o buffer de entrada
            if (alterar_preco == 's' || alterar_preco == 'S') {
                printf("Novo preço do queijo: ");
                scanf("%f", &produtos[i].preco);
                getchar(); // Limpa o buffer de entrada
            }

            printf("Queijo alterado com sucesso.\n");
            printf("Pressione Enter para voltar ao menu...");
            getchar(); // Espera uma entrada do usuário para prosseguir
            return;
        }
    }
    printf("Queijo com codigo %d nao encontrado.\n", codigo);
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void apagarQueijo() {

    if (contador_produtos == 0) {
        printf("Não possui queijos cadastrados para apagar.\n");
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Espera uma entrada do usuário para prosseguir
        return;
    }

    int codigo;
    printf("Digite o código do queijo a ser apagado: ");
    scanf("%d", &codigo);
    getchar(); // Limpa o buffer de entrada

    for (int i = 0; i < contador_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < contador_produtos - 1; j++) {
                produtos[j] = produtos[j + 1]; // Desloca os elementos para a esquerda
            }
            contador_produtos--;
            printf("Queijo apagado com sucesso.\n");
            printf("Pressione Enter para voltar ao menu...");
            getchar(); // Espera uma entrada do usuário para prosseguir
            return;
        }
    }
    printf("Queijo nao encontrado");
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
