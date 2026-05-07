#include <stdio.h>
#include <stdlib.h>
#include "source_bar.h"

struct no_aluno *create(void) {
    struct no_aluno *aux = (struct no_aluno *)malloc(sizeof(struct no_aluno));
    if (aux != NULL) {
        aux->prox = NULL;
        aux->despesas = NULL;
    }
    return aux;
}

void clean(struct no_aluno *list) {
    while (list != NULL) {
        struct no_aluno *temp = list;



        list = list->prox;
        free(temp);
    }
}

void insert(struct no_aluno *list, struct no_aluno novo_dados) {
    struct no_aluno *novo = (struct no_aluno *)malloc(sizeof(struct no_aluno));
    if (novo != NULL) {
        *novo = novo_dados;
        novo->prox = list->prox;
        list->prox = novo;
    }
}