#include <stdio.h>

void ConcatenarStrings(char string1[],int t1, char string2[], int t2, char string3[]){
    for(int i = 0; i < t1; i++){
        string3[i] = string1[i];
    }
    for(int j = 0; j < t2; j++){
        string3[t1+j] = string2[j];
    }
    
}

int main(void){
    void ConcatenarStrings(char string1[], int t1, char string2[], int t2, char string3[]);
    char palavra1[] = {'p', 'a', 'o', ' '}, palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'}, novaPalavra[13];
    
    ConcatenarStrings(palavra1, 4, palavra2, 9, novaPalavra);

    for(int x; x < 13; x++){
        printf("%c", novaPalavra[x]);
    }
    return 0;
}