#include <stdio.h>
#include <stdlib.h>
#include "source_bar.h"
//BÁSICO

int pesquisar(struct no_aluno *a, int procurar, int *indice){
    struct elemento *temp = a->header;
    int pos = 0;
    while (temp != NULL) {
        if (temp->valor == procurar) {
            if (indice != NULL) *indice = pos;
            return temp->valor;
        }
        temp = temp->prox;
        pos++;
    }
    return -1;
}

// ALUNOS

struct no_aluno *create_aluno(void) {
    struct no_aluno *aux = (struct no_aluno *)malloc(sizeof(struct no_aluno));
    if (aux != NULL) {
        aux->prox = NULL;
        aux->despesas = NULL;
        aux->ano=NULL;
        aux->curso=NULL;
        aux->data_nascimento=NULL;
        aux->nome=NULL;
        aux->numero=NULL;
        aux->saldo=NULL;
    }
    return aux;
}

void clean_alunos(struct no_aluno *list) {
    while (list != NULL) {
        struct no_aluno *temp = list;

        clean_despesas(temp);

        list = list->prox;
        free(temp);
    }
}

void insert_aluno(struct no_aluno *list, struct no_aluno aluno) {
    struct no_aluno *novo = (struct no_aluno *)malloc(sizeof(struct no_aluno));
    if (novo != NULL) {
        *novo = aluno;
        novo->prox = list->prox;
        list->prox = novo;
        novo->
    }
}


// DESPESAS


void *create_despesa(void){
    struct no_despesa *aux = (struct no_despesa *)malloc(sizeof(struct no_despesa));
    if (aux != NULL){
        aux->prox = NULL;
        aux->data_despesa=NULL;
        aux->descricao=NULL;
        aux->valor=NULL;
    }
}
void clean_despesas(struct no_aluno *aluno){
    struct no_despesa *list = aluno->despesas;
    while (list != NULL){
        struct no_despesa *temp = list;
        list = list->prox;
        free(temp);
    }
}

void insert_despesa(struct no_aluno *list, struct no_despesa despesa) {
    struct no_despesa *novo = (struct no_despesa *)malloc(sizeof(struct no_despesa));
    if (novo != NULL) {
        *novo = despesa;
        novo->prox = list->prox;
        list->prox = novo;
    }
}