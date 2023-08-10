#include <stdio.h>

int main(void){
    FILE *arq;

    arq = fopen("teste.txt", "at");

    if(arq == NULL){
        printf("Deu erro manehJH");
    }
    fprintf(arq, "%s\n", "Alexandre e Mota");
    printf("Deu tudo certo");
    fclose(arq);


    return 0;
}