#include <stdio.h>

int nivel(float velocidade){
    if (velocidade < 10) {
    return 1;
    }else if(velocidade >=  10 && velocidade < 20){
    return 2;
    }else{
    return 3;
    }
}

int main() {
  int qtdLesmas, velocidade, maxNivel;
  maxNivel=0;
  i=1;

  scanf("%d", &qtdLesmas);

  while (i<=qtdLesmas) {
    scanf("%d", &velocidade);
    int nivelLesma = nivel(velocidade);
    if (level > maxNivel) {
      maxNivel = nivelLesma;
    }
    i+=1;
  }

  printf("Level %d\n", maior_level);

  return 0;
}