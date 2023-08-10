#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    int agregados;
    char comida[100];
    char bebida[100];
    char atracao[100];
}VOTO;

int main(void){
    int n, x = 0, h;
    int gus = 0, billie = 0, pericao = 0, shev = 0, joao = 0;
    int cox = 0, brig = 0, ris = 0, pic = 0, piz = 0;
    int agua = 0, cafe = 0, suco = 0, mons = 0, pitu = 0;
    char comidaFinal[100], bebidaFinal[100], cantorFinal[100];
    int agregadoFinal, maisVotados[100], coordenada_maior_numero;
    scanf("%d", &n);
    VOTO votos[n];
    char vips[n][100], cache[100];

    for(int i = 0; i < n; i++){
        scanf("%s %d %s %s %[^\n]", votos[i].nome, &votos[i].agregados, votos[i].comida, votos[i].bebida, votos[i].atracao);

        maisVotados[votos[i].agregados] = 0;
        maisVotados[votos[i].agregados] += 1;
      
      if(i == 0){
        h = votos[i].agregados;
      }

        if(strcmp(votos[i].comida, "coxinha") == 0){
            cox++;
        }
        else if(strcmp(votos[i].comida, "brigadeiro") == 0){
            brig++;
        }
        else if(strcmp(votos[i].comida, "risoto") == 0){
            ris++;
        }
        else if(strcmp(votos[i].comida, "picanha") == 0){
            pic++;
        }
        else{
            piz++;
        }

        if(strcmp(votos[i].bebida, "agua") == 0){
            agua++;
        }
        else if(strcmp(votos[i].bebida, "cafe") == 0){
            cafe++;
        }
        else if(strcmp(votos[i].bebida, "suco") == 0){
            suco++;
        }
        else if(strcmp(votos[i].bebida, "monster") == 0){
            mons++;
        }
        else{
            pitu++;
        }

        if(strcmp(votos[i].atracao, "Gustavo Mioto") == 0){
            gus++;
        }
        else if(strcmp(votos[i].atracao, "Billie Eilish") == 0){
            billie++;
        }
        else if(strcmp(votos[i].atracao, "Pericles") == 0){
            pericao++;
        }
        else if(strcmp(votos[i].atracao, "Shevchenko e Elloco") == 0){
            shev++;
        }
        else if(strcmp(votos[i].atracao, "Joao Gomes") == 0){
            joao++;
        }
    }
    int tam = sizeof(maisVotados) / sizeof(maisVotados[h]);
    int maiorNum = maisVotados[h];

    for (int i = 0; i < tam; i++) {
      if (maisVotados[i] > maiorNum) {
        maiorNum = maisVotados[i];
        coordenada_maior_numero = i;
      }
    }

    agregadoFinal = coordenada_maior_numero;
    
    if(cox > brig && cox > ris && cox > pic && cox > piz){
        strcpy(comidaFinal, "coxinha");
    }
    else if(brig > cox && brig > ris && brig > pic && brig > piz){
        strcpy(comidaFinal, "brigadeiro");
    }
    else if(ris > brig && ris > cox && ris > pic && ris > piz){
        strcpy(comidaFinal, "risoto");
    }
    else if(pic > brig && pic > ris && pic > cox && pic > piz){
        strcpy(comidaFinal, "picanha");
    }
    else if(piz > pic && piz > brig && piz > ris && piz > cox){
        strcpy(comidaFinal, "pizza");
    }
    else if((brig == cox && brig != 0) || (brig == ris && brig !=0) || (brig == pic && brig != 0) || (brig == piz && brig != 0)){
        strcpy(comidaFinal, "brigadeiro");
    }
    else if((cox == ris && cox != 0) || (cox == pic && cox != 0) || (cox == piz && cox != 0)){
        strcpy(comidaFinal, "coxinha");
    }
    else if((pic == piz && pic != 0) || (pic == ris && pic != 0)){
        strcpy(comidaFinal, "picanha");
    }
    else if((piz == ris && piz != 0)){
        strcpy(comidaFinal, "pizza");
    }

    
    if(agua > cafe && agua > suco && agua > mons && agua > pitu){
        strcpy(bebidaFinal, "agua");
    }
    else if(cafe > agua && cafe > suco && cafe > mons && cafe > pitu){
        strcpy(bebidaFinal, "cafe");
    }
    else if(suco > cafe && suco > agua && suco > mons && suco > pitu){
        strcpy(bebidaFinal, "suco");
    }
    else if(mons > cafe && mons > suco && mons > agua && mons > pitu){
        strcpy(bebidaFinal, "monster");
    }
    else if(pitu > cafe && pitu > suco && pitu > agua && pitu > mons){
        strcpy(bebidaFinal, "pitu");
    }
    else if((agua == cafe && agua != 0) || (agua == suco && agua != 0) || (agua == mons && agua != 0) || (agua == pitu && agua != 0)){
        strcpy(bebidaFinal, "agua");
    }
    else if(cafe == suco || cafe == mons || cafe == pitu){
        strcpy(bebidaFinal, "cafe");
    }
    else if(mons == suco || mons == pitu){
        strcpy(bebidaFinal, "monster");
    }
    else if(pitu == suco){
        strcpy(bebidaFinal, "pitu");
    }

    
    if(gus > billie && gus > pericao && gus > shev && gus > joao){
        strcpy(cantorFinal, "Gustavo Mioto");
    }
    else if(billie > gus && billie > pericao && billie > shev && billie > joao){
        strcpy(cantorFinal, "Billie Eilish");
    }
    else if(pericao > billie && pericao > gus && pericao > shev && pericao > joao){
        strcpy(cantorFinal, "Pericles");
    }
    else if(shev > billie && shev > pericao && shev > gus && shev > joao){
        strcpy(cantorFinal, "Shevchenko e Elloco");
    }
    else if(joao > billie && joao > pericao && joao > gus && joao > shev){
        strcpy(cantorFinal, "Joao Gomes");
    }
    else if((billie == gus && billie != 0) || (billie == pericao && billie != 0) || (billie == shev && billie != 0)|| (billie == joao && billie != 0)){
        strcpy(cantorFinal, "Billie Eilish");
    }
    else if((gus == pericao && gus != 0) || (gus == shev && gus != 0) || (gus == joao && gus != 0)){
        strcpy(cantorFinal, "Gustavo Mioto");
    }
    else if((joao == pericao && joao != 0) || (joao == shev && joao !=0)){
        strcpy(cantorFinal, "Joao Gomes");
    }
    else if(pericao == shev && pericao != 0){
        strcpy(cantorFinal, "Pericles");
    }

    for(int i = 0; i < n; i++){
        if((strcmp(votos[i].comida, comidaFinal) == 0) && (strcmp(votos[i].bebida, bebidaFinal) == 0)){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
        else if((strcmp(votos[i].comida, comidaFinal) == 0) && (strcmp(votos[i].atracao, cantorFinal) == 0)){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
        else if((strcmp(votos[i].bebida, bebidaFinal) == 0) && (strcmp(votos[i].atracao, cantorFinal) == 0)){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
        else if((strcmp(votos[i].comida, comidaFinal) == 0) && votos[i].agregados == agregadoFinal){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
        else if(strcmp(votos[i].bebida, bebidaFinal) == 0 && votos[i].agregados == agregadoFinal){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
        else if(strcmp(votos[i].atracao, cantorFinal) == 0 && votos[i].agregados == agregadoFinal){
            strcpy(vips[x], votos[i].nome);
            x++;
        }
    }

    for(int k = 0; k < x-1; k++){
        for(int u = 0; u < x - k - 1; u++){
            if(strcmp(vips[u],vips[u+1]) > 0){
                strcpy(cache, vips[u]);
                strcpy(vips[u], vips[u+1]);
                strcpy(vips[u+1], cache);
            }
        }
    }
    

    printf("%d\n%s\n%s\n%s\n", agregadoFinal, comidaFinal, bebidaFinal, cantorFinal);
    printf("convidados vip:\n");
    for(int j = 0; j < x; j++){
        printf("%s\n", vips[j]);
    }

    return 0;
}