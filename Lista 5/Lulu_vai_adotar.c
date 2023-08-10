#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} LULU;

int main(void) {
    int n, m, x, temp;
    float tamNom;
    scanf("%d %d %d", &n, &m, &x);

    LULU rgs[n];
    float dif[n];
    char cache[100]; // Correção: cache é um array de arrays de caracteres
    for (int i = 0; i < n; i++) {
        scanf("%s %d %f", rgs[i].nome, &rgs[i].idade, &rgs[i].altura);
        tamNom = strlen(rgs[i].nome);
        dif[i] = x - (rgs[i].altura * rgs[i].idade * tamNom);
        if(dif[i] < 0){
            dif[i] *= -1;
        }
    }

    for (int j = 0; j < n - 1; j++) {
        for(int k = 0; k < n - j - 1; k++){
            if (dif[k] > dif[k + 1]) {
                temp = dif[k];
                dif[k] = dif[k+1];
                dif[k+1] = temp;
                strcpy(cache, rgs[k].nome); // Correção: copiar para cache[j]
                strcpy(rgs[k].nome, rgs[k + 1].nome);
                strcpy(rgs[k + 1].nome, cache);
            }
        }
    }

    for (int k = 0; k < m; k++) {
        printf("%s\n", rgs[k].nome);
    }

    return 0;
}
