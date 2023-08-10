#include <stdio.h>

int main(void) {
    int x, y, i, j, a = 0, b, c;
    int qtdDiv, maisDiv = 0, menosDiv = 0, numPrim = 1, resto;

    scanf("%d %d", &x, &y);

    if (y > x && x > 0 && !(x == 2 && y == 3)) {
        for (i = x; i <= y; i++) { // Percorre o intervalo
            numPrim = 1;
            for (j = 2; j * j <= i; j++) { // Divide por todos os números até ele mesmo
                if (i % j == 0) { // Se o resto da divisão for 0, logo, ele tem uma divisão exata
                    numPrim = 0;
                    break;
                }
            }

            if (numPrim == 0) {
                qtdDiv = 0;
                for (j = 1; j <= i / 2; j++) {
                    if (i % j == 0) {
                        qtdDiv++;
                    }
                }

                if (qtdDiv > maisDiv) {
                    maisDiv = qtdDiv;
                    a = i;
                } else if (qtdDiv == maisDiv && (menosDiv == 0 || i < a)) {
                    a = i;
                }

                if (qtdDiv < menosDiv || menosDiv == 0) {
                    menosDiv = qtdDiv;
                    b = i;
                } else if (qtdDiv == menosDiv && i < b) {
                    b = i;
                }
            }
        }
    }

    x = a;
    y = b;

    while (y != 0) {
        resto = x % y;
        x = y;
        y = resto;
    }
    c = x;

    printf("%d %d %d", a, b, c);

    return 0;
}
