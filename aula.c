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
    int *x, *y; //x ja seria um ponteiro
    x = atribuicao(10, NULL, 5); // \forall i:0..4 @ x[i] = 10;
    y = atribuicao(10, x, 5);
    for(int i = 0; i < 5; i++)
        printf
    for(int i = 0; i < 5; i++)
        printf("x[%d] = %d\n", i+1, x[i]);
    return 0;
}