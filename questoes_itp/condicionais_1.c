#include <stdio.h>
int main ( ){
    float temp, c, k, f;
    char escala;
    printf("temperatura: ");
    scanf("%f %c",&temp, &escala);
    //printf("%d\n", temp);
    //printf("%c\n", escala);
    if  (escala == 'C'){
        c = temp;
        k = c + 273.15;
        f = (c * 1.8) + 32;
        printf("Celsius: %.2f\n", c);
        printf("Farenheit: %.2f\n", f);
        printf("Kelvin: %.2f\n", k);
    } else if (escala=='K'){
        k = temp;
        c = k-273.15;
        f = (k * 1.8) - 459.67;
        printf("Celsius: %.2f\n", c);
        printf("Farenheit: %.2f\n", f);
        printf("Kelvin: %.2f\n", k);
    }else if (escala=='F'){
        f = temp;
        k = (f+459.67)/1.8;
        c = (f-32)/1.8;
        printf("Celsius: %.2f\n", c);
        printf("Farenheit: %.2f\n", f);
        printf("Kelvin: %.2f\n", k);
    }

    return 0;
}