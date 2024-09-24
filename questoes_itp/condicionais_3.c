#include <stdio.h>
int main ( ){
    int cod, qtd, valor;
    scanf("%d  %d",&cod, &qtd);
    if (cod == 1){
        if (qtd==12){
            printf("Deu certim!");
        }else if(qtd>12){
            valor=qtd-12;
            printf("Troco= %d reais",valor);
        }else if(qtd<12){
            valor=12-qtd;
            printf("Saldo insuficiente! Falta %d reais",valor);
        }}

        if (cod == 2){
        if (qtd==23){
            printf("Deu certim!");
        }else if(qtd>23){
            valor=qtd-23;
            printf("Troco= %d reais",valor);
        }else if(qtd<23){
            valor=23-qtd;
            printf("Saldo insuficiente! Falta %d reais",valor);
        }}

         if (cod == 3){
        if (qtd==31){
            printf("Deu certim!");
        }else if(qtd>31){
            valor=qtd-31;
            printf("Troco= %d reais",valor);
        }else if(qtd<31){
            valor=31-qtd;
            printf("Saldo insuficiente! Falta %d reais",valor);
        }}

         if (cod == 4){
        if (qtd==28){
            printf("Deu certim!");
        }else if(qtd>28){
            valor=qtd-28;
            printf("Troco= %d reais",valor);
        }else if(qtd<28){
            valor=28-qtd;
            printf("Saldo insuficiente! Falta %d reais",valor);
        }}

         if (cod == 5){
        if (qtd==15){
            printf("Deu certim!");
        }else if(qtd>15){
            valor=qtd-15;
            printf("Troco= %d reais",valor);
        }else if(qtd<15){
            valor=15-qtd;
            printf("Saldo insuficiente! Falta %d reais",valor);
        }}



    return 0;
}