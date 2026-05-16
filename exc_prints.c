#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "source_bar.h"

#define TAM_BUFFER 1000

void limpar_prompt()
{
    #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
}

int verificar_file(FILE *f)
{
    if(f == NULL) 
    {
        printf("N da para encontrar espaço");
        return 1;
    }
    else return 0;
}

int verificar_int_final(char buffer[], char final)
{
    if(strlen(buffer) != 1 || (buffer[0] < '0' || buffer[0] > final)) return 0;
    else return 1;
}

int verificar_data_existente(int dia, int mes, int ano)
{
    if (dia < 1) return 1; 
    
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia > 31) return 1;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30) return 1;
    }
    else if (mes == 2)
    {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            if (dia > 29) return 1;
        }
        else
        {
            if (dia > 28) return 1;
        }
    }

    return 0;
}

int verificar_input(char input[], char buffer[])
{
    int i, numero_ano, tam, barras, digitos_segmento, dia, mes, ano;

    buffer[strcspn(buffer, "\n")] = '\0';

    if(strcmp(input, "inicio") == 0)
    {
        return 1;
    }
    else if(strcmp(input, "opcao") == 0)
    {
        return verificar_int_final(buffer, '6');
    }
    else if(strcmp(input, "string") == 0)
    {
        for(i = 0; buffer[i] != '\0'; i++)
        {
            if(!((buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= 'a' && buffer[i] <= 'z') || buffer[i] == ' ')) return 0;
        }
        return 1;
    }
    else if(strcmp(input, "data") == 0)
    {
        tam = strlen(buffer);
        
        if (tam < 8 || tam > 10) return 0;

        barras = 0;
        digitos_segmento = 0;

        for (i = 0; buffer[i] != '\0'; i++) 
        {
            if (buffer[i] == '/') 
            {
                barras++;
                if (digitos_segmento < 1 || digitos_segmento > 2) return 0;
                digitos_segmento = 0;
            } 
            else if (buffer[i] >= '0' && buffer[i] <= '9') 
            {
                digitos_segmento++;
            } 
            else 
            {
                return 0;
            }
        }

        if (barras != 2 || digitos_segmento != 4) return 0;

        sscanf(buffer, "%d/%d/%d", &dia, &mes, &ano);

        if (ano < 1970 || ano > 2010) return 0;
        if (mes < 1 || mes > 12) return 0;
        if(verificar_data_existente(dia, mes, ano)) return 0;

        return 1;
    }
    else if(strcmp(input, "ano") == 0)
    {
        return verificar_int_final(buffer, '3');
    }
    else if(strcmp(input, "saldo") == 0)
    {
        int cont = 0;
        char temp_buffer[TAM_BUFFER];

        strcpy(temp_buffer, buffer);

        char *pch = strtok (temp_buffer," .");

        while (pch != NULL)
        {
            if (cont >= 2) return 0;

            for( i = 0; pch[i] != '\0'; i++)
            {
                if(pch[i] < '0' || pch[i] > '9') return 0;
            }

            pch = strtok (NULL, " .");
            cont++;
        }

        if (cont == 0) return 0;

        return 1;
    }
    else
    {
        printf("Nao sei o que meteste no inicio mas nao tenho knowledge dessa string");
        return 0;
    }
}

void disclaimer(char buffer[])
{
    limpar_prompt();
    
    printf("\n\n\n\n\n");
    printf("                       /\\     \n");
    printf("                      /  \\    \n");
    printf("                     / || \\   \n");
    printf("                    /  ||  \\  \n");
    printf("                   /   ||   \\ \n");
    printf("                  /    ||    \\\n");
    printf("                 /     ::     \\\n");
    printf("                /      **      \\\n");
    printf("               /________________\\\n\n");
    printf("\n\nDisclaimer: Tens o poder de com toques ultra mega magicos, gerir contas de alunos... Choose wisely your option\n");
    printf("\n\nPressione Enter para continuar...\n");

    fgets(buffer, TAM_BUFFER, stdin);

    verificar_input("inicio", buffer);
}

int menu()
{
    int opcao = 0;
    char buffer[TAM_BUFFER] = "\0";

    disclaimer(buffer);

    do
    {
        limpar_prompt();

        printf("\n\n\n+------------------------------------------------------------------+\n");
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
    }while(verificar_input("opcao", buffer) != 1);
    
    opcao = atoi(buffer);
    return opcao;
}

void finale()
{
    char buffer[TAM_BUFFER] = "\0";

    limpar_prompt();
    
    printf("\n\n\n\n\nEspero que tenha gostado do nosso humilde programa ^^\n");
    printf("\nNao pensamos melhorar a cadeira (outra vez no meu caso) mas se o fizermos, vai ter Bar Manager 2 com trailer\n");
    printf("\n\nPressione Enter outra vez porque 7 linhas de codigo a mais nao faz mal a ninguem...");

    fgets(buffer, TAM_BUFFER, stdin);
    verificar_input("inicio", buffer);

    limpar_prompt();

    printf("\n\n\n\n\n\nFeito por Andre Pires e...\n");
    printf("\nO Majestoso e Incrivel Daniel Mendes\n\n");
    printf("\nEnter mais uma vez...");

    fgets(buffer, TAM_BUFFER, stdin);
    verificar_input("inicio", buffer);

    limpar_prompt();

    printf("\n\n\n\n\nEsqueci-me de dizer que o Daniel e mesmo muito fixe (Sou o Andre a escrever)\n");
    printf("\n\nJa sabe a tecla...");

    fgets(buffer, TAM_BUFFER, stdin);
    verificar_input("inicio", buffer);

    limpar_prompt();

    printf("\n\n\n\n\n====================================================================\n");
    printf("     MUITO OBRIGADO POR USAR O BAR MANAGER (By Andre & Daniel)     \n");
    printf("====================================================================\n\n");

    printf("         ******       ******     \n");
    printf("       **********   **********   \n");
    printf("     ************* ************* \n");
    printf("     *************************** \n");
    printf("      *************************  \n");
    printf("        *********************    \n");
    printf("          *****************      \n");
    printf("            *************        \n");
    printf("              *********          \n");
    printf("                *****            \n");
    printf("                  *              \n\n");

    printf("   Daniel & Andre aprovam este trabalho hehe \n\n");
    
    printf("          /\\_/\\  \n");
    printf("         ( o.o ) \n");
    printf("          > ^ <  \n");
    printf("         /     \\ \n");
    printf("        |       | \n");
    printf("       / |  |  | \\\n");
    printf("       | |  |  | |\n");
    printf("       (______               (Enter para fechar de vez desta vez :p)\n");

    fgets(buffer, TAM_BUFFER, stdin);
    verificar_input("inicio", buffer);
}