#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_queijo.h"

#define MAX_PEDIDOS 100 // Define o número máximo de pedidos que podem ser armazenados

typedef struct {
    int codigo_produto;
    int quantidade;
} ItemPedido;

typedef struct {
    ItemPedido itens[MAX_PRODUTOS];
    int num_itens;
    float valor_total;
    char forma_pagamento[20]; // Para armazenar "pix" ou "cartao"
    int parcelas; // Quantidade de parcelas, caso seja pagamento no cartão
} Pedido;

Pedido pedidos[MAX_PEDIDOS];
int num_pedidos = 0;

void listarProdutosvend() {
    if (contador_produtos > 0) {
        for (int i = 0; i < contador_produtos; i++) {
            printf("%d - %s\n", produtos[i].codigo, produtos[i].nome);
        }
    } else {
        printf("Não há produtos disponíveis para venda.\n");
    }
}

void pedido() {
    if (num_pedidos >= MAX_PEDIDOS) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    Pedido novo_pedido;
    novo_pedido.num_itens = 0;
    char rep_pedido = 's';

    while (novo_pedido.num_itens < MAX_PRODUTOS && (rep_pedido == 's' || rep_pedido == 'S')) {
        limparTela();
        printf("\n----------------------------\n");
        printf("------   Produtos    -------\n");
        printf("----------------------------\n");

        listarProdutosvend();

        if (contador_produtos == 0) {
            break;
        }

        printf("\nSelecione o código do produto para adicionar ao pedido: ");
        scanf("%d", &novo_pedido.itens[novo_pedido.num_itens].codigo_produto);
        getchar(); // Limpa o buffer de entrada

        // Verifica se o código do produto é válido
        int codigo_valido = 0;
        for (int i = 0; i < contador_produtos; i++) {
            if (produtos[i].codigo == novo_pedido.itens[novo_pedido.num_itens].codigo_produto) {
                codigo_valido = 1;
                break;
            }
        }

        if (codigo_valido) {
            printf("Digite a quantidade do produto: ");
            scanf("%d", &novo_pedido.itens[novo_pedido.num_itens].quantidade);
            getchar(); // Limpa o buffer de entrada

            novo_pedido.num_itens++;
            if (novo_pedido.num_itens < MAX_PRODUTOS) {
                printf("Deseja adicionar outro produto ao pedido? (s/n): ");
                scanf(" %c", &rep_pedido);
                getchar(); // Limpa o buffer de entrada
            }
        } else {
            printf("Código de produto inválido. Tente novamente.\n");
            printf("Pressione Enter para continuar...");
            getchar(); // Espera uma entrada do usuário para prosseguir
        }
    }

    // Adiciona o novo pedido à lista de pedidos
    pedidos[num_pedidos] = novo_pedido;
    num_pedidos++;

    printf("Pedido realizado com sucesso. Produtos no pedido:\n");
    for (int i = 0; i < novo_pedido.num_itens; i++) {
        for (int j = 0; j < contador_produtos; j++) {
            if (produtos[j].codigo == novo_pedido.itens[i].codigo_produto) {
                printf("%d - %s | Quantidade: %d\n", produtos[j].codigo, produtos[j].nome, novo_pedido.itens[i].quantidade);
                break;
            }
        }
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void listarPedidos() {
    limparTela();
    if (num_pedidos > 0) {
        printf("Lista de Pedidos:\n");
        for (int i = 0; i < num_pedidos; i++) {
            printf("Pedido %d:\n", i + 1);
            for (int j = 0; j < pedidos[i].num_itens; j++) {
                for (int k = 0; k < contador_produtos; k++) {
                    if (produtos[k].codigo == pedidos[i].itens[j].codigo_produto) {
                        printf("  %d - %s | Quantidade: %d\n", produtos[k].codigo, produtos[k].nome, pedidos[i].itens[j].quantidade);
                        break;
                    }
                }
            }
        }
    } else {
        printf("Não há pedidos realizados.\n");
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void finalizarCompra() {
    limparTela();

    if (num_pedidos == 0) {
        printf("Não há pedidos para finalizar.\n");
        printf("Pressione Enter para voltar ao menu...");
        getchar(); // Espera uma entrada do usuário para prosseguir
        return;
    }

    // Exibir todos os pedidos em andamento
    printf("Pedidos em andamento:\n");
    for (int i = 0; i < num_pedidos; i++) {
        printf("Pedido %d:\n", i + 1);
        for (int j = 0; j < pedidos[i].num_itens; j++) {
            for (int k = 0; k < contador_produtos; k++) {
                if (produtos[k].codigo == pedidos[i].itens[j].codigo_produto) {
                    printf("  %d - %s | Quantidade: %d\n", produtos[k].codigo, produtos[k].nome, pedidos[i].itens[j].quantidade);
                    break;
                }
            }
        }
    }

    // Calcular e exibir o valor total da compra
    float valor_total = 0;
    for (int i = 0; i < num_pedidos; i++) {
        for (int j = 0; j < pedidos[i].num_itens; j++) {
            for (int k = 0; k < contador_produtos; k++) {
                if (produtos[k].codigo == pedidos[i].itens[j].codigo_produto) {
                    valor_total += produtos[k].preco * pedidos[i].itens[j].quantidade;
                    break;
                }
            }
        }
    }
    printf("\nValor Total da Compra: R$ %.2f\n", valor_total);

    // Escolher a forma de pagamento
    printf("\nEscolha a forma de pagamento:\n");
    printf("1 - Pagar no Pix (à vista)\n");
    printf("2 - Pagar no Cartão (parcelado)\n");
    int opcao_pagamento;
    printf("Opção: ");
    scanf("%d", &opcao_pagamento);
    getchar(); // Limpar o buffer de entrada

    if (opcao_pagamento == 1) {
        strcpy(pedidos[num_pedidos - 1].forma_pagamento, "pix");
        printf("Pagamento realizado via Pix (à vista).\n");
    } else if (opcao_pagamento == 2) {
        strcpy(pedidos[num_pedidos - 1].forma_pagamento, "cartao");

        // Escolher a quantidade de parcelas (até 10 vezes)
        printf("Quantas vezes deseja parcelar (1 a 10 vezes): ");
        scanf("%d", &pedidos[num_pedidos - 1].parcelas);
        getchar(); // Limpar o buffer de entrada

        float valor_parcela = valor_total / pedidos[num_pedidos - 1].parcelas;
        printf("Pagamento realizado via Cartão em %d vezes de R$ %.2f.\n", pedidos[num_pedidos - 1].parcelas, valor_parcela);
    } else {
        printf("Opção de pagamento inválida.\n");
    }

    printf("Compra finalizada com sucesso.\n");
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Espera uma entrada do usuário para prosseguir
}

void menuCompras() {
    int opcao;
    do {
        limparTela();
        printf("Sistema de Vendas\n");
        printf("1 - Fazer Pedido\n");
        printf("2 - Ver Pedidos\n");
        printf("3 - Finalizar Compra\n");
        printf("4 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                pedido();
                break;
            case 2:
                listarPedidos();
                break;
            case 3:
                finalizarCompra();
                break;
            case 4:
                printf("Saindo do sistema de vendas...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);
}