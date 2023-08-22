#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    int numero;
}Candidato;

typedef struct{
    Candidato *depFed;
    Candidato *depEst;
    Candidato *Senador;
    Candidato *Governador;
    Candidato *Presidente;
    int qtdCandidatos[5];
}listaCandidatos;

typedef struct{
    Candidato candi;
    int votos;
}TotalVoto;

typedef struct{
    char nome[100];
    char cpf[12];
}Eleitor;

listaCandidatos carregarCandidatos(char *nomeArq){
    char tipo[100];
    int qtdFed = 0, qtdEst = 0, qtdGov = 0, qtdSen = 0, qtdPres = 0;
    FILE *registroCand;
    listaCandidatos candidatos;
    registroCand = fopen(nomeArq, "r");

    if(registroCand){
        while(!feof(registroCand)){
                fscanf(registroCand, "%99[^,]", tipo);

            if(strcmp(tipo, "deputada federal") == 0){
                qtdFed++;
                Candidato *tmp = candidatos.depFed;
                candidatos.depFed = (Candidato *) realloc(candidatos.depFed, sizeof(Candidato) * qtdFed);

                if(candidatos.depFed == NULL){
                    printf("Erro de alocação de memória");
                    free(tmp);
                    exit(1);
                }
                fscanf(registroCand, "%99[^,]", candidatos.depFed[qtdFed - 1].nome);
                fscanf(registroCand, "%100[^\n]", &candidatos.depFed[qtdFed - 1].numero);
            }
            else if(strcmp(tipo, "deputado estadual") == 0){
                qtdEst++;
                Candidato *tmp = candidatos.depEst;
                candidatos.depEst = (Candidato *) realloc(candidatos.depEst, sizeof(Candidato) * qtdEst);

                if(candidatos.depEst == NULL){
                    printf("Erro de alocação de memória");
                    free(tmp);
                    exit(1);
                }
                fscanf(registroCand, "%99[^,]", candidatos.depEst[qtdEst - 1].nome);
                fscanf(registroCand, "%100[^\n]", &candidatos.depEst[qtdEst - 1].numero);
            }
            else if(strcmp(tipo, "senador") == 0){
                qtdSen++;
                Candidato *tmp = candidatos.Senador;
                candidatos.Senador = (Candidato *) realloc(candidatos.Senador, sizeof(Candidato) * qtdSen);

                if(candidatos.Senador == NULL){
                    printf("Erro de alocação de memória");
                    free(tmp);
                    exit(1);
                }
                fscanf(registroCand, "%99[^,]", candidatos.Senador[qtdSen - 1].nome);
                fscanf(registroCand, "%100[^\n]", &candidatos.Senador[qtdSen - 1].numero);
            }
            else if(strcmp(tipo, "governador") == 0){
                qtdGov++;
                Candidato *tmp = candidatos.Governador;
                candidatos.Governador = (Candidato *) realloc(candidatos.Governador, sizeof(Candidato) * qtdGov);

                if(candidatos.Governador == NULL){
                    printf("Erro de alocação de memória");
                    free(tmp);
                    exit(1);
                }
                fscanf(registroCand, "%99[^,]", candidatos.Governador[qtdGov - 1].nome);
                fscanf(registroCand, "%100[^\n]", &candidatos.Governador[qtdGov - 1].numero);
            }
            else if(strcmp(tipo, "presidente") == 0){
                qtdPres++;
                Candidato *tmp = candidatos.Presidente;
                candidatos.Presidente = (Candidato *) realloc(candidatos.Presidente, sizeof(Candidato) * qtdPres);

                if(candidatos.Presidente == NULL){
                    printf("Erro de alocação de memória");
                    free(tmp);
                    exit(1);
                }
                fscanf(registroCand, "%99[^,]", candidatos.Presidente[qtdPres - 1].nome); //qtdPres - 1 pois é a posição do vetor. o 1° candidato vai estar na posição 0 do vetor
                fscanf(registroCand, "%100[^\n]", &candidatos.Presidente[qtdPres].numero);
            }
        }
    }
    else{
        printf("Erro ao abrir o arquivo...\nRegistro de candidatos falhou!\n");
        return candidatos;
    }
    candidatos.qtdCandidatos[0] = qtdFed;
    candidatos.qtdCandidatos[1] = qtdEst;
    candidatos.qtdCandidatos[2] = qtdSen;
    candidatos.qtdCandidatos[3] = qtdGov;
    candidatos.qtdCandidatos[4] = qtdPres;

    fclose(registroCand);
    return candidatos;
}

Eleitor *carregarEleitores(char *nomeArq, int *qtdEleitores){
    FILE *registroEleitores;
    Eleitor *eleitores = NULL;

    registroEleitores = fopen(nomeArq, "r");

    if(registroEleitores){
        while(!feof(registroEleitores)){
            (*qtdEleitores)++;
            Eleitor *tmp = eleitores;
            eleitores = (Eleitor *) realloc(eleitores, sizeof(Eleitor) * (*qtdEleitores));

            if(eleitores == NULL){
                printf("Erro ao alocar memória...\nFechando programa\n");
                free(tmp);
                exit(1);
            }
            fscanf(registroEleitores, "%100[^,]", eleitores[*qtdEleitores - 1].cpf);
            fscanf(registroEleitores, "%100[^\n]", eleitores[*qtdEleitores - 1].nome);
        }
    }
    else{
        printf("Erro ao abrir o arquivo");
        return eleitores;
    }
    fclose(registroEleitores);
    return eleitores;
}

int verificaCandidato(listaCandidatos listaC, Candidato candidatoAt){
    if(strcmp(candidatoAt.nome, listaC.depEst))
    candidatoAt, 
    return;
}

int verificaEleitor(Eleitor *listaE, Eleitor eleitorAt){
    return;
}

void apresentaResultado(TotalVoto *votos, int qtdCandidatos){

}

Candidato *localizaCandidato(listaCandidatos listaC, Candidato candidatoAt, char *cargo){
    return;
}

int main(void){
    char ArqCandidatos[] = "candidatos.txt", ArqEleitores[] = "eleitores.txt";
    int qtdEleitores, escolha, saida = 1;
    listaCandidatos candidatos = carregarCandidatos(&ArqCandidatos);
    Eleitor *eleitores = carregarEleitores(&ArqEleitores, &qtdEleitores);

    printf("\t SISTEMA ELEITORAL\n\tELEICOES 2023.1\n1- Votar\n2- Votacao Atual\n3- Sair do sistema\n");
    scanf("%d", &escolha);

    do{
        switch(escolha){
        case 1:

            break;
        case 2:

            break;
        case 3:
            printf("Voto computado com sucesso!\nSaindo do sistema...");
            saida = 0;
            break;
        }
    }while(saida);
    

    return 0;
}