#include <stdio.h>
#include <string.h>

void verifica(int *necessidade) {
    if (*necessidade > 100) {
        *necessidade = 100;
    } else if (*necessidade < 0) {
        *necessidade = 0;
    }
}

int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio) {
    char acao[20];
    fgets(acao, 20, stdin); 
    acao[strcspn(acao, "\n")] = 0; 


    if (strcmp(acao, "comer") == 0) {
        *fome += 30;
        *banheiro -= 15;
        //afetados indretamente
        *sono -= 5;
        *tedio -= 5;
        *sede -= 5;
        
    } else if (strcmp(acao, "beber") == 0) {
        *sede += 30;
        *banheiro -= 20;
        //afetados indretamente
        *sono -= 5;
        *tedio -= 5;
        *fome -= 5;
    } else if (strcmp(acao, "dormir") == 0) {
        *sono += 80;
        *tedio += 30;
        *fome -= 30;
        *sede -= 30;
        *banheiro -= 30;
    } else if (strcmp(acao, "se aliviar") == 0) {
        *banheiro = 100;
        //afetados indretamente
        *sono -= 5;
        *tedio -= 5;
        *sede -= 5;
        *fome -= 5;
    } else if (strcmp(acao, "jogar videogame") == 0) {
        *tedio += 80;
        *fome -= 20;
        *sede -= 20;
        *banheiro -= 20;
        *sono -= 20;
    }


    verifica(fome);
    verifica(sede);
    verifica(banheiro);
    verifica(sono);
    verifica(tedio);
    
    if (*fome <= 0) {
        printf("Game Over! Morreu de fome\n");
        return 0;
    }
    if (*sede <= 0) {
        printf("Game Over! Morreu de sede\n");
        return 0;
    }
    if (*banheiro <= 0) {
        printf("Game Over! Morreu apertado...\n");
        return 0;
    }
    if (*sono <= 0) {
        printf("Game Over! Morreu dormindo...\n");
        return 0;
    }
    if (*tedio <= 0) {
        printf("Game Over! Morreu deprimido...\n");
        return 0;
    }

    

    if (*fome > 0 && *fome <= 15) printf("Alerta: fome está com valor baixo\n");
    if (*sede > 0 && *sede <= 15) printf("Alerta: sede está com valor baixo\n");
    if (*banheiro > 0 && *banheiro <= 15) printf("Alerta: banheiro está com valor baixo\n");
    if (*sono > 0 && *sono <= 15) printf("Alerta: sono está com valor baixo\n");
    if (*tedio > 0 && *tedio <= 15) printf("Alerta: tédio está com valor baixo\n");
return 1; 
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio) {
    printf("Status final:\n");
    printf("Fome: %d\n", fome);
    printf("Sede: %d\n", sede);
    printf("Banheiro: %d\n", banheiro);
    printf("Sono: %d\n", sono);
    printf("Tédio: %d\n", tedio);
}


int main(){
    //armazena o valor de cada necessidade
    int fome, sede, banheiro, sono, tedio;
    int acoes; //ações que o sim realiza para atender a necessidade
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d ", &acoes);
    for(int i=0;i<acoes;i++){
        int ret= simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret==0){break;}
    }
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}