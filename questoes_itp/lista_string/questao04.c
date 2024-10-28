#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    char prefixos[100][11]; // Limite de 10 caracteres
    char sufixos[100][11];  // Limite de 10 caracteres
    char palavra[101];      // Limite de 100 caracteres
    char processadas[100][101];
    int contador_palavras = 0;

    // Lendo a quantidade de prefixos
    scanf("%d", &n);
    // Lendo os prefixos em si
    for (int i = 0; i < n; i++) {
        scanf("%s", prefixos[i]);
    }

    // Lendo a quantidade de sufixos
    scanf("%d", &m);
    // Lendo os sufixos em si
    for (int i = 0; i < m; i++) {
        scanf("%s", sufixos[i]);
    }

    // Lendo as palavras (até -1)
    while (1) {
        palavra[0] = '\0';  // Limpa a palavra para o próximo ciclo
        scanf("%s", palavra);
        if (strcmp(palavra, "-1") == 0) {  // Compara as strings
            break;
        }

        // Removendo os prefixos
        for (int i = 0; i < n; i++) {
            int prefixo_l = strlen(prefixos[i]);
            if (strncmp(palavra, prefixos[i], prefixo_l) == 0) {
                strcpy(palavra, palavra + prefixo_l);
                break;
            }
        }

        // Removendo os sufixos
        for (int i = 0; i < m; i++) {
            int sufixo_l = strlen(sufixos[i]);
            int palavra_l = strlen(palavra);
            if (palavra_l >= sufixo_l && strcmp(palavra + palavra_l - sufixo_l, sufixos[i]) == 0) {
                palavra[palavra_l - sufixo_l] = '\0';
                break;
            }
        }

        // Armazenando a palavra, depois do processo (se ela tiver caracteres)
        if (strlen(palavra) > 0 && contador_palavras < 100) { strcpy(processadas[contador_palavras], palavra);
            contador_palavras++;
        }
    }

    // Exibindo as palavras
    for (int i = 0; i < contador_palavras; i++) {
        printf("%s\n", processadas[i]);
    }

    return 0;
}
