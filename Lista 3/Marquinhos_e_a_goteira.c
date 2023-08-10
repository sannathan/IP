#include <stdio.h>

int main(void){
    int altura, largura, n = 1;

    scanf("%d %d", &altura, &largura);

    char parede[altura][largura];

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            scanf(" %c", &parede[i][j]);
        }
    }

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            if(parede[i][j] == 'o' && parede[i+1][j] == '.' && i+1 < altura){
                parede[i+1][j] = 'o';
            }
            else if(parede[i][j] == 'o' && parede[i+1][j] == '#' && i+1 < altura && j - 1 >= 0){
                parede[i][j - 1] = 'o';
                if(parede[i][j - 1] == 'o' && parede[i+1][j - 1] == '#' && i+1 < altura && j - 2 >= 0 && j - 1 >= 1){
                    parede[i][j - 2] = 'o';
                    if(parede[i][j-2] == 'o' && parede[i+1][j - 2] == '#' && i+1 < altura && j - 3 >= 0 && j - 2 >= 1){
                        parede[i][j - 3] = 'o';
                        if(parede[i][j-3] == 'o' && parede[i+1][j - 3] == '#' && i+1 < altura && j - 4 >= 0 && j - 3 >= 1){
                            parede[i][j - 4] = 'o';
                            if(parede[i][j-4] == 'o' && parede[i+1][j - 4] == '#' && i+1 < altura && j - 5 >= 0 && j - 4 >= 1){
                                parede[i][j - 5] = 'o';
                                if(parede[i][j-5] == 'o' && parede[i+1][j - 5] == '#' && i+1 < altura && j - 6 >= 0 && j - 5 >= 1){
                                    parede[i][j - 6] = 'o';
                                }
                            }
                        }
                    }
                }

                if(parede[i][j] == 'o' && parede[i+1][j] == '#' && i+1 < altura && j + 1 >= largura){
                    parede[i][j + 1] = 'o';
                    if(parede[i][j + 1] == 'o' && parede[i+1][j + 1] == '#' && i+1 < altura && j + 2 < largura && j + 1 < largura-1){
                        parede[i][j + 2] = 'o';
                }
            }
            else if(){
                
                if(parede[i][j + 1] == 'o' && parede[i+1][j + 1] == '#' && i+1 < altura && j + 2 < largura && j + 1 < largura-1){
                    parede[i][j + 2] = 'o';
                    if(parede[i][j + 2] == 'o' && parede[i+1][j + 2] == '#' && i+1 < altura && j + 3 < largura && j + 2 < largura - 1){
                        parede[i][j + 3] = 'o';
                        if(parede[i][j + 3] == 'o' && parede[i+1][j + 3] == '#' && i+1 < altura && j + 4 < largura && j - 3 >= 1){
                            parede[i][j + 4] = 'o';
                            if(parede[i][j + 4] == 'o' && parede[i+1][j + 4] == '#' && i+1 < altura && j - 5 >= 0 && j - 4 >= 1){
                                parede[i][j + 5] = 'o';
                                if(parede[i][j + 5] == 'o' && parede[i+1][j + 5] == '#' && i+1 < altura && j - 6 >= 0 && j - 5 >= 1){
                                    parede[i][j + 6] = 'o';
                                }
                            }
                        }
                    }
                }
            }
            
            else if(parede[i][j] == 'o' && parede[i][j+1] == '#' && j+1 < largura && i+1 < altura){
                parede[i+1][j] = 'o';
            }
            else if(parede[i - 1][j] == 'o' && parede[i][j] == '.' && i-1 >= 0){
                parede[i][j] = 'o';

                if(parede[i][j] == 'o' && parede[i+1][j] == '#' && i+1 < altura && j - 1 >= 0 && j+1 < largura){
                    parede[i][j - 1] = 'o';
                    if(parede[i][j - 1] == 'o' && parede[i+1][j - 1] == '#' && j - 1 >= 1 && j - 2 >= 0 && i+1 < altura){
                        parede[i][j - 2] = 'o';
                    }
                    parede[i][j + 1] = 'o';
                    if(parede[i][j + 1] == 'o' && parede[i+1][j + 1] == '#' && j + 1 < largura && j + 2 < largura && i+1 < altura){
                        parede[i][j + 2] = 'o';
                    }
                }
            }
        }
    }

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            printf("%c", parede[i][j]);
        }
        printf("\n");
    }


    return 0;
}