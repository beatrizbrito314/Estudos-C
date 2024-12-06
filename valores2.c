#include <stdio.h>
int main(){
    int tamanho;
    int vetor[tamanho];
    int duplicado=0;
    scanf("%d", &tamanho);

    for(int i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i=0; i<tamanho-1; i++){
        for(int j=0; j<tamanho;j++){
            if(vetor[i]==vetor[j]){
                duplicado=1;
                printf("%d", vetor[j]);
                break;
            }
        }
    }
    if(!duplicado){
        printf("nao foram encontrados");
    }


return 0;

}