#include <stdio.h>

int main() {
    int num;
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
        printf("%d é Palíndromo e par.\n", num);
    } else if (num == inverso && num % 2 != 0){
        printf("%d é Palíndromo e impar.\n", num);
    }else if (num != inverso && num % 2 == 0){
        printf("%d não é Palindromo e par.\n", num);
    }else {
        printf("%d não é Palindrom e impar \n", num);
    }


    return 0;
}