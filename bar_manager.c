#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source_bar.h"

#define TAM_BUFFER 1000
#define LINHA 100

int main()
{
    struct no_aluno *agenda = create_aluno();
    struct no_aluno *novo;
    int num_alunos = 0, opcao; //Contador para o número de alunos

    FILE *f_txt = fopen("Dados.txt", "r");
    if(verificar_file(f_txt) == true) exit(1);

    while(num_alunos<LINHA && fscanf(f_txt, "%s|%d/%d/%d|%s|%d|%d|%d", 
        novo->nome, novo->data_nascimento->dia, novo->data_nascimento->mes, novo->data_nascimento->ano,
        novo->curso, novo->ano, novo->numero, novo->saldo)!=EOF){
        insert_aluno(agenda, novo);
        num_alunos++;
    }

    do
    {
        opcao = menu();

        switch(opcao)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                break;
        }

    } while (opcao);

    FILE *f_txt = fopen("Dados.txt", "r");
    if(verificar_file(f_txt) == true) exit(1);

    return 0;
}

/*        while(fgets(linha, sizeof(linha), f_txt)){
            if(fscanf(linha, "%s|%d/%d/%d|%s|%d|%d|%d",  )==8){
            }
        }
*/