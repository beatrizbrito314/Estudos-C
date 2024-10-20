#include <stdio.h>
float media(char tipo, float num1, float num2, float num3) {
 float res;
    
    if (tipo == 'A') {
        res = (num1 + num2 + num3) / 3;
        printf("Média %.2f\n", res);
    } else if (tipo == 'P') {
        res = ((num1*4) + (num2*5) + (num3*6)) / 15;
        printf("Média %.2f\n", res);
    }
    
    return res;}

int main() {
    char tipo;
    float nota1, nota2, nota3;

    scanf(" %c", &tipo);
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    media(tipo, nota1, nota2, nota3);

    return 0;
}