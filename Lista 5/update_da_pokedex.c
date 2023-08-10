#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    char tipo[100];
    int ataque;
    int defesa;
}dados;

int main(void){
    int n;
    dados inimigo;

    scanf("%s %s %d %d", inimigo.nome, inimigo.tipo, &inimigo.ataque, &inimigo.defesa);
    scanf("%d", &n);

    dados pokemons[n];
    float vant[n];
    float cache;
    char cacheS[100];
    int resultado;

    for(int i = 0; i < n; i++){
        scanf("%s %s %d %d", pokemons[i].nome, pokemons[i].tipo, &pokemons[i].ataque, &pokemons[i].defesa);

        if(strcmp(pokemons[i].tipo, "agua") == 0 && strcmp(inimigo.tipo, "fogo") == 0){
            vant[i] = 0;
            vant[i] = (pokemons[i].ataque + (pokemons[i].ataque * 0.5)) - inimigo.defesa;
        }
        else if(strcmp(pokemons[i].tipo, "grama") == 0 && strcmp(inimigo.tipo, "agua") == 0){
            vant[i] = 0;
            vant[i] = (pokemons[i].ataque + (pokemons[i].ataque * 0.5)) - inimigo.defesa;
        }
        else if(strcmp(pokemons[i].tipo, "fogo") == 0 && strcmp(inimigo.tipo, "grama") == 0){
            vant[i] = 0;
            vant[i] = (pokemons[i].ataque + (pokemons[i].ataque * 0.5)) - inimigo.defesa;
        }
        else{
            vant[i] = 0;
            vant[i] = pokemons[i].ataque - inimigo.defesa;
            printf("O nome eh: %s e a vantagem eh:%f", pokemons[i].nome, vant);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(vant[j] < vant[j+1]){
                cache = vant[j];
                vant[j] = vant[j+1];
                vant[j+1] = cache;

                strcpy(cacheS, pokemons[j].nome);
                strcpy(pokemons[j].nome, pokemons[j+1].nome);
                strcpy(pokemons[j+1].nome, cacheS);
            }
            else{
                resultado = strcmp(pokemons[j].nome, pokemons[j+1].nome);
                if(resultado > 0){
                    strcpy(cacheS, pokemons[j].nome);
                    strcpy(pokemons[j].nome, pokemons[j+1].nome);
                    strcpy(pokemons[j+1].nome, cacheS);
                }
            }
        }
    }

    for(int k = 1; k < n+1; k++){
        printf("%d. %s\n", k, pokemons[k-1].nome);
    }

    return 0;
}