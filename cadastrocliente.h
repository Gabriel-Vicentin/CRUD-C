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

int inicio(){
    menucad();
return 0;
}

    void menucad(){
        int opc;
        do{
            printf("   MENU   \n");
            printf("1 - Cadastrar usuario\n");
            printf("2 - Listar usuarios\n");
            printf("3 - Atualizar cliente");
            printf("4 - Sair\n");
            printf("Escolha uma opcao: ");
                scanf("%d", &opc);
                getchar();

            switch (opc){
            case 1:
                cadastrouser();
            break;

            case 2:
                listarcliente();
            break;
            
            case 4:
                printf("Saindo...\n");
            break;

            default:
                printf("Opcao invalida, tente novamente\n");
            break;
            }

        }while (opc != 0);
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
        printf("%i | %s", usuario[i].id, usuario[i].nome);
        printf("\n");
    }
    
}