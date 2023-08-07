#include <stdio.h>

int main(void){
    FILE *arq;

    arq = fopen("teste.txt", "wt");

    if(arq == NULL){
        printf("Deu erro maneh");
    }

    fclose(arq);


    return 0;
}