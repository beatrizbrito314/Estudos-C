#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeEspaco(char *entrada, char *novoTexto) {
    int j = 0;
    for (int i = 0; i < strlen(entrada); i++) {
        if (entrada[i] == '\n') {
            break;
        }
        if (entrada[i] != ' ') {
            novoTexto[j] = entrada[i];
            j++;
        }
    }
    novoTexto[j] = '\0'; 
}

int palindromoRecursivo(char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return 1; 
         return palindromoRecursivo(str, inicio + 1, fim - 1); 
    }
    if (str[inicio] != str[fim]) {
        return 0; 
    }
   
}

int palindromo(char *entrada) {
    char novoTexto[100];
    removeEspaco(entrada, novoTexto);
    int tam = strlen(novoTexto); 
    return palindromoRecursivo(novoTexto, 0, tam - 1); 
}

int main() {
    char entrada[100];
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 
    if (palindromo(entrada)) {
        printf("O texto \"%s\" é um palíndromo\n", entrada);
    } else {
        printf("O texto \"%s\" não é um palíndromo\n", entrada);
    }

    return 0;
}