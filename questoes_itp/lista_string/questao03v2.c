#include <stdio.h>
#include <string.h>

int main() {
    char texto[51];
    char padrao[10];
    char verificaErro[10];

    int achouPadrao, erroIndex, count = 0, tamTexto, tamPadrao;

    fgets(texto, 51, stdin);
    fgets(padrao, 10, stdin);
    texto[strcspn(texto, "\n")] = 0; 
    padrao[strcspn(padrao, "\n")] = 0; 

    tamTexto = strlen(texto);
    tamPadrao = strlen(padrao);

    while (count <= tamTexto - tamPadrao) {
        achouPadrao = 1; 
        for (int i = 0; i < tamPadrao; i++) {
            if (texto[count + i] != padrao[i]) {
                achouPadrao = 0; 
                
                for (int j = 0; j < i; j++) {
                    printf("%c ", texto[count + j]);
                }
                printf("%c não\n", texto[count + i]);
                break;
            }
        }
        if (achouPadrao) {
            
            for (int l = 0; l < tamPadrao; l++) {
                printf("%c ", padrao[l]);
            }
            printf("sim\n");
            printf("Achei o padrão no índice %d\n", count);
            break;
        }
        count++;
    }
    
    if (count > tamTexto - tamPadrao) {
        printf("Não achei o padrão \n");
    }

    return 0;
}