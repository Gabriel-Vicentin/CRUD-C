#include "vinho.h"
#include <stdio.h>
#include <string.h>


void cadastrarVinho(Vinho *vinho, int *nextId, const char *nome, const char *tipo, float preco) {
    vinho->id = *nextId;
    strcpy(vinho->nome, nome);
    strcpy(vinho->tipo, tipo);
    vinho->preco = preco;
    vinho->ativo = 1;
    (*nextId)++;
}

void atualizarVinho(Vinho *vinho, const char *nome, const char *tipo, float preco) {
    strcpy(vinho->nome, nome);
    strcpy(vinho->tipo, tipo);
    vinho->preco = preco;
}

void listarVinhos(const Vinho *vinhos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (vinhos[i].ativo) {
            printf("ID: %d | Nome: %s | Tipo: %s | Preço: %.2f\n", vinhos[i].id, vinhos[i].nome, vinhos[i].tipo, vinhos[i].preco);
        }
    }
}

void excluirVinho(Vinho *vinhos, int id, int tamanho) {
    if (id >= 0 && id < tamanho && vinhos[id].ativo) {
        vinhos[id].ativo = 0;
        printf("Vinho ID %d excluído com sucesso.\n", id);
    } else {
        printf("ID inválido ou vinho não encontrado!\n");
    }
}
