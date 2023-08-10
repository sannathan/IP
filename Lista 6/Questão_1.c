#include <stdio.h>

int main(void){
    char c;
    char *pc = NULL;
    c = 'a';
    pc = &c;

    printf("endereco de c: %p, valor de c: %c\n", &c, c);
    printf("valor que pc armazena: %p o valor guardado: %c\n", pc, *pc);
    printf("Endereco de pc: %p\n", &pc);
    printf("Endereço do valor guardado: %p e o valor guardado em pc: %p\n", &*pc, *&pc);
    return 0;
}