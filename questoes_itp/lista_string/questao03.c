#include <stdio.h>
#include <string.h>

int main() {
    char texto[51], padrao[51];
    int tamanho_texto, tamanho_padrao, i, j, indice_padrao, achou = 0;

    fgets(texto, 51, stdin);
    fgets(padrao, 51, stdin);

    texto[strcspn(texto, "\n")] = 0;
    padrao[strcspn(padrao, "\n")] = 0;

    tamanho_texto = strlen(texto);
    tamanho_padrao = strlen(padrao);

    for (i = 0; i <= tamanho_texto - tamanho_padrao; i++) {
        indice_padrao = 0;
        int grupo_casou = 1;

        for (j = i; j < i + tamanho_padrao; j++) {
            printf("%c ", texto[j]); 
            if (texto[j] != padrao[indice_padrao]) {
                grupo_casou = 0;  
                break;
            }
            indice_padrao++;
        }

        if (grupo_casou && indice_padrao == tamanho_padrao) {
            printf("sim\n");
            achou = 1;
            printf("Achei o padrão no índice %d\n", i);
            break;
        } else {
            printf("não\n");
        }
    }

    if (!achou) {
        printf("Não achei o padrão\n");
    }

    return 0;
}
