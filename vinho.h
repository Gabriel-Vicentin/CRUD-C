#ifndef VINHO_H
#define VINHO_H

typedef struct {
    int id;
    char nome[50];
    char tipo[30];
    float preco;
    int ativo;
} Vinho;

void cadastrarVinho(Vinho *vinho, int *nextId, const char *nome, const char *tipo, float preco);
void atualizarVinho(Vinho *vinho, const char *nome, const char *tipo, float preco);
void listarVinhos(const Vinho *vinhos, int tamanho);
void excluirVinho(Vinho *vinhos, int id, int tamanho);

#endif
