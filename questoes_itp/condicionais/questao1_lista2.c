#include <stdio.h>

int main() {
  int linhas, i, j;
  char letra;

  // Solicita ao usuário o número de linhas e o caractere desejado
  scanf("%d %c", &linhas, &letra);


for (i = 1; i < linhas; i++) {
  for (j = 1; j <= linhas; j++) {
    if (i == j || i + j == linhas) {
      printf("%c", letra);
    } else {
      printf(" "); 
    }
  }
  printf("\n");
}

  return 0;
}