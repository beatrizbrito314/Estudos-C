#include <stdio.h>
#include <string.h>

#define MAX_SMARTPHONES 100

typedef struct {
    char modelo[40];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qntCadastrada, Smartphone phones[], Smartphone novoSmartphone) {
    if (qntCadastrada < MAX_SMARTPHONES) {
        phones[qntCadastrada] = novoSmartphone;
        return qntCadastrada + 1;
    } 
}

int pesquisaSmartphones(int qntCadastrada, Smartphone phones[], Smartphone reqMin) {
    int qntEncontrados = 0;
    for (int i = 0; i < qntCadastrada; i++) {
        if (phones[i].memoria >= reqMin.memoria &&
            phones[i].processador >= reqMin.processador &&
            phones[i].camera >= reqMin.camera &&
            phones[i].bateria >= reqMin.bateria) {
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
            qntEncontrados++;
        }
    }
    return qntEncontrados;
}

int main() {
    Smartphone phones[MAX_SMARTPHONES];
    int qntCadastrada = 0;
    char resposta;
    Smartphone novoSmartphone;
    Smartphone reqMin;

    while (1) {
        scanf(" %c", &resposta);
        if (resposta == 's' || resposta == 'S') {
            scanf(" %[^\n]", novoSmartphone.modelo);
            scanf("%d", &novoSmartphone.memoria);
            scanf("%f", &novoSmartphone.processador);
            scanf("%f", &novoSmartphone.camera);
            scanf("%f", &novoSmartphone.bateria);
           
            qntCadastrada = cadastraSmartphone(qntCadastrada, phones, novoSmartphone);
        } else if (resposta == 'n' || resposta == 'N') {
            break;
        }
    }

    scanf("%d", &reqMin.memoria);
    scanf("%f", &reqMin.processador);
    scanf("%f", &reqMin.camera);
    scanf("%f", &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qntCadastrada, phones, reqMin);
    if (encontrados == 0) {
        printf("0 smartphones encontrados.\n");
    }else {
    printf("%d smartphones encontrados.\n", encontrados);
}

    return 0;
}