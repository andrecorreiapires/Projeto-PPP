#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source_bar.h"

#define TAM_BUFFER 1000

int main()
{
    struct no_aluno *agenda = create_aluno();

    int num_alunos = 0, opcao; //Contador para o número de alunos

    ler_ficheiro(agenda);
                                 // criei o ficheiro "File_manager.c" para ler o ficheiro de texto e dar save quando terminar o programa

    do
    {
        opcao = menu();

        switch(opcao)
        {
            case 0:
                save_state();
                finale();
                break;
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

    return 0;
}

/*        while(fgets(linha, sizeof(linha), f_txt)){
            if(fscanf(linha, "%s|%d/%d/%d|%s|%d|%d|%d",  )==8){                             // nao entendi esta parte mas n vou mexer para se quiseres aproveita la para algo
            }
        }
*/