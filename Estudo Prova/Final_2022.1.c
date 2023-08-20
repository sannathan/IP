#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    unsigned char parte1;
    unsigned char parte2;
    unsigned char  emJogo;
}Peca;

Peca *inicializaPecasDomino(){
    Peca *pecas = (Peca *)malloc (28 * sizeof(Peca));
    int x = 0;

    if(pecas == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    for(int i = 0; i < 7; i++){
        for(int j = i; j < 7; j++){
            pecas[x].parte1 = i;
            pecas[x].parte2 = j;
            pecas[x].emJogo = 0;
            x++;
        }
    }
    return pecas;
}

char *pecasIndividuo(Peca *todasPecas){
    Peca *pecasJog = (Peca *)malloc (7 * sizeof(Peca));

    srand(time(NULL));
    if(pecasJog){
        for(int i = 0; i < 7; i++){
            int index = rand() % 28;
            pecasJog[i] = todasPecas[index];
            if(todasPecas[index].emJogo == 1){
                do{
                    index = rand() % 28;
                    pecasJog[i] = todasPecas[index];
                }while(todasPecas[index].emJogo != 0);
            }
            todasPecas[index].emJogo = 1;
        }
    }
    else{
        printf("Erro ao alocar memória");
        exit(1);
    }
    return pecasJog;
}

char *jogada(char pecaEscolhida, char extremidade, char *pecasJogador, char *tamPecasJog, Peca *todasPecas, char *Mesa, char *tamMesa){

    if(extremidade == 0){
        //Verifica se pode adicionar no começo da mesa
        if(todasPecas[pecaEscolhida].parte1 != Mesa[0] && todasPecas[pecaEscolhida].parte2 != Mesa[0]){
            printf("Jogada Inválida!");
            return pecasJogador;
        }
    }
    else{
        //Verifica se pode ser adicionado no final da mesa
        if(todasPecas[pecaEscolhida].parte1 != Mesa[*tamMesa - 1] && todasPecas[pecaEscolhida].parte2 != Mesa[*tamMesa - 1]){
            printf("Jogada Inválida!");
            return pecasJogador;
        }
    }

    int i;
    for(i = 0; i < *tamPecasJog; i++){
        if(pecasJogador[i] == pecaEscolhida){
            break;
        }
    }
    for(; i < *tamPecasJog - 1; i++){
        pecasJogador[i] = pecasJogador[i + 1];
    }
    (*tamPecasJog)--;

    if(extremidade == 0){
        for(i = *tamMesa; i > 0; i--){
            Mesa[i] = Mesa[i - 1];
        }
        Mesa[0] = pecaEscolhida;
    }
    else{
        Mesa[*tamMesa] = pecaEscolhida;
    }
    (*tamMesa)++;

    return pecasJogador;
}

int main(void){
    unsigned char pecaEscolhida, tamMesa;
    char extremidade, Mesa, pecasJogador, tamPecasJog = 7;
    Peca *todasPecas = inicializaPecasDomino();

    Peca *jogador1 = pecasIndividuo(todasPecas);
    Peca *jogador2 = pecasIndividuo(todasPecas);

    int escolha = 0;

    printf("Qual jogador irá iniciar a partida?: 1 - 1° Primeiro jogador\n 2 - 2° Jogador\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        for(int i = 0; i < 7; i++){
            printf("%d°: %d | %d\n", i, jogador1[i].parte1, jogador1[i].parte2);
        }

        if(tamMesa == 0){
            printf("Qual peça deseja jogar?");
            scanf("%d", &pecaEscolhida);
        }
        else{
            printf("Qual peça e extremidade deseja jogar?\n1- Para o final da mesa\n0- Para o inicio da mesa\n");
            scanf("%d %c", &pecaEscolhida, &extremidade);
        }
        
        jogador1 = jogada(pecaEscolhida, extremidade, &pecasJogador, &tamPecasJog, todasPecas, &Mesa, &tamMesa);
        

        break;
    
    case 2:

        break;
    default:
        break;
    }


    return 0;
}