#include <stdio.h>

int main(void) {
    int dis = 0;
    char dir = ' ';
    int first = 0, espc = 20;

    while (dir != 'x') {
        scanf(" %c %d", &dir, &dis);

        if (dir == 'd') {
            if(first == 0){
                first++;
                for (int j = 0; j < espc; j++) {
                    putchar(' ');
                }
                for (int i = 0; i < dis; i++) {
                    printf("->");
                }
                printf("\n");
                espc+= dis * 2; //Armazena a quantidade de espaços a ser utilizado 
            }
            else{
                for(int i = 0; i < espc; i++){
                    putchar(' ');
                }
                for(int i = 0; i < dis; i++){
                    printf("->");
                }
                printf("\n");
                espc+=dis * 2;
            }
            
        }

        if (dir == 'e') {
            if(first == 0){
                first++;
                for (int j = 0; j < espc - dis * 2; j++) {
                    putchar(' ');
                }
                for (int i = 0; i < dis; i++) {
                    printf("<-");
                }
                printf("\n");
                espc-=(dis) * 2;
            }
            else{
                for (int j = 0; j < espc - dis; j++) {
                    putchar(' ');
                }
                for (int i = 0; i < dis; i++) {
                    printf("<-");
                }
                printf("\n");
                espc-=(dis) * 2;
            }
            
        }

        if (dir == 'f') {
                for (int i = 0; i < dis; i++) {
                    for (int j = 0; j < espc; j++) {
                        putchar(' ');
                    }
                    printf("|\n");
                } 
            }

        if(dir == 'x'){
            for (int j = 0; j < espc; j++) {
                    putchar(' ');
            }
            printf("x");
        }
    }

    return 0;
}
