#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "source_bar.h"

#define TAM_BUFFER 1000

int verificar_file(FILE *f)
{
    if(f == NULL) 
    {
        printf("N da para encontrar espaço");
        return 0;
    }
    else return 1;
}

int verificar_input(char input[], char buffer[])
{
    int i;

    if(strcmp(input, "inicio") == 0)
    {
        for(i = 0; i < '\0'; i++)
        {
            if(buffer[i] == '\n') return 1;
        }
    }
    else if(strcmp(input, "opcao") == 0)
    {
        if(strlen(buffer) >= 2) return 0;
        else if(buffer[0] < '0' || buffer[0] > '6') return 0;
        return 1;
    }
    else if(strcmp(input, "string") == 0)
    {
        for(i = 0; i < '\0'; i++)
        {
            if(!(buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= 'a' && buffer[i] <= 'z') || buffer[i] == ' ') return 0;
        }
        return 1;
    }
    else if(strcmp(input, "data") == 0)
    {
        return 1;
    }
    else if(strcmp(input, "ano") == 0)
    {
        return 1;
    }
    else if(strcmp(input, "saldo") == 0)
    {
        return 1;
    }
    else
    {
        printf("Não sei o que meteste no inicio mas nao tenho knowledge dessa string");
        return 0;
    }
}

void disclaimer(char buffer[])
{
    printf("\nDisclaimer: Tens o poder de com toques ultra mega magicos, gerir contas de alunos... Choose wisely your option\n");
    printf("Pressione Enter para continuar...\n");
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);

    verificar("inicio", buffer);
}

int menu()
{
    int opcao = 0;
    char buffer[TAM_BUFFER] = "\0";

    disclaimer(buffer);

    do
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n\n+------------------------------------------------------------------+\n");
        printf("|                           Bar Manager                            |\n");
        printf("+------------------------------------------------------------------+\n");
        printf("|  1 -> Inserir Aluno                                              |\n");
        printf("|  2 -> Eliminar Aluno                                             |\n");
        printf("|  3 -> Listar Alunos                                              |\n");
        printf("|  4 -> Inserir Despesa                                            |\n");
        printf("|  5 -> Carregar conta de um Aluno                                 |\n");
        printf("|  6 -> Eliminar Despesa de um Aluno                               |\n");
        printf("|  0 -> Sair deste magnifico programa...                           |\n");
        printf("|                                                                  |\n");
        printf("'-> R: ");
        fgets(buffer, sizeof(buffer), stdin);
    }while(verificar("opcao", buffer) != true);
    
    opcao = atoi(buffer);
    return opcao;
}