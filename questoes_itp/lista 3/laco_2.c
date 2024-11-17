#include <stdio.h>
#include <math.h>
int main (){
    float tempoMin, tempoAtleta, qtdSeries;
    int atletasAptos;
    atletasAptos=0;
    //printf("tempo min: ");
    scanf("%f", &tempoMin);
    do{
        //printf("tempo atletas: ");
        scanf("%f", &tempoAtleta);
        if  (tempoAtleta==-1) break;
        if(tempoAtleta<=tempoMin){
            atletasAptos++;
        }
  
    }while(1);
    if (atletasAptos>8){
        qtdSeries=atletasAptos/8.0;
        qtdSeries=ceil(qtdSeries);   
    }else if(atletasAptos==0){
        qtdSeries=0;
    }
    else{
        qtdSeries=1;
    }
    printf("%d %0.f",  atletasAptos, qtdSeries);


}