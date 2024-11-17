#include <stdio.h>
int main(){
    int matriz[3][3]={{1,2,3},{1,2,4},{1,2,3}};
    int linha, maior=0;
    printf("linha: ");
    scanf("%d",  &linha);
    //scanf("%d ",  &coluna);
    
    //imprimir matriz
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            printf("%d ", matriz[i][j]);
    }printf("\n");
    //verificar
    for(int c=0; c<3;c++){
        if(matriz[linha][c]>maior){
            maior=matriz[linha][c];
        }
    }    
}
    printf("%d\n", maior);


return 0;}