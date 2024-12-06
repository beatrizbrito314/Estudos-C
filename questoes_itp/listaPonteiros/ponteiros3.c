#include <stdio.h>
void calcular_media(int *A, int *B) {
    int media = (*A + *B) / 2;
    int mod = (*A + *B) % 2; 
    if (*A < *B) {
        *A = media; 
        *B = mod; 
    } else {
        *B = media; 
        *A = mod; 
    }
}
int main() {
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);
    calcular_media(&num1, &num2);
    printf("A = %d\n", num1);
    printf("B = %d\n", num2);
    return 0;
}