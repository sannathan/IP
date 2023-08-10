#include <stdio.h>

void MenorInt(int *vet){
    int cache;
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            if(vet[j] < vet[i]){
                cache = vet[j];
                vet[j] = vet[i];
                vet[i] = cache;
            }
        }
    }   
}
void MaiorInt(int *vet){
    int cache;
    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 5; j++){
            if(vet[j] > vet[i]){
                cache = vet[j];
                vet[j] = vet[i];
                vet[i] = cache;
            }
        }
    }
}
int main(void){
    int vet[6];

    for(int i = 0; i < 6; i++){
        scanf("%d", &vet[i]);
    }

    MenorInt(&vet);
    printf("O menor valor eh: %d\n", vet[0]);
    MaiorInt(&vet);
    printf("O maior valor eh: %d\n", vet[5]);




    return 0;
}