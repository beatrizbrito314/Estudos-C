#include <stdio.h>

void calcular_media(int *A, int *B) {
    int media = (*A + *B) / 2;
    int resto = (*A + *B) % 2; 

    if (*A < *B) {
        *A = media; 
        *B = resto; 
    } else {
        *B = media; 
        *A = resto; 
    }
}

int main() {
    int A, B;

    scanf("%d", &A);
    scanf("%d", &B);

    calcular_media(&A, &B);

    printf("A = %d\n", A);
    printf("B = %d\n", B);

    return 0;
}