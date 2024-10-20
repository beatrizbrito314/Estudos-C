#include <stdio.h>
/*int classificacao() {




}*/
int main () {
    int l, h, i, j, countVegetacao, countAgua, countRecursos, countDeserto, countEspecies, elementosTotal;
    countVegetacao=countAgua=countRecursos=countDeserto=countEspecies=0;
    float porcentagemAgua, porcentagemDeserto, porcentagemVegetacao;
    printf("insira a largura:");
    scanf("%d", &l);
    printf("insira a altura:");
    scanf("%d", &h);
    //matriz do scaner
    char composicaoPlaneta [l][h];
    //inserindo os dados na matriz
    for ( i=0; i<l; i++ )
        for ( j=0; j<h; j++ )
            {
                scanf (" %c", &composicaoPlaneta[ i ][ j ]);
            }
         // imprimindo a matriz e contando os elementos
    for (i = 0; i < l; i++) {
        for (j = 0; j < h; j++) {
            printf("%c ", composicaoPlaneta[i][j]);
            if (composicaoPlaneta[i][j] == '~') {
                countAgua++;
            } else if (composicaoPlaneta[i][j] == 'X') {
                countEspecies++;
            } else if (composicaoPlaneta[i][j] == '^') {
                countDeserto++;
            } else if (composicaoPlaneta[i][j] == '*') {
                countVegetacao++;
            } else if (composicaoPlaneta[i][j] == '.') {
                countRecursos++;
            }
        }
        printf("\n");
    }
    elementosTotal=countAgua+countDeserto+countEspecies+countRecursos+countVegetacao;
    porcentagemAgua= (countAgua/elementosTotal * 100);
    porcentagemDeserto= (countDeserto/elementosTotal * 100);
    porcentagemVegetacao= (countVegetacao/elementosTotal * 100);
elementosTotal = countAgua + countDeserto + countEspecies + countRecursos + countVegetacao;
//porcentagem dos elementos
    porcentagemAgua = ((float)countAgua / elementosTotal) * 100;
    porcentagemDeserto = ((float)countDeserto / elementosTotal) * 100;
    porcentagemVegetacao = ((float)countVegetacao / elementosTotal) * 100;
//classificacao do planeta 
   if (countEspecies >= 1) {
    printf("Planeta Hostil\n");
} else if (porcentagemAgua >= 84.5 && porcentagemAgua <= 85.5) {
    printf("Planeta Aquático \n");
} else if (porcentagemDeserto >= 59.5 && porcentagemDeserto <= 60.5) {
    printf("Planeta Desértico\n");
} else if (porcentagemVegetacao >= 64.5 && porcentagemVegetacao <= 65.5) {
    printf("Planeta Selvagem\n");
} else if (porcentagemAgua >= 50 && porcentagemVegetacao >= 20) {
    printf("Planeta Classe M\n");
} else {
    printf("Planeta Inóspito\n");
}
    return 0;
}