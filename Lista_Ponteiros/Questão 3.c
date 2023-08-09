#include <stdio.h>

int main(void){
    char str[50];
    char str_inv[50];
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;
    scanf(" %s", str);

    while(*ptr_str != '\0'){ //Enquanto a posição do ponteiro for diferente de \0
        ptr_str++; //aumente para a próxima posição da string
        i++; //aumente o contador
    }

    while(i != -1){
        ptr_str--;
        *ptr_inv = *ptr_str;
        ptr_inv++;
        i--;
    }

    *ptr_inv = '\0';
    
    printf("O inverso da string: %s\n\n", str_inv);

    return 0;
}