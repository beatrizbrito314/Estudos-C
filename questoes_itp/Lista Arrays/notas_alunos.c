#include <stdio.h>
 
int main() {
    int n, i, chamada;
    float media;

    scanf("%d", &n);

    int aprov[n], rec[n], repro[n];
    float aprovMedia[n], recMedia[n], reproMedia[n];
    int aprovCount,recCount, reproCount;
    aprovCount=recCount=reproCount=0;

    for (i = 0; i < n; i++) {
        scanf("%d - %f", &chamada, &media);

        if (media >= 7.0) {
            aprov[aprovCount] = chamada;
            aprovMedia[aprovCount] = media;
            aprovCount++;
        } else if (media >= 5.0) {
            rec[recCount] = chamada;
            recMedia[recCount] = media;
            recCount++;
        } else {
            repro[reproCount] = chamada;
            reproMedia[reproCount] = media;
            reproCount++;
        }
    }

    printf("Aprovados: ");
    for (i = 0; i < aprovCount; i++) {
        if (i > 0) printf(", ");
        printf("%d (%.1f)", aprov[i], aprovMedia[i]);
    }

    if (recCount > 0) {
        printf("\nRecuperação: ");
        for (i = 0; i < recCount; i++) {
            if (i > 0) printf(", ");
            printf("%d (%.1f)", rec[i], recMedia[i]);
        }
    }

    if (reproCount > 0) {
        printf("\nReprovados: ");
        for (i = 0; i < reproCount; i++) {
            if (i > 0) printf(", ");
            printf("%d (%.1f)", repro[i], reproMedia[i]);
        }
    }
    return 0;
}