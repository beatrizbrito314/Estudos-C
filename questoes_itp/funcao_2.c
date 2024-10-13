#include <stdio.h>

int score_dia(int score1, int score2, int score3) {
    int maior= score1;
    int menor= score1;
    int medio = score1;

    if (score2 > maior) {
        medio = maior;
        maior = score2;
    } else if (score2 < menor) {
        medio = menor;
        menor = score2;
    } else {
        medio = score2;
    }

    if (score3 > maior) {
        medio = maior;
        maior = score3;
    } else if (score3 < menor) {
        medio = menor;
        menor = score3;
    } else {
        medio = score3;
    }

    if (medio == maior || medio == menor) {
        return medio;
    } else {
        return medio;
    }
}

int main() {
    int scoreA1, scoreA2, scoreA3, scoreA4, scoreA5, scoreA6, scoreA7, scoreA8, scoreA9;
    int scoreB1, scoreB2, scoreB3, scoreB4, scoreB5, scoreB6, scoreB7, scoreB8, scoreB9;

    scanf("%d %d %d %d %d %d %d %d %d", &scoreA1, &scoreA2, &scoreA3, &scoreA4, &scoreA5, &scoreA6, &scoreA7, &scoreA8, &scoreA9);
    scanf("%d %d %d %d %d %d %d %d %d", &scoreB1, &scoreB2, &scoreB3, &scoreB4, &scoreB5, &scoreB6, &scoreB7, &scoreB8, &scoreB9);

    int scoreA_dia1 = score_dia(scoreA1, scoreA2, scoreA3);
    int scoreA_dia2 = score_dia(scoreA4, scoreA5, scoreA6);
    int scoreA_dia3 = score_dia(scoreA7, scoreA8, scoreA9);

    int scoreB_dia1 = score_dia(scoreB1, scoreB2, scoreB3);
    int scoreB_dia2 = score_dia(scoreB4, scoreB5, scoreB6);
    int scoreB_dia3 = score_dia(scoreB7, scoreB8, scoreB9);

    int scoreA_final = score_dia(scoreA_dia1, scoreA_dia2, scoreA_dia3);
    int scoreB_final = score_dia(scoreB_dia1, scoreB_dia2, scoreB_dia3);

    if (scoreA_final > scoreB_final) {
        printf("A\n");
    } else if (scoreA_final < scoreB_final) {
        printf("B\n");
    } else {
        printf("empate\n");
    }

    return 0;
}