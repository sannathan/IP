#include <stdio.h>

int *inicializa(int valor, int tam){
    int *var = (int *) malloc(tam * sizeof(int));
    if(var == NULL)
        exit(1);
    for(int i = 0; i < tam; i++)
        var[i] = valor;
    return var;
}

int main(void){
    printf("Mim de papai");
    return 0;
}