#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "source_bar.h"
int main(){
    struct no_aluno *agenda = create_aluno();
    struct no_aluno aux;
    FILE *f_txt = fopen("Dados.txt", "r");
    if(f_txt!=NULL){
        int num_alunos =0;//Contador para o número de alunos
        while(fscanf("%s|%d/%d/%d|%s|%d|%d|%d", 
            [])&&!=EOF){
            struct no_aluno *novo =create_aluno();
        num_alunos++;
        }
    }else{
        return;
    }
}