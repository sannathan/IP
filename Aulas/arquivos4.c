#include <stdio.h>

int main(void){
    FILE *arq;
    arq = fopen("teste.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir arquivo");
        return 0;
    }

    char frase[100];

    while(fgets(frase, 100, arq) != NULL){
        printf("%s", frase);
    }
    fclose(arq);
    
    return 0;
}