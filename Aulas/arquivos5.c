#include <stdio.h>

int main(void){
    FILE *arq;
    arq = fopen("teste.txt", "at");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return 0;
    }

    fprintf(arq, "Adicionar a segunda linhaaa\n");

    char frase[] = "Enésima linha";
    fputs(frase, arq);

    char caractere =  '3';
    fputc(caractere, arq);

    fclose(arq);
    return 0;
}