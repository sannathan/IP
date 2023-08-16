#include <stdio.h>

int main(void){
    FILE *arq;
    char frase[100];
    arq = fopen("teste.txt", "rt");

    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 0;
    }

    fscanf(arq, "%99[^\n]", frase);
    printf("%s", frase);

    fclose(arq);
    return 0;
}