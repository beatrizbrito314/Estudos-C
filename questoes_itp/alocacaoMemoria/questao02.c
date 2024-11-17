#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarNumeros(char *str) {
    int contador = 0;
    char *token = strtok(str, " ");
    
    while (token != NULL) {
        contador++;
        token = strtok(NULL, " ");
    }
    
    return contador;
}

void inserirNumerosNoVetor(char *str, int *vetor) {
    char *token = strtok(str, " ");
    int i = 0;
    
    while (token != NULL) {
        vetor[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }
}

void ordenarVetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    char entrada[100];
    fgets(entrada, 100, stdin); 
    entrada[strcspn(entrada, "\n")] = 0;  

    
    int tamVetor = contarNumeros(entrada);
    int *vetor = (int *)malloc(tamVetor * sizeof(int));
  

    inserirNumerosNoVetor(entrada, vetor);
    ordenarVetor(vetor, tamVetor);

    for (int i = 0; i < tamVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}