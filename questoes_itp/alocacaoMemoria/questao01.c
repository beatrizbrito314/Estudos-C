#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int s;
    scanf("%d ", &s);
    srand(s);
    int n = 0;
    char **participantes = (char **)malloc(20 * sizeof(char *)); 
    

    do {
        char participante[20];
        fgets(participante, sizeof(participante), stdin);
        participante[strcspn(participante, "\n")] = 0; 

        if (strcmp(participante, "acabou") == 0) {
            break; 
        }
        
        participantes[n] = (char *)malloc((strlen(participante) + 1) * sizeof(char));
        strcpy(participantes[n], participante);//inserir no vetor de maneira + eficiente
        n++;
    } while (1); 
  
   
    int *sorteados = (int *)calloc(n, sizeof(int));//calloc inicializa c 0
    //1=sorteado
    //0=nao sorteado

    for(int i = 0; i < n; i++){
        int indexParticipante;
        do {
            indexParticipante = rand() % n;
        } while (sorteados[indexParticipante] == 1); 

        sorteados[indexParticipante] = 1; 
        printf("%s ", participantes[indexParticipante]); 
    }
    printf("\n");
    printf("%d ", n);

   
    for (int i = 0; i < n; i++) {
        free(participantes[i]); 
    }
    free(participantes);
    free(sorteados); 

    return 0;
}