#ifndef SOURCE_BAR_H
#define SOURCE_BAR_H

// STRUCTS

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

// DEFINITIONS

struct no_aluno *create_aluno(void);
void clean_alunos(struct no_aluno *list);
void insert_aluno(struct no_aluno *list, struct no_aluno a);

struct no_aluno *create_despesa(void);
void clean_despesas(struct no_aluno *aluno);
void insert_despesa(struct no_aluno *list, struct no_despesa a);

#endif