#include <stdio.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

int main(void){
    Contato c;
    FILE *arq = fopen("teste2.bin", "rb");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    fread(&c, sizeof(Contato), 2, arq);
    printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);





    return 0;
}