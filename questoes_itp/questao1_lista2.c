#include <stdio.h>

int main() {
  int linhas, i, j;
  char caractere;

  // Solicita ao usuário o número de linhas e o caractere desejado
  printf("Digite um numero inteiro e um caractere: ");
  scanf("%d %c", &linhas, &caractere);


  // Desenha o X
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < linhas; j++) {
      if (i == j || i + j == linhas - 1) {
        printf("%c", caractere);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}