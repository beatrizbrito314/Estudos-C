#include <stdio.h>
 //Esse demõnio dessa questão que passei três dias fazendo tbm quem manda a pessoa ser burra
int main() {
    int n, i, chamada;
    float media;

    scanf("%d", &n);

    int aprovados[n], recuperacao[n], reprovados[n];
    float mediaApr[n], mediaRec[n], mediaRepr[n];
    int contagemApr = 0, contagemRec = 0, contagemRepr = 0;

    for (i = 0; i < n; i++) {
        scanf("%d - %f", &chamada, &media);

        if (media >= 7.0) {
            aprovados[contagemApr] = chamada;
            mediaApr[contagemApr] = media;
            contagemApr++;
        } else if (media >= 5.0) {
            recuperacao[contagemRec] = chamada;
            mediaRec[contagemRec] = media;
            contagemRec++;
        } else {
            reprovados[contagemRepr] = chamada;
            mediaRepr[contagemRepr] = media;
            contagemRepr++;
        }
    }

    printf("Aprovados: ");
    for (i = 0; i < contagemApr; i++) {
        if (i > 0) printf(", ");
        printf("%d (%.1f)", aprovados[i], mediaApr[i]);
    }

    if (contagemRec > 0) {
        printf("\nRecuperação: ");
        for (i = 0; i < contagemRec; i++) {
            if (i > 0) printf(", ");
            printf("%d (%.1f)", recuperacao[i], mediaRec[i]);
        }
    }

    if (contagemRepr > 0) {
        printf("\nReprovados: ");
        for (i = 0; i < contagemRepr; i++) {
            if (i > 0) printf(", ");
            printf("%d (%.1f)", reprovados[i], mediaRepr[i]);
        }
    }
    return 0;
}