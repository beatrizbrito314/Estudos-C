#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int nlin, int ncol) {
    int **mat, i, j;
    // Alocando espaço para matriz
    mat = (int **)malloc(nlin * sizeof(int *)); // Reservar espaço de cada linha
    if (mat == NULL) {
        return NULL; 
    }
    for (i = 0; i < nlin; i++) {
        mat[i] = (int *)malloc(ncol * sizeof(int)); // Reservar espaço de cada coluna
        if (mat[i] == NULL) {
            // Se a alocação falhar, libera a memória já alocada
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    return mat;
}
void readMatrix(int **mat, int nlin, int ncol) {
    for (int i = 0; i < nlin; i++) {
        for (int j = 0; j < ncol; j++) {
            
            scanf("%d", &mat[i][j]); // Lê o valor e armazena na matriz
        }
    }
}
void printMatrix(int **mat, int nlin, int ncol){
    for (int i = 0; i < nlin; i++) {
        for (int j = 0; j < ncol; j++) {
            
            printf("%d ", mat[i][j]); // imprime o valor e armazena na matriz
        }
        printf("\n");
    }


}
void destroyMatrix(int **mat, int nlin){
     for (int i = 0; i < nlin; i++) {
        free(mat[i]);
    }
    free(mat); 
}


int main(){
    int lin, col;
    scanf("%d %d", &lin, &col);
    int **mat = createMatrix(lin, col);
    readMatrix(mat, lin, col);
    printMatrix(mat, lin, col);
    destroyMatrix(mat, lin);
    mat=NULL;
    printf("OK \n");
    return 0;


}