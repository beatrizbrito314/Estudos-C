#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool validar(char quadro[SIZE][SIZE], int linhas, int colunas, char num) {
    for (int x = 0; x < SIZE; x++) {
        if (quadro[linhas][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < SIZE; x++) {
        if (quadro[x][colunas] == num) {
            return false;
        }
    }

    int para_linhas = linhas - linhas % 3;
    int para_colunas = colunas - colunas % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadro[i + para_linhas][j + para_colunas] == num) {
                return false;
            }
        }
    }

    return true;
}

bool resolver(char quadro[SIZE][SIZE]) {
    for (int linhas = 0; linhas < SIZE; linhas++) {
        for (int colunas = 0; colunas < SIZE; colunas++) {
            if (quadro[linhas][colunas] == '*') { 
                for (char num = '1'; num <= '9'; num++) {
                    if (validar(quadro, linhas, colunas, num)) {
                        quadro[linhas][colunas] = num; 

                        if (resolver(quadro)) {
                            return true; 
                        }

                        quadro[linhas][colunas] = '*'; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

 exibir_solucao(char quadro[SIZE][SIZE]) {
    for (int linhas = 0; linhas < SIZE; linhas++) {
        for (int colunas = 0; colunas < SIZE; colunas++) {
            printf("%c ", quadro[linhas][colunas]);
        }
        printf("\n");
    }
}

int main() {
    char quadro[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf(" %c", &quadro[i][j]);
        }
    }

    if (resolver(quadro)) {
        exibir_solucao(quadro);
    } else {
        printf("Não tem solução!\n");
    }

    return 0;
}