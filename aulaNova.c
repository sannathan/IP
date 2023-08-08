#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *arq;
    float vet[4];
    arq = fopen("test.bin", "r");

    if(arq == NULL)
        exit(1);
    fseek(arq, 2 * sizeof(float), SEEK_SET);
    fread(&vet[2], sizeof(float), 1, arq);
    for(int i = 0; i < 4; i++)
        printf("vet[%d]=%f\n", i+1, vet[i]);
    fclose(arq);
    return 0;
}