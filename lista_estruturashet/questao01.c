#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[200];
    int vitorias;
    int empates;
    int derrotas;
    int golsFeitos;
    int golsSofridos;
} Time;

void lerTimes(Time time[], int t) {
    for(int i = 0; i < t; i++) {
        scanf(" %[^;]; %d %d %d %d %d", time[i].nome, &time[i].vitorias, 
              &time[i].empates, &time[i].derrotas, &time[i].golsFeitos, 
              &time[i].golsSofridos);
    }
}

void tabela(Time time[], int t) {
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
    
    for(int i = 0; i < t; i++) {
        int pontos = (time[i].vitorias * 3) + (time[i].empates);
        int jogos = time[i].vitorias + time[i].empates + time[i].derrotas;
        int saldoGols = time[i].golsFeitos - time[i].golsSofridos;

        printf("%s|%d|%d|%d|%d|%d|%d|%d|%d\n",
               time[i].nome, pontos, jogos, time[i].vitorias, time[i].empates, 
               time[i].derrotas, time[i].golsFeitos, time[i].golsSofridos, saldoGols);
    }
}

void bubbleSort(Time time[], int t) {
    for(int i = 0; i < t - 1; i++) {
        for(int j = 0; j < t - i - 1; j++) {
            int pontosA = (time[j].vitorias * 3) + (time[j].empates);
            int pontosB = (time[j + 1].vitorias * 3) + (time[j + 1].empates);
            int saldoGolsA = time[j].golsFeitos - time[j].golsSofridos;
            int saldoGolsB = time[j + 1].golsFeitos - time[j + 1].golsSofridos;

            if(pontosA < pontosB || 
               (pontosA == pontosB && time[j].vitorias < time[j + 1].vitorias) || 
               (pontosA == pontosB && time[j].vitorias == time[j + 1].vitorias && saldoGolsA < saldoGolsB)) {
                Time temp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = temp;
            }
        }
    }
}

void imprimirZonaLibertadores(Time time[], int t) {
    printf("\nTimes na zona da Libertadores:\n");
    for(int i = 0; i < 6 && i < t; i++) {
        printf("%s\n", time[i].nome);
    }
}

void imprimirZonaRebaixamento(Time time[], int t) {
    printf("\nTimes na zona de rebaixamento:\n");
    for(int i = t - 4; i <= t; i++) {
        int n=4;
        printf("%s\n", time[i+n].nome);
        n-=1;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    Time time[t];

    lerTimes(time, t);
    bubbleSort(time, t);
    tabela(time, t);
    imprimirZonaLibertadores(time, t);
    imprimirZonaRebaixamento(time, t);

    return 0;
}