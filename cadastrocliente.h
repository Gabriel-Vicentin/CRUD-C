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
        printf("   MENU   \n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Listar  clientes\n");
            scanf("%i", &opc);

        switch (opc){
        case 1:
            cadastrouser();
        break;

        case 2:
            listarcliente();
        break;

        default:
            printf("Opcao invalida, tente novamente\n");
        break;
        }

    }

void cadastrouser(){
    int repcad = 0;
    printf("\n");
    do{
        printf("Digite o nome do usuario a ser cadastrado\n");
        scanf("%s", &usuario[user_count].nome);
        usuario[user_count].nome[strcspn(usuario[user_count].nome, "\n")] = '\0'; // Remove o newline do final da string
        usuario[user_count].id = user_count + 1; // Atribuir um ID simples
        printf("Usuario cadastrado com sucesso: %s \n", usuario[user_count].nome);
            if (user_count < 5){
                printf("Deseja cadastrar outro usuario?\n");
                printf("1 - sim\n");
                printf("0 - nao\n");
                    scanf("%i", &repcad);
        
        }else{
            printf("Limite de usuarios cadastrados atingido.\n");
        }
        user_count++;
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