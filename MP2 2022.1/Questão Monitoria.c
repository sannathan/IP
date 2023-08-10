#include <stdio.h>

typedef struct{
    char placa[6];
}Caminhao;

typedef struct{

};

Caminhao remover_caminhao(Filial *filiais, int codigo_filial){
    Caminhao removido;
    if(filiais[codigo_filial].n_caminhao == 0){
        printf("Nao ha caminhoes nessa filial!\n")
    }
}


int main(void){
    int escolha = -1, qtdfiliais = 0;
    FILIAL *filial = NULL;



    return 0;
}