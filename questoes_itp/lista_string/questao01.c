#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void cripto(char mensagem[201], char chave[4]) {
    int letra=0;
     const char S[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '
    };
    for(int i=0; i< strlen(mensagem); i++){
        letra=0;
        for(int j=0;j<strlen(S); j++){
            
            if(mensagem[i]==S[j]){
                letra=1;
                break;
            }else{
                continue;
            }
    }}
    if(!letra){
                printf("Invalido");
                return;
                
            }else{
    

    int j = 0;
    //verificar qtd de digitos da chave
    if (strlen(chave)>4){
        printf("Chave invalida!");
    }else{
    
    //inicializar com 0 p nao ficar com caractere esquisito no final
     char msgCripto[201]={0};
     
    
    
    for(int i = 0; i < strlen(mensagem); i++) {
        
        
        int chaveIndice = i % 4;
        
        for(int j = 0; j < 41; j++) {
            if((mensagem[i]) == S[j]) { 
                
                int deslocamento = (chave[chaveIndice] - '0'); //-0 para converter para int
                int novaPosicao = (j + deslocamento) % 40;
                msgCripto[i] = S[novaPosicao];
                break;
            }
        }
    }
    
    printf("%s\n", msgCripto);
}}}
int main() {
    //1 posicao a mais reservada p \0
    char k[5];
    char p[201];
    
    
    scanf("%s", k);
    getchar(); //limpar buffer do teclado
    fgets(p, 201, stdin); //considera espacos
    p[strcspn(p, "\n")] = 0;
    cripto(p, k);
    
    return 0;
}