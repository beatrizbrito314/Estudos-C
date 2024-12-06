#include <stdio.h>

int main() {
    int num, posicaoDiv = 0, soma=0, count=0;
    scanf("%d", &num);
    int div[num]; 

    for (int i = 1; i < num; i++) {  
        if (num % i == 0) {
            div[posicaoDiv] = i;  
            posicaoDiv++;       
            
        }
    }
    for(int j=0; j<posicaoDiv; j++ ){
        soma=div[j]+soma;
    }
    printf("%d  \n", soma);
    if(soma==num){
        printf("%d é um numero perfeito", num);
    }else{
        printf("%d nao é um numero perfeito", num);
    }
    return 0;
    }
    
    
