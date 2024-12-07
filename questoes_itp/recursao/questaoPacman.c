#include <stdio.h>
#include <stdlib.h>

void posicaoPacman(char **matriz, int linhas, int colunas, int *linhaPacman, int *colunaPacman) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 'C') {
                *linhaPacman = i;
                *colunaPacman = j; 
                return; 
            }
        }
    }
}

int moverPacman(char **matriz, int linhas, int colunas, int *linhaPacman, int *colunaPacman) {
    int count = 0;

    // Mover para a direita
    if (*colunaPacman + 1 < colunas && matriz[*linhaPacman][*colunaPacman + 1] == '.') {
        matriz[*linhaPacman][*colunaPacman + 1] = ' '; // Marca como comida devorada
        *colunaPacman += 1;
        count += 1;
        count += moverPacman(matriz, linhas, colunas, linhaPacman, colunaPacman);
        *colunaPacman -= 1; // Volta para a posição anterior
    }
    // Mover para a esquerda
    if (*colunaPacman - 1 >= 0 && matriz[*linhaPacman][*colunaPacman - 1] == '.') {
        matriz[*linhaPacman][*colunaPacman - 1] = ' '; // Marca como comida devorada
        *colunaPacman -= 1;
        count += 1;
        count += moverPacman(matriz, linhas, colunas, linhaPacman, colunaPacman);
        *colunaPacman += 1; // Volta para a posição anterior
    }
    // Mover para baixo
    if (*linhaPacman + 1 < linhas && matriz[*linhaPacman + 1][*colunaPacman] == '.') {
        matriz[*linhaPacman + 1][*colunaPacman] = ' '; // Marca como comida devorada
        *linhaPacman += 1;
        count += 1;
        count += moverPacman(matriz, linhas, colunas, linhaPacman, colunaPacman);
        *linhaPacman -= 1; // Volta para a posição anterior
    }
    // Mover para cima
    if (*linhaPacman - 1 >= 0 && matriz[*linhaPacman - 1][*colunaPacman] == '.') {
        matriz[*linhaPacman - 1][*colunaPacman] = ' '; // Marca como comida devorada
        *linhaPacman -= 1;
        count += 1;
        count += moverPacman(matriz, linhas, colunas, linhaPacman, colunaPacman);
        *linhaPacman += 1; // Volta para a posição anterior
    }

    return count;
}

void print_novoMapa(char **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c", matriz[i][j]); // Imprime o mapa atualizado
        }
        printf("\n"); // Nova linha após cada linha do mapa
    }
}

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    
    char **mapa = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++) {
        mapa[i] = (char *)malloc(colunas * sizeof(char));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }
    
    int linhaPacman, colunaPacman;
    posicaoPacman(mapa, linhas, colunas, &linhaPacman, &colunaPacman);
    int qtdBolinhas = moverPacman(mapa, linhas, colunas, &linhaPacman, &colunaPacman);
    printf("Total de bolinhas devoradas: %d\n", qtdBolinhas);
    printf("Mapa final: \n");
    
    print_novoMapa(mapa, linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
    
    return 0;
}