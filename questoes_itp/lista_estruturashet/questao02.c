#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int golsMarcados;
    int golsSofridos;
} Time;

void lerTimes(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do time: ");
        fgets(times[i].nome, sizeof(times[i].nome), stdin); 
        times[i].nome[strcspn(times[i].nome, "\n")] = 0; 

        printf("Digite os gols marcados: ");
        scanf("%d", &times[i].golsMarcados);
        printf("Digite os gols sofridos: ");
        scanf("%d", &times[i].golsSofridos);
        getchar(); 
    }
}

void bubbleSort(Time times[], int n) {
    Time temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (times[j].golsMarcados < times[j + 1].golsMarcados) {                
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
            }
        }
    }
}

void exibirTimes(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].golsMarcados);
        printf("Gols sofridos: %d\n", times[i].golsSofridos);
        printf("\n"); 
    }
}

int main() {
    int n;

  
    scanf("%d", &n);
    getchar(); 

    Time times[n]; 

    lerTimes(times, n); 
    bubbleSort(times, n); 
    exibirTimes(times, n); 
    return 0;
}