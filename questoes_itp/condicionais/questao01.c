#include <stdio.h>

int main() {
    int l; 
    scanf("%d", &l);
    int c[l]; 

    
    for (int k = 0; k < l; k++) {
        scanf("%d", &c[k]);
    }


    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c[i]; j++) { 
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}