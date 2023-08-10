#include <stdio.h>

int main(void){
    int T, N;

    scanf("%d %d", &T, &N);

    int x[T][N];

    for(int i = 0; i < T; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &x[i][j]);
        }
    }

    int cache;

    for(int i = 0; i < T; i++){
        for(int j = 0; j < N; j++){
            if(x[i][j] < x[i][j+1]){
                cache = x[i][j];
                x[i][j] = x[i][j+1];
                x[i][j+1] = cache;
            }
        }
    }

    for(int i = 0; i < T; i++){
        for(int j = 0; j < N; j++){
            if(x[i][j] < x[i][j+1]){
                cache = x[i][j];
                x[i][j] = x[i][j+1];
                x[i][j+1] = cache;
            }
        }
    }


    return 0;
}