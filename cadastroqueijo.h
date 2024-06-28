#ifndef CADASTRO_QUEIJO_H
#define CADASTRO_QUEIJO_H

#define MAX_PRODUTOS 5
#define MAX_NOME 50

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    float preco;
} Produto;

extern Produto produtos[MAX_PRODUTOS]; // Array de produtos
extern int contador_produtos; // Contador de produtos cadastrados

void menu();
void cadastrarQueijo();
void listarQueijos();
void alterarQueijo();
void apagarQueijo();
void limparTela();

#endif // CADASTRO_QUEIJO_H
