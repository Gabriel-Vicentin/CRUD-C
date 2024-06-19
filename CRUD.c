#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 5
#define MAX_NOME 5

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS]; // Array de produtos
int contador_produtos = 0; // Contador de produtos cadastrados

// Protótipos das funções
void menu();
void cadastrarProduto();
void listarProdutos();
void alterarProduto();
void apagarProduto();
void limparTela();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;

    do {
        limparTela();
        printf("\n==========================\n");
        printf("======Bem vindo(a) =======\n");
        printf("======Sessão Cadastro=====\n");

        printf("Selecione a opção desejada:\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Alterar Produto\n");
        printf("4 - Apagar Produto\n");
        printf("5 - Sair do Sistema\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                alterarProduto();
                break;
            case 4:
                apagarProduto();
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

void cadastrarProduto() {
    int resposta_cadastro = 1; // Inicializa como 1 para entrar no loop

    while (contador_produtos < MAX_PRODUTOS && resposta_cadastro == 1) {
        limparTela();
        printf("Cadastrar Produto:\n");
        printf("Nome do produto: ");
        scanf(" %s", produtos[contador_produtos].nome); // Captura o nome até encontrar uma quebra de linha
        printf("Preço do Produto: ");
        scanf("%f", &produtos[contador_produtos].preco);

        produtos[contador_produtos].codigo = contador_produtos + 1; // Novo código para o produto
        contador_produtos++;

        printf("O produto foi cadastrado com sucesso.\n\n");

        if (contador_produtos < MAX_PRODUTOS) {
            printf("Deseja cadastrar outro produto?\n");
            printf("1 - Sim 2 - Nao\n\n");
            scanf("%d", &resposta_cadastro);
        }
    }

    if (contador_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado. Não é possível cadastrar mais produtos.\n");
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
}

void listarProdutos() {
    limparTela();
    if (contador_produtos > 0) {
        printf("Lista de Produtos:\n");
        for (int i = 0; i < contador_produtos; i++) {
            printf("Código: %d | Nome: %s | Preço: %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
        }
    } else {
        printf("Nao ha produtos cadastrados.\n");
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
}

void alterarProduto() {
    limparTela();
    int codigo;
    printf("Digite o código do produto a ser alterado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Alterar Produto (Código: %d):\n", codigo);
            printf("Novo nome do produto: ");
            scanf(" %s", produtos[i].nome);
            printf("Novo preço do produto: ");
            scanf("%f", &produtos[i].preco);
            printf("Produto alterado com sucesso.\n");
            printf("Pressione Enter para voltar ao menu...");
            getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", codigo);
    printf("Pressione Enter para voltar ao menu...");
    getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
}

void apagarProduto() {
    limparTela();
    int codigo;
    printf("Digite o código do produto a ser apagado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador_produtos; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < contador_produtos - 1; j++) {
                produtos[j] = produtos[j + 1]; // Desloca os elementos para a esquerda
            }
            contador_produtos--;
            printf("Produto apagado com sucesso.\n");
            printf("Pressione Enter para voltar ao menu...");
            getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", codigo);
    printf("Pressione Enter para voltar ao menu...");
    getchar(); getchar(); // Espera uma entrada do usuário para prosseguir
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
