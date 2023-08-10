#include <stdio.h>

int main(void){
    int *pontptr = NULL, pont = 5;
    void *ponte = NULL;

    pontptr = &pont;

    printf("%d", pontptr);
    printf("%d", &pont);

    return 0;
}