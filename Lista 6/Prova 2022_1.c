#include <stdio.h>
#include <string.h>

typedef struct{
    char produto[100];
    float valor;
    int quantidade;
}compra;

void InserirCompra(compra **lista, int *tamLista){
    *lista = (compra *)realloc(*lista, (*tamLista+1) * sizeof(compra));
    scanf("%s %f %d", (*lista)[*tamLista].produto, &(*lista)[*tamLista].valor, &(*lista)[*tamLista].quantidade);
    (*tamLista)++;
}
void removerCompra(compra **lista, int *tamLista){
    char produto[50];
    int qtd_remover;
    scanf("%s %d", produto, &qtd_remover);

    for(int i = 0; i < *tamLista; i++){
        if(strcmp((*lista)[i].produto, produto) == 0){
            (*lista)[i].quantidade = (*lista)[i].quantidade - qtd_remover;

            if((*lista)[i].quantidade <= 0){
                (*lista)[i] = (*lista)[*tamLista - 1];
                *lista = (compra *)realloc(*lista)
            }
        }
    }
}
void removerGrupoCompra(compra **lista, int *tamLista){

}
void consultarLista(compra *lista, int tamLista){
    float valor = 0;
    for(int i = 0; i < tamLista; i++){
        valor = valor + (lista[i].valor * lista[i].quantidade);
    }
    printf("Atualmente a lista esta em R$%.1f\n\n", valor);
}
void PorcurarCompra(compra *lista, int tamLista){
    char palavra[30];
    scanf("%s", palavra);

    if(tamLista == 0){
        printf("%s nao foi encontrado. \n\n", palavra);
        return;
    }

    for(int i = 0; i < tamLista; i++){
        if(strcmp(lista[i].produto, palavra) == 0){
            printf("%s\n - %.1f\n")
        }
    }
}

int main(void){
    compra *lista = NULL;
    int tamLista = 0;
    char funcao[50];

    while(scanf(" %s", funcao) != EOF){
        if(strcmp(funcao, "INSERIR") == 0){

        }
        else if(strcmp(funcao, "REMOVER") == 0){

        }
        else if(strcmp(funcao, "REMOVERGRUPO") == 0){

        }
        else if(strcmp(funcao, "CONSULTAR") == 0){

        }
        else if(strcmp(funcao, "PROCURAR") == 0){

        }
    } 

    free(lista);
    return 0;
}