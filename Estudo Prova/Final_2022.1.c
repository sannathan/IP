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
            int index;
            do{
                index = rand() % 28;
            }while(todasPecas[index].emJogo != 0);
            pecasJog[i] = todasPecas[index];
            todasPecas[index].emJogo = 1;
        }
    }
    else{
        printf("Erro ao alocar memória");
        exit(1);
    }
    return pecasJog;
}

char *jogada(char pecaEscolhida, char extremidade, Peca *pecasJogador, char *tamPecasJog, Peca *todasPecas, char *Mesa, char *tamMesa){

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

void mostraPecas(char *pecasJogador){
    printf("Pecas: ");
    for(int i = 0; pecasJogador[i] != '\0'; i+= 2){
        printf("%c:%c ", pecasJogador[i], pecasJogador[i+1]);
    }
    printf("\n");
}

unsigned char pontuacao(Peca *pecaJogador, char *tamPecasJog){
    unsigned char somatorio[7];
    for(int i = 0; i < *tamPecasJog; i++){
        somatorio[i] = pecaJogador[i].parte1 + pecaJogador[i].parte2;
    }
    return somatorio;
}

void mostraMesa(char *mesa){
    printf("Mesa: ");
    for(int i = 0; mesa[i] != '\0'; i += 2){
        printf("%c:%c ", mesa[i], mesa[i+1]);
    }
    printf("\n");
}

int main(void){
    int inicio = 1;
    unsigned char pecaEscolhida, tamMesa;
    char extremidade, Mesa, tamPecasJog1 = 7, tamPecasJog2 = 7,opt = 'S';
    Peca *todasPecas = inicializaPecasDomino();

    Peca *jogador1 = pecasIndividuo(todasPecas);
    Peca *jogador2 = pecasIndividuo(todasPecas);

    int escolha = 0;

    while(opt == 'S' || opt == 's'){

    
        do{

        if(inicio){
            printf("Qual jogador irá iniciar a partida?: 1 - 1° Primeiro jogador\n 2 - 2° Jogador\n");
            scanf("%d", &escolha);
            inicio++;    
        }
        else{
            if(escolha == 1){
                escolha = 2;
            }
            else{
                escolha = 1;
            }
        }

        switch (escolha)
        {
        case 1:
        if(tamPecasJog1 != 0){
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
            
            jogador1 = jogada(pecaEscolhida, extremidade, jogador1, &tamPecasJog1, todasPecas, &Mesa, &tamMesa);
            
            mostraMesa(&Mesa);
            break;
        }
        else{
            printf("Jogador 1 foi o vencedor da partida!");
            break;
        }
            
        case 2:
        if(tamPecasJog2 != 0){
            for(int i = 0; i < 7; i++){
                printf("%d°: %d | %d\n", i, jogador2[i].parte1, jogador2[i].parte2);
            }

            if(tamMesa == 0){
                printf("Qual peça deseja jogar?");
                scanf("%d", &pecaEscolhida);
            }
            else{
                printf("Qual peça e extremidade deseja jogar?\n1- Para o final da mesa\n0- Para o inicio da mesa\n");
                scanf("%d %c", &pecaEscolhida, &extremidade);
            }
                    
            jogador2 = jogada(pecaEscolhida, extremidade, jogador2, &tamPecasJog2, todasPecas, &Mesa, &tamMesa);
                    
            mostraMesa(&Mesa);
            break;
        }
        else{
            printf("Jogador 2 foi o vencedor!");
            break;
        }
        
        default:
        printf("Número inválido!");
            break;
        }

        }while(tamPecasJog1 != 0 || tamPecasJog2 != 0 || );

    printf("Deseja jogar novamente?:\nDigite S para sim e N para encerrar");
    scanf("%c", &opt);
    }
    return 0;
}