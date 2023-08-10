#include <stdio.h>

int main(void){
    int Ai, Aj, Bi, Bj;
    scanf("%d %d %d %d", &Ai, &Aj, &Bi, &Bj);

    int Mat1[Ai][Aj], Mat2[Bi][Bj];

    for(int i = 0; i < Ai; i++){
        for(int j = 0; j < Aj; j++){
            scanf("%d", &Mat1[i][j]);
        }
    }

    for(int i = 0; i < Bi; i++){
        for(int j = 0; j < Bj; j++){
            scanf("%d", &Mat2[i][j]);
        }
    }

    int Mat3[Ai][Bj];

    if(Aj == Bi){
        for(int i = 0; i < Ai; i++){
            for(int j = 0; j < Bj; j++){
                Mat3[i][j] = 0;
                for(int k = 0; k < Aj; k++){
                    Mat3[i][j] += Mat1[i][k] * Mat2[k][j];
                }
            }
        }
    }
    else{
        printf("Nao e possivel multiplicar\n");
        return 0;
    }

    for(int x = 0; x < Ai; x++){
        for(int y = 0; y < Bj; y++){
            printf("%d ", Mat3[x][y]);
        }
        printf("\n");
    }

    return 0;
}