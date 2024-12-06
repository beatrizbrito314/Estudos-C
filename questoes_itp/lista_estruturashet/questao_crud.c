#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[51];
    int idade;
    char sexo[2]; 
} info;

info criar(char nome[51], int idade, char sexo[2]) {
    info novaPessoa;
    strncpy(novaPessoa.nome, nome, 51);
    novaPessoa.idade = idade;
    strncpy(novaPessoa.sexo, sexo, 2);
    return novaPessoa;
}

void inserir(info *pessoas, int *count, info novaPessoa) {
    pessoas[*count] = novaPessoa;
    (*count)++;
}

void deletar(info *pessoas, int *count, info pessoa) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(pessoas[i].nome, pessoa.nome) == 0 &&
            pessoas[i].idade == pessoa.idade &&
            strcmp(pessoas[i].sexo, pessoa.sexo) == 0) {
            
            for (int j = i; j < *count - 1; j++) {
                pessoas[j] = pessoas[j + 1]; 
            }
            (*count)--; 
            break; 
        }
    }
}

void imprimir(info *pessoas, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s,%d,%s\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }
}

int main() {
    info pessoas[100]; 
    int count = 0;
    char comando;

    while (1) {
        scanf(" %c", &comando); 

        if (comando == 'i') {
            char nome[51];
            int idade;
            char sexo[2];
            scanf(" %[^\n]s", nome); 
            scanf("%d", &idade); 
            scanf("%s", sexo); 
            info novaPessoa = criar(nome, idade, sexo);
            inserir(pessoas, &count, novaPessoa);
        } else if (comando == 'd') {
            char nome[51];
            int idade;
            char sexo[2];
            scanf(" %[^\n]s", nome);
            scanf("%d", &idade);
            scanf("%s", sexo);
            info pessoaParaDeletar = criar(nome, idade, sexo);
            deletar(pessoas, &count, pessoaParaDeletar);
        } else if (comando == 'p') {
            imprimir(pessoas, count);
            break; 
        }
    }

    return 0;
}