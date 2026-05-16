#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "source_bar.h"

#define TAM_BUFFER 1000

// vou explicar esta parte de ler o coiso do ficheiro à medida q passas pelos comentarios

void ler_ficheiro(struct no_aluno *list)
{
    FILE *f_txt = fopen("Dados.txt", "r");
    if(verificar_file(f_txt) == true) exit(1);            //le o ficheiro ne :p

    char linha[TAM_BUFFER];
    struct no_aluno *aluno_atual = NULL;
    int num_barras = 0, i;

    while (fgets(linha, sizeof(linha), f_txt) != NULL)           // tive de meter assim porque pelo formato dantes para o fim do ficheiro dava merda
    {
        linha[strcspn(linha, "\n")] = '\0';

        num_barras = 0;

        for (i = 0; linha[i] != '\0'; i++) 
        {
            if (linha[i] == '|') num_barras++;              //em vez de ler o formato inteiro, podemos ver pela quantidade de barras ou pelo tamanho ja que a descricao nao seria mt grande mas para ser mais facil, fui pelas barras
        }

        if (num_barras == 5)                                     //se for 5 é aluno
        {
            struct no_aluno *novo = malloc(sizeof(struct no_aluno));
            novo->data_nascimento = malloc(sizeof(struct data));            //epa, perguntei ao gemini como poderia deixar esta parte sem erro ja q o create e insert ta um coto confuso e deu isto, ta chill por enquanto q eu saiba
            novo->despesas = NULL;

            // %[^|] lê tudo até à próxima barra vertical (apanha espaços bem)
            sscanf(linha, "%[^|]|%d/%d/%d|%[^|]|%d|%d|%ld", 
                   novo->nome, &novo->data_nascimento->dia, &novo->data_nascimento->mes, &novo->data_nascimento->ano,
                   novo->curso, &novo->ano, &novo->numero, &novo->saldo);

            // Insere na lista ligada de alunos
            insert_aluno(list, novo);

            // damos save state do aluno pas despesas
            aluno_atual = novo;
        }
        else if (num_barras == 2)
        {
            struct no_despesa *nova_despesa = malloc(sizeof(struct no_despesa));
            nova_despesa->data_despesa = malloc(sizeof(struct data));

            sscanf(linha, "%f|%[^|]|%d/%d/%d", 
                   &nova_despesa->valor, 
                   nova_despesa->descricao,                  //mesma cena do aluno
                   &nova_despesa->data_despesa->dia, 
                   &nova_despesa->data_despesa->mes, 
                   &nova_despesa->data_despesa->ano);

            // mete-a no no do aluno
            insert_despesa(aluno_atual, nova_despesa);
        }
    }

    fclose(f_txt);     //fecha a leitura :DDD
}

// vou dar commit das cenas q fiz, posso explicar a logica rapida do save
//abre o mesmo ficheiro q lemos para escrevemos por cima e dar save
//pega na lista de alunos e percorre cada lista ligada de despesas dos nos da mesma
//a mesma cena q tinhamos dito na aula de ler, fazemos para o save
// no final, limpa as estruturas todas

void save_state(struct no_aluno *list)
{
    FILE *f_txt = fopen("Dados.txt", "w");
    if(verificar_file(f_txt) == 1) exit(1);

    struct no_aluno *aux = list->prox;

    while(aux != NULL)
    {
        fprintf(f_txt, "%s|%d/%d/%d|%s|%d|%d|%.2f\n", aux->nome, aux->data_nascimento->dia, 
                   aux->data_nascimento->mes, aux->data_nascimento->ano,
                   aux->curso, aux->ano, aux->numero, aux->saldo);

        struct no_despesa *aux_desp = aux->despesas;

        while(aux_desp != NULL)
        {
            fprintf(f_txt, "%.2f|%s|%d/%d/%d\n", aux_desp->valor, aux_desp->descricao, 
                    aux_desp->data_despesa->dia, aux_desp->data_despesa->mes, aux_desp->data_despesa->ano);

            aux_desp = aux_desp->prox;
        }

        aux = aux->prox;
    }

    fclose(f_txt);

    clean_alunos(list);
}