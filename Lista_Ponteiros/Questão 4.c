#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int tam = 5; //Quantidade de strings iniciais a serem guardadas
    char **str = (char **) malloc(tam * sizeof(char*)); //Aloca a quantidade inicial de strings
    char buffer[100];
    int cont = 0;

    while(1){
        printf("Digite suas strings ou 'x' para sair:\n");
        scanf(" %[^\n]", buffer); //Guarda a string no buffer

        if(strcmp(buffer, "x") == 0){ //Se o buffer for digitado a opção de saída, o loop encerra
            break;
        }

        str[cont] = (char *)malloc((strlen(buffer) + 1) * sizeof(char)); //Aloca espaço pra guardar a string
        strcpy(str[cont], buffer); //Copia a string do buffer para a matriz

        cont++;

        if(cont == tam){ //Se chegar no tamanho máximo
            tam *= 2;
            str = (char **)realloc(str, tam * sizeof(char *)); //Dobra o tamanho da matriz, assim podendo armazenar mais strings
        }
    }

    printf("\t Strings armazenadas:\n");
    for(int i = 0; i < cont; i++){
        printf("%d: %s\n", i+1, str[i]);
    }

    for(int i = 0; i < cont; i++){
        free(str[i]);
    }
    free(str);

    return 0;
}