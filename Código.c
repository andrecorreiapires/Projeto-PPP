#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source_bar.h"
#define LINHA 100
int main(){
    struct no_aluno *agenda = create_aluno();
    struct no_aluno *novo =create_aluno();
    agenda->prox=novo;
    int num_alunos =0;//Contador para o número de alunos
    FILE *f_txt = fopen("Dados.txt", "r");
    if(f_txt!=NULL){
        while(num_alunos<LINHA && fscanf(f_txt, "%s|%d/%d/%d|%s|%d|%d|%d", 
            novo->nome, novo->data_nascimento->dia, novo->data_nascimento->mes, novo->data_nascimento->ano,
            novo->curso, novo->ano, novo->numero, novo->saldo)!=EOF){
            num_alunos++;
        }
        
    }
}

/*        while(fgets(linha, sizeof(linha), f_txt)){
            if(fscanf(linha, "%s|%d/%d/%d|%s|%d|%d|%d",  )==8){
            }
        }
*\