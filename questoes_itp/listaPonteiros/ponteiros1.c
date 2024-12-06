#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted) {
    int max1 = 0, max2 = 0;
    int cnt[10] = {0};

   
    for (int i = 0; i < n; i++) {
        if (votes[i] > 0 && votes[i] <= 10) {
            cnt[votes[i] - 1]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] > max1) {
            max2 = max1; 
            max1 = cnt[i];
            *second_most_voted = *most_voted; 
            *most_voted = i + 1; 
        } else if (cnt[i] > max2 && cnt[i] != max1) {
            max2 = cnt[i];
            *second_most_voted = i + 1; 
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int votos[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &votos[i]);
    }

    int maisVotado = 0;
    int segundoMaisVotado = 0;

    compute_votes(n, votos, &maisVotado, &segundoMaisVotado);

    printf("%d %d\n", maisVotado, segundoMaisVotado);

    return 0;
}