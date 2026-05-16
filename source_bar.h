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
    struct data *data_despesa;
    struct no_despesa *prox;
};

struct no_aluno {         
    char nome[150];
    struct data *data_nascimento;
    char curso[50];
    int ano;
    int numero;
    float saldo;
    
    struct no_despesa *despesas; 
    struct no_aluno *prox; 
};

// DEFINITIONS

// Principal and Aux Funcs

struct no_aluno *create_aluno(void);
void clean_alunos(struct no_aluno *list);
void insert_aluno(struct no_aluno *list, struct no_aluno *a);

struct no_aluno *create_despesa(void);
void clean_despesas(struct no_aluno *aluno);
void insert_despesa(struct no_aluno *list, struct no_despesa *despesa);

//  prints e comodidades de exc_prints.c

void limpar_prompt(); 
void disclaimer(char buffer[]);
int menu();
void finale(); 

//  verificações de exc_prints.c

int verificar_file(FILE *f);
int verificar_int_final(char buffer[], char final); 
int verificar_data_existente(int dia, int mes, int ano); 
int verificar_input(char input[], char buffer[]);

// file_manager.c

void ler_ficheiro(struct no_aluno *list);
void save_state(struct no_aluno *list);
#endif