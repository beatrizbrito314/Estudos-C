#include <stdio.h>

int main() {
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);

    int resto, inverso = 0;

    // Verificar se o número é palíndromo
    int temp = num;
    while (temp != 0) {
        resto = temp % 10;
     inverso = inverso * 10 + resto;
        temp /= 10;
    }

    //Condicionais para verificar os casos em que o numerro é ou não palindromo e é ou não par
    if (num == inverso && num % 2 == 0) {
        printf("%d e um numero palindromo e par.\n", num);
    } else if (num == inverso && num % 2 != 0){
        printf("%d e um numero palindromo e impar.\n", num);
    }else if (num != inverso && num % 2 == 0){
        printf("%d nao e um numero palindromo, mas e par.\n", num);
    }else {
        printf("%d nao e um número palindrom, mas e impar \n", num);
    }


    return 0;
}