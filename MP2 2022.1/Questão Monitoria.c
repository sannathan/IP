#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 100000000000

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

Caminhao remover_caminhao(Filial *filiais, int codigo_filial){
    Caminhao remov;
    strcpy(remov.Placa , filiais[codigo_filial].caminhao->Placa);
    filiais[codigo_filial].caminhao = (Caminhao *)realloc(filiais[codigo_filial].caminhao, (filiais[codigo_filial].caminhao - 1) * sizeof(Caminhao));
    filiais[codigo_filial].n_caminhao -= 1;
    return remov;
}

Filial *cadastrar_filial(Filial *filiais, int *n_filiais){
    int loc_x, loc_y;

    Filial *tmp = filiais; //Ponteiro temporario para caso o ponteiro principal der ruim, liberar a memória por ele
    filiais = (Filial *)realloc(filiais, (*n_filiais + 1) * (sizeof(Filial)));

    if(filiais == NULL){
        printf("Erro ao alocar memória\n");
        for(int i = 0; i < *n_filiais; i++){
            free(tmp[i].caminhao);
        }
        free(tmp);
        exit(1);
    }

    printf("Digite a coordenada x da sua filial:\n");
    scanf("%d", &loc_x);
    printf("Digite a coordenada y da sua filial:\n");
    scanf("%d", &loc_y);

    printf("Filial Cadastrada com sucesso!\n");
    filiais->codigo = *n_filiais;
    filiais->loc_x = loc_x;
    filiais->loc_y = loc_y;
    filiais->caminhao = NULL;
    filiais->n_caminhao = 0;
    (*n_filiais)++;

    return filiais;
}

void cadastrar_caminhao(Filial *filiais, Caminhao caminhao, int codigo_filial){
    char buffer[6];
    printf("Digite a placa do caminhao:\n");
    scanf(" %5[^\n]", buffer);

    strcpy(caminhao.Placa, buffer);

    Caminhao *tmp = filiais[codigo_filial].caminhao;
    filiais[codigo_filial].caminhao = (Caminhao *)realloc(filiais[codigo_filial].caminhao, (filiais[codigo_filial].n_caminhao + 1) * sizeof(Caminhao));

    if(filiais[codigo_filial].caminhao == NULL){
        printf("Erro ao alocar memória\n");
        free(tmp);
        exit(1);
    }
    filiais[codigo_filial].caminhao[filiais[codigo_filial].n_caminhao] = caminhao;    
    filiais[codigo_filial].n_caminhao++;
    printf("Caminhao adicionado com sucesso!\n");
}

void realizar_entrega(Filial *filiais, Produto produto, int n_filiais){
    float DistOrigem, DistDestino;
    float minOrigem = max, minDestino = max;
    int indexOrigem = 0, indexDestino = 0;

    for(int i = 0; i < n_filiais; i++){
        DistOrigem = sqrt(pow(produto.origem_x - filiais[i].loc_x, 2) + pow(produto.origem_y - filiais[i].loc_y, 2));

        if(DistOrigem < minOrigem){
            minOrigem = DistOrigem;
            indexOrigem = i;
        }

        DistDestino = sqrt(pow(produto.destino_x -filiais[i].loc_y, 2) + pow(produto.origem_y - filiais[i].loc_y, 2));

        if(DistDestino < minDestino){
            minDestino = DistOrigem;
            indexDestino = i;
        }
    }

    Caminhao adicionar = remover_caminhao(filiais, indexOrigem);
    cadastrar_caminhao(filiais, adicionar, indexDestino);
}

void imprimir_filiais(Filial *filiais, int n_filiais){

}

int main(void){
    int valor, n_filiais = 0, codigo_filial = 0;
    Produto produto;
    Filial *filiais = NULL;
    Caminhao caminhao;

    do{
    printf("\t MENU\n");
    printf("1: Cadastrar filial\n");
    printf("2: Cadastrar caminhao\n");
    printf("3: Realizar entrega\n");
    printf("4: Imprimir filiais\n");
    printf("5: Sair\n");

    scanf("%d", &valor);

    switch(valor){
        case 1:
            filiais = cadastrar_filial(filiais, &n_filiais);
            break;
        case 2:
            printf("Digite o codigo da filial: ");
            scanf("%d", &codigo_filial);
            cadastrar_caminhao(filiais, caminhao, codigo_filial);
            break;
        case 3:
            printf("Digite as coordenadas x e y de origem do produto:\n");
            scanf("%d %d", produto.origem_x, produto.origem_y);
            printf("Digite as coordenadas x e y de destino do produto:\n");
            scanf("%d %d", produto.destino_x, produto.destino_y);
            realizar_entrega(filiais, produto, n_filiais);
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
