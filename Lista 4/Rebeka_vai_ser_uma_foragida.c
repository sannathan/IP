#include <stdio.h>

int main(void){
    char frases[10][1000];
    int linha = 0;

    while(linha < 10 && scanf("%999s", frases[linha]) != EOF) {
        if(frases[linha][0] == ' '){
            break;
        }
        linha++;
    }

    printf("Frases lidas:\n");
    for(int i = 0; i < linha; i++){
        printf("%s\n", frases[i]);
    }
    
    return 0;
}