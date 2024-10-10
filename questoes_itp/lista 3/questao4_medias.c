#include <stdio.h>

//função das medias
float calculaMedia(char tipo, float num1, float num2, float num3) {
    float result;
    switch (tipo) {
        case 'A':
            result = (num1 + num2 + num3) / 3;
            printf("Média %.2f\n", result);
            break;
        case 'P':
            result = ((num1*4) + (num2*5) + (num3*6)) / 15;
            printf("Média %.2f\n", result);
            break;
    }
    return result;
}

int main() {
    char tipo;
    float num1, num2, num3;

//leitura dos dados
    scanf(" %c", &tipo);
    scanf("%f %f %f", &num1, &num2, &num3);

//chamada da função
    calculaMedia(tipo, num1, num2, num3);

    return 0;
}