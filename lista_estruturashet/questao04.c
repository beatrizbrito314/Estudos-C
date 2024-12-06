#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} smartphone;

typedef struct {
    int memoReq;
    float proReq;
    float camReq;
    float bateReq;
} requisitos;

int cadastraSmartphone(int qtd_cadastrada, smartphone phones[]) {
    smartphone novo;
    scanf(" %s[^\n]", novo.modelo);
    

    scanf("%d", &novo.memoria);
    
    scanf("%f", &novo.processador);
    
    scanf("%f", &novo.camera);
    
    // Bateria
    scanf("%f", &novo.bateria);

    phones[qtd_cadastrada] = novo;
    qtd_cadastrada += 1; // Incrementa a quantidade cadastrada
    return qtd_cadastrada;
}

int pesquisaSmartphones(int qtd_cadastrada, smartphone phones[], requisitos reqMin) {
    int encontrados = 0;
   
    for (int i = 0; i < qtd_cadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoReq &&
            phones[i].processador >= reqMin.proReq &&
            phones[i].camera >= reqMin.camReq &&
            phones[i].bateria >= reqMin.bateReq) {
            printf("Modelo: %s", phones[i].modelo);
            printf("\n");
            printf(" Memoria: %d GB", phones[i].memoria);
            printf("\n");
            printf(" Processador: %.2f GHz", phones[i].processador);
            printf("\n");
            printf(" Camera: %.2fPixels", phones[i].camera);
            printf("\n");
            printf(" Bateria: %.2fmA", phones[i].bateria);
            printf("\n");
            encontrados++;
        }
    }
    return encontrados;
}

int main() {
    smartphone phones[50]; 
    int qtd = 0; 
    
    char solicita[2];
    do {
        scanf("%s", solicita);
        
        if (strcmp(solicita, "s") == 0) {
            qtd = cadastraSmartphone(qtd, phones);
        } else if (strcmp(solicita, "n") == 0) {
            break; 
        }
    } while (1); 

    requisitos novoReq;
    scanf("%d", &novoReq.memoReq);
    scanf("%f", &novoReq.proReq);
    scanf("%f", &novoReq.camReq);
    scanf("%f", &novoReq.bateReq);
    int encontrados = pesquisaSmartphones(qtd, phones, novoReq);
    printf("%d\n", encontrados);

    return 0;
}