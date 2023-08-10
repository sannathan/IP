#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x, n;
    scanf("%d %d", &x, &n);

    int num1, num2, numAtual, minAtual = 2;
    int distanciaMaisProx = -1, canalMaisProx, minutoMaisProx, ingressoVip;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &num1, &num2);

        int numseq1, numseq2;

        while(1) {
            numAtual = numseq1 + numseq2; //A sequencia atual é denotada por f(i) = f(i - 1) + f(i - 2), ou seja, numseq1, numseq2.

            int distanciaA = x - numseq1; //A distancia da primeira sequência é o número de xupenio menos a sequencia atual.
            int distanciaB = x - numseq2;

            int distancia = distanciaA < distanciaB ? distanciaA : distanciaB; //A distancia em geral, é a menor das distancias tanto de a como de b
            if (distancia < 0) {
                distancia = -distancia; // Se a distancia for negativa, se torna positiva
            }

            if(distanciaMaisProx == -1 || distancia < distanciaMaisProx) { //Se a distancia mais próxima for maior que distancia, distanciaMaisProx assume o valor de distância
                distanciaMaisProx = distancia; //Distancia mais próxima atualizada
                canalMaisProx = i; //Canal mais próximo é o i
                minutoMaisProx = minAtual; //Minuto mais proximo é o minuto atual
                
                int soma_digitos = 0;
                int temp = numAtual;
                while (temp > 0) {
                    soma_digitos += temp % 10;
                    temp /= 10;
                }
                
                if (soma_digitos > 10) {
                    ingressoVip = 1;
                } else {
                    ingressoVip = 0;
                }
            }
            
            if (numAtual >= x) {
                break;
            }
            
            numseq1 = numseq2;
            numseq2 = numAtual;
            minAtual++;
        }
    }
    
    if (ingressoVip) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canalMaisProx, minutoMaisProx);
    } 
    else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canalMaisProx, minutoMaisProx);
    }

    return 0;
}
