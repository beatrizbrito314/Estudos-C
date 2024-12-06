#include <stdio.h>
#include <string.h>

int main() {
    int n1, n2;
    char pref[100][11]; 
    char suf[100][11];  
    char palavra[101];      
    char palavrasProcessadas[100][101];
    int count = 0;

    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        scanf("%s", pref[i]);
    }

  
    scanf("%d", &n2);
   
    for (int i = 0; i < n2; i++) {
        scanf("%s", suf[i]);
    }

    
    while (1) {
        palavra[0] = '\0';  
        scanf("%s", palavra);
        if (strcmp(palavra, "-1") == 0) { 
            break;
        }

        
        for (int i = 0; i < n1; i++) {
            int tamPref = strlen(pref[i]);
            if (strncmp(palavra, pref[i], tamPref) == 0) {
                strcpy(palavra, palavra + tamPref);
                break;
            }
        }

     
        for (int i = 0; i < n2; i++) {
            int tamSuf = strlen(suf[i]);
            int tamPalavra = strlen(palavra);
            if (tamPalavra >= tamSuf && strcmp(palavra + tamPalavra - tamSuf, suf[i]) == 0) {
                palavra[tamPalavra - tamSuf] = '\0';
                break;
            }
        }

        
        if (strlen(palavra) > 0 && count < 100) { strcpy(palavrasProcessadas[count], palavra);
            count++;
        }
    }

   
    for (int i = 0; i < count; i++) {
        printf("%s\n", palavrasProcessadas[i]);
    }

    return 0;
}