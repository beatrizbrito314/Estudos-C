#include <stdio.h>

int soma_divisores(int numero) {
    int i;
    int soma = 0;
    for (i = 1; i < numero; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }
    return soma;
}

int colegas(int num1, int num2) {
    int soma1 = soma_divisores(num1);
    int soma2 = soma_divisores(num2);
    return (abs(soma1 - num2) <= 2) && (abs(soma2 - num1) <= 2);
}

int main() {
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    
    if (colegas(num1, num2)) {
        printf("S");
    } else {
        printf("N");
    }
    return 0;
}