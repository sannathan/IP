#include <stdio.h>

int abs(int num) {
    return num >= 0 ? num : -num;
}

int main() {
    int numero, n;
    scanf("%d %d", &numero, &n);
    
    int canal_mais_chance = 0;
    int minuto_mais_chance = 0;
    int distancia_mais_proxima = -1;
    int ingresso_vip = 0;
    
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int fib_ant_ant = a;
        int fib_ant = b;
        int fib_atual;
        int minuto_atual = 2;
        
        while (1) {
            fib_atual = fib_ant_ant + fib_ant;
            
            int distancia_a = abs(numero - fib_ant);
            int distancia_b = abs(numero - fib_atual);
            
            int distancia = distancia_a < distancia_b ? distancia_a : distancia_b;
            
            if (distancia_mais_proxima == -1 || distancia < distancia_mais_proxima) {
                distancia_mais_proxima = distancia;
                canal_mais_chance = i;
                minuto_mais_chance = minuto_atual;
                
                int soma_digitos = 0;
                int temp = fib_atual;
                while (temp > 0) {
                    soma_digitos += temp % 10;
                    temp /= 10;
                }
                
                if (soma_digitos > 10) {
                    ingresso_vip = 1;
                } else {
                    ingresso_vip = 0;
                }
            }
            
            if (fib_atual >= numero) {
                break;
            }
            
            fib_ant_ant = fib_ant;
            fib_ant = fib_atual;
            minuto_atual++;
        }
    }
    
    if (ingresso_vip) {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canal_mais_chance, minuto_mais_chance);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canal_mais_chance, minuto_mais_chance);
    }
    
    return 0;
}
