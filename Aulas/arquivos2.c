#include <stdio.h>

int main(void){
    FILE *arq;
    arq = fopen("teste.txt", "wt");
    fprintf(arq, "Ainnnnnnnnnnnnn ze da manga");
    fclose(arq);
    return 0;
}