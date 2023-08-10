#include <stdio.h>

typedef struct{
    char Placa[6];
}Caminhao;

typedef struct{
    int codigo;
    float loc_x, loc_y;
    Caminhao *caminhao;
    int n_caminhao;
}Filial;

typedef struct{
    float origem_x, origem_y;
    float destino_x, destino_y;
}Produto;

int main(void){
    int valor;

    do{
    printf("\t MENU\n");
    printf("1: Cadastrar filial\n");
    printf("2: Cadasrar caminhao\n");
    printf("3: Realizar entrega\n");
    printf("4: Imprimir filiais\n");
    printf("5: Sair\n");

    scanf("%d", &valor);

    switch(valor){
        case 1:
            
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("Saindo...");
            valor = 5;
            break;
        }
    }while (valor != 5);

    return 0;
}
