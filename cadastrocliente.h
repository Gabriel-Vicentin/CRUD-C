#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct user { 
    char nome[70];
    int id;
} usuario[5];

int user_count = 0;

void menucad();
void cadastrouser();
void listarcliente();
void atualizaruser();

int inicio(){
    menucad();
return 0;
}

    void menucad(){
        int opc;
        do{
            printf("|---------------------------|\n");
            printf("|           MENU            |\n");
            printf("| 1 - Cadastrar usuario     |\n");
            printf("| 2 - Listar usuarios       |\n");
            printf("| 3 - Atualizar usuario     |\n");
            printf("| 4 - Sair                  |\n");               
            printf("|---------------------------|\n");
            printf("| Escolha uma opcao:  ");
                scanf("%d", &opc);
                getchar();

            switch (opc){
            case 1:
                cadastrouser();
            break;

            case 2:
                listarcliente();
            break;

            case 3:
                atualizaruser();
            break;

            case 4:
                printf("Saindo...\n");
            break;

            default:
                printf("Opcao invalida, tente novamente\n");
            break;
            }

        }while (opc != 4);
    }

void cadastrouser(){
    int repcad = 0;
    do {
        if (user_count >= 5) {
            printf("Limite de usuarios cadastrados atingido.\n");
            break;
        }

        printf("Digite o nome do usuario a ser cadastrado\n");
        fgets(usuario[user_count].nome, sizeof(usuario[user_count].nome), stdin);
        usuario[user_count].nome[strcspn(usuario[user_count].nome, "\n")] = '\0';

        usuario[user_count].id = user_count + 1; 
        printf("Usuario cadastrado com sucesso: %s \n", usuario[user_count].nome);
        user_count++;

            if (user_count < 5){
                printf("Deseja cadastrar outro usuario?\n");
                printf("1 - sim\n");
                printf("0 - nao\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &repcad);
                getchar();  
        }else{
            printf("Limite de usuarios cadastrados atingido.\n");
        }
    }while (user_count < 5 && repcad == 1);
}

void listarcliente(){
    printf("\n");
    int i;

    for (i = 0; i < user_count; i++)
    {
        printf("ID: %i | Nome:  %s", usuario[i].id, usuario[i].nome);
        printf("\n");
    }
    printf("\n");
    printf("Aperte enter para retornar ao menu");
    getchar();
    
}

void atualizaruser(){

    if (user_count == 0){
        printf("Nao ha usuario para atualizar");
        getchar();
        return;
    }

    int cod, atualizar_usuario, i;
    printf("Digite o código do usuario a ser atualizado: ");
    scanf("%i", &cod);
    getchar(); 

    for (i = 0; i < user_count; i++) {
        if (usuario[i].id == cod) {
            printf("Atualziar usuario (Código: %d):\n", cod);

            printf("Deseja atualizar este usuario?: ");
            printf("\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
                scanf(" %i", &atualizar_usuario);
                getchar();
            

            if (atualizar_usuario== 1) {
                printf("Novo nome de usuario: ");
                fgets(usuario[i].nome, 70, stdin);
                usuario[i].nome[strcspn(usuario[i].nome, "\n")] = '\0'; 
            }

            printf("usuario atualizado com sucesso.\n");
            printf("Pressione enter para voltar ao menu...");
            getchar();
            return;
        }
    }
    printf("Usuario nao encontrado.\n");
    printf("Pressione enter para voltar ao menu...");
    getchar();
}