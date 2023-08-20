#include <stdio.h>

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

listaCandidatos carregarCandidatos(char *nomeArq){
    listaCandidatos candidatos;
    return candidatos;
}

Eleitor *carregarEleitores(char *nomeArq, int *qtdEleitores){
    return;
}

int verificaCandidato(listaCandidatos listaC, Candidato candidatoAt){
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
    printf("\t SISTEMA ELEITORAL\n\tELEICOES 2023.1\n1- Votar\n2- Votacao Atual\n3- Sair do sistema\n");


    return 0;
}