#ifndef BAR_H
#define BAR_H

struct data {
    int dia;
    int mes;
    int ano;
};

struct no_despesa {
    float valor;
    char descricao[100];
    struct data data_despesa;
    struct no_despesa *prox;
};

struct no_aluno {         
    char nome[150];
    struct data data_nascimento;
    char curso[50];
    int ano;
    int numero;
    float saldo;
    
    struct no_despesa *despesas; 
    struct no_aluno *prox; 
};

struct no_aluno *create(void);
void clean(struct no_aluno *list);
void insert(struct no_aluno *list, struct no_aluno a);

#endif