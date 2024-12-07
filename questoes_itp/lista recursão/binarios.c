#include <stdio.h>

void converterParaBinario(int numero) {
    if (numero == 0) { 
        return;
    }
    
    converterParaBinario(numero / 2);
    
    printf("%d", numero % 2);
}

int main() {
    int numero;

    scanf("%d", &numero);

    if (numero == 0) {
        printf("0\n");
    } else {
        converterParaBinario(numero);
        printf("\n");
    }

    return 0;
}