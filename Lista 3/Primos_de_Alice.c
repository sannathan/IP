#include <stdio.h>

int main(void) {
    int n = 0, i, j, ehprimo;

    scanf("%d", &n);

    int matriz[n][n], num, vet[n * n];
    int indice = 1;

    for (i = 0; i < n * n; i++) {
        vet[i] = -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            num = matriz[i][j];
            ehprimo = 1;

            for (int q = 2; q * q <= num; q++) {
                if (num % q == 0) {
                    ehprimo = 0;
                    break;
                }
            }

            if (ehprimo) {
                vet[indice] = num;
                indice++;
            }
        }
    }

    int cache;
    for(i = 1; i < indice; i++){
        for(j = 0; j < indice; j++){
            if(vet[j] > vet[j + 1]){
                cache = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = cache;
            }
        }
    }

    for(int x = 0; x < indice; x++){
        printf("%d ", vet[x]);
    }

    return 0;
}
