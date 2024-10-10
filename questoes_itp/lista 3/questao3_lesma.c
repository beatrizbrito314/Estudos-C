#include <stdio.h>

int definirLevel(float velocidade){
    if (velocidade < 10) {
    return 1;
    }else if(velocidade >=  10 && velocidade < 20){
    return 2;
    }else{
    return 3;
    }
}

int main() {
  int qtdLesmas, velocidade, maior_level = 0;

  scanf("%d", &qtdLesmas);

  for (int i = 0; i < qtdLesmas; i++) {
    scanf("%d", &velocidade);
    int level = definirLevel(velocidade);
    if (level > maior_level) {
      maior_level = level;
    }
  }

  printf("Level %d\n", maior_level);

  return 0;
}