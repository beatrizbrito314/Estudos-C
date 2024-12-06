#include <stdio.h>
int main ( ){
    int qtd, qtdTotal;
    float valor, valorTotal;
    qtdTotal=0;
    valorTotal=0;
    do{
    printf("qtt e valor unitario");
    scanf(" %d %f", &qtd, &valor);
    if (qtd == -1) break;
    qtdTotal=qtdTotal+qtd;
    valorTotal=(qtd*valor)+valorTotal;
}while(1);
    printf("%d %f", qtdTotal, valorTotal);
    return 0;
}