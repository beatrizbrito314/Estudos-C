#include <stdio.h>

int verificaLinha(char tabuleiro[3][3], int x, int y, char simb) {
   if((tabuleiro[x][0] == simb || (x == x && y == 0)) &&
            (tabuleiro[x][1] == simb || (x == x && y == 1)) &&
            (tabuleiro[x][2] == simb || (x == x && y == 2))){
                return 1;
            }else{
                return 0;
            }
}

int verificaColuna(char tabuleiro[3][3], int x, int y, char simb) {
    if ((tabuleiro[0][y] == simb || (x == 0 && y == y)) &&
            (tabuleiro[1][y] == simb || (x == 1 && y == y)) &&
            (tabuleiro[2][y] == simb || (x == 2 && y == y))){
                return 1;
            }else{
                return 0;
            }
}

int verificaDiagonais(char tabuleiro[3][3], int x, int y, char simb) {
    if(((tabuleiro[0][0] == simb || (x == 0 && y == 0)) &&
             (tabuleiro[1][1] == simb || (x == 1 && y == 1)) &&
             (tabuleiro[2][2] == simb || (x == 2 && y == 2))) ||
            ((tabuleiro[0][2] == simb || (x == 0 && y == 2)) &&
             (tabuleiro[1][1] == simb || (x == 1 && y == 1)) &&
             (tabuleiro[2][0] == simb || (x == 2 && y == 0)))){
                return 1;
            }else{
                return 0;
            }
}

int main() {
    int i, j, x, y, n, k;
    char confTabuleiro[3][3], simb;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf(" %c", &confTabuleiro[i][j]);
        }
    }

    scanf("%d", &n);
    
    for (k = 0; k < n; k++) {
        scanf(" %d %d %c", &x, &y, &simb);
        x--;
        y--;
        if (confTabuleiro[x][y] == 'X' || confTabuleiro[x][y] == 'O') {
            printf("Jogada inválida!\n");
        }
        else if (verificaLinha(confTabuleiro, x, y, simb) || 
                 verificaColuna(confTabuleiro, x, y, simb) || 
                 verificaDiagonais(confTabuleiro, x, y, simb)) {
            printf("Boa jogada, vai vencer!\n");
        }
        else {
            printf("Continua o jogo.\n");
        }
    }

    return 0;
}