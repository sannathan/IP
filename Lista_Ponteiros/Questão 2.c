#include <stdio.h>

int main(void){
    int vet[5] = {1,2,3,4,5};
    int *p = &vet;

    printf("Endereço em vet :%d e endereço guardado em p: %d\n", &(*vet), &(*p));
    for(int i = 0; i < 5; i++){
        printf("Valores do vet usando p[]: %d\n", p[i]);
    }
    for(int j = 0; j < 5; j++){
        //printf("Valores do vet usando p*: %d\n", *p);
        //(*p)++;
    }
    for(int k = 0; k < 5; k++){
        printf("Valores de vet usando vet[]: %d\n", vet[k]);
    }
    for(int l = 0; l < 5; l++){
        printf("Valores de vet usando *vet: %d\n", *vet);
        (*vet)++;
    }

    return 0;
}