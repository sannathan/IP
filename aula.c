#include <stdio.h>

int *atribuicao(int valor, int tam){
    int *var = (int *) malloc(tam *sizeof(int));
    if(var == NULL){
        printf("Problema aloc em atrib\n");
        exit(1);
    }
    for(int i = 0; i < tam; i++)
        var[i] =  valor;
        return var;
}

int main(void){
    int *x[5]; //x ja seria um ponteiro
    x = atribuicao(10, 5); // \forall i:0..4 @ x[i] = 10;
    for(int i = 0; i < 5; i++)
        printf("x[%d] = %d\n", i+1, x[i]);
    return 0;
}