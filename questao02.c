#include <stdio.h>

int main() {
    int dimencao, i, j, somaT;
    int principal = 0, secundaria = 0;

    
    printf("Digite o tamanho da matriz quadrada (n x n): ");
    scanf("%d", &dimencao);

   
    int matriz[dimencao][dimencao];

    
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < dimencao; i++) {
        for (j = 0; j < dimencao; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < dimencao; i++) {
        principal += matriz[i][i]; 
        secundaria += matriz[i][dimencao - i - 1]; 
    }

    somaT = principal + secundaria;

    printf("Soma da diagonal principal: %d\n", principal);
    printf("Soma da diagonal secundária: %d\n", secundaria);
    printf("Soma total das duas diagonais: %d\n", somaTotal);

    return 0;
}

