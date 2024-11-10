#include <stdio.h>
#include <string.h>

int main() {
    char texto[51], padrao[51];
    int tamTexto, tamPadrao, i, j, achou = 0;

    
    fgets(texto, 51, stdin);
    fgets(padrao, 51, stdin);

  
    texto[strcspn(texto, "\n")] = 0; 
    padrao[strcspn(padrao, "\n")] = 0; 

    tamTexto = strlen(texto);
    tamPadrao = strlen(padrao);

    for (i = 0; i <= tamTexto - tamPadrao; i++) {
        int combina = 1;

        for (j = 0; j < tamPadrao; j++) {
            printf("%c ", texto[i + j]);
            if (texto[i + j] != padrao[j]) {
                combina = 0;
                break;
            }
        }

      
        if (!combina) {
            printf("não\n");
        } else { 
            printf("sim\n");
            printf("Achei o padrão no índice %d\n", i);
            achou = 1;
            break;
        }
    }

    
    if (!achou) {
        printf("Não achei o padrão\n");
    }

    return 0;
}
