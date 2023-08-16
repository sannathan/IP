#include <stdio.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

int main(void){
    FILE *arq;
    arq = fopen("teste2.bin", "ab");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo");
        return 0;
    }

    Contato pessoa;
    printf("Digite o nome e a data de nascimento dd/mm/aaaa:\n ");
    scanf(" %49[^\n] %d %d %d", pessoa.nome, &pessoa.dia, &pessoa.mes, &pessoa.ano);

    fwrite(&pessoa, sizeof(Contato), 1, arq);
    fclose(arq);
    return 0;
}