#include <stdio.h>
#include <string.h>

const char S[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '
};

void descobriChave(char msgCifrada[201], int fragmentoKP[8], int chave[5]) {
    int msgCrip[201];
    int count = 0;
    int resultado[201] = {0};
    int cont = 0;
    
    // Convertendo a mensagem cifrada para índices
    for (int k = 0; k < strlen(msgCifrada); k++) {
        for (int j = 0; j < strlen(S); j++) {
            if (msgCifrada[k] == S[j]) {
                msgCrip[count++] = j;
                break;
            }
        }
    }

    do {
        for (int i = 0; i < 8; ++i) {
            
                resultado[i] = ((msgCrip[i + cont] - fragmentoKP[i]) + 40)%40;
            
        }
        cont += 1;
    } while (cont < count - 8 && (resultado[0] > 9 || resultado[1] > 9 || resultado[2] > 9 || resultado[3] > 9 ||
             resultado[4] > 9 || resultado[5] > 9 || resultado[6] > 9 || resultado[7] > 9));
int perm_index = (cont - 1) % 4;

       if (perm_index == 0) {
        chave[0] = resultado[0];
        chave[1] = resultado[1];
        chave[2] = resultado[2];
        chave[3] = resultado[3];
    } else if (perm_index == 1) {
        chave[0] = resultado[3];
        chave[1] = resultado[0];
        chave[2] = resultado[1];
        chave[3] = resultado[2];
    } else if (perm_index == 2) {
        chave[0] = resultado[2];
        chave[1] = resultado[3];
        chave[2] = resultado[0];
        chave[3] = resultado[1];
    } else if (perm_index == 3) {
        chave[0] = resultado[1];
        chave[1] = resultado[2];
        chave[2] = resultado[3];
        chave[3] = resultado[0];
    }

    }

void descripto(char msgCripto[201], int chave[5]) {
    
    char mensagem[201] = {0};
    
    for(int i = 0; i < strlen(msgCripto); i++) {
        int chaveIndice = i % 4;
        if(chave[0]==0 && chave[1]==0 && chave[2]==0 && chave[3]==0){
            break;
        }
        else{
        
        for(int j = 0; j < 40; j++) {
            if(msgCripto[i] == S[j]) {
                int deslocamento = (chave[chaveIndice] );
                int novaPosicao = (j - deslocamento + 40) % 40;
                mensagem[i] = S[novaPosicao];
                break;
            }}
        }
    }
    
    printf("%s\n", mensagem);
    
}

int main() {
    int fragmento[8] = {26, 30, 14, 39, 10, 39, 15, 24};
    char msgCifrada[201];

    
    fgets(msgCifrada, 201, stdin);
    msgCifrada[strcspn(msgCifrada, "\n")] = 0;

    int chave[5] = {0};
    descobriChave(msgCifrada, fragmento, chave);
    int verificar=0;
    for  (int i = 0; i < 4; i++) {
        if(chave[0]==0 && chave[1]==0 && chave[2]==0 && chave[3]==0 || chave[i]>9){
            verificar=1;
            break;
        }}
        if(verificar==1){
            printf("Mensagem nao e da Resistencia!\n");
        }else{
             for  (int i = 0; i < 4; i++) {
             printf("%d", chave[i]);}
             printf("\n");
             descripto(msgCifrada, chave);
        }
       

   
    
    
    return 0;
}