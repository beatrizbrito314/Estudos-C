#include <stdio.h>

int main() {
    int n, i, j, troca, temp;

    scanf("%d", &n);

    int arr[n];
    int original[n]; 

    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        original[i] = arr[i]; 
    }

    for (i = 0; i < n; i++) {
        printf("%d", original[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    troca = 1;
    while (troca) {
        troca = 0;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                troca = 1;
            }
        }

        if (troca) {
            for (j = 0; j < n; j++) {
                printf("%d", arr[j]);
                if (j < n - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}