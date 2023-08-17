#include <stdio.h>

typedef struct{
    char nome[101];
    char CPF[12];
    int qtd_notas;
    int *notas;
    float media;
}Aluno;

Aluno *carregaAlunos(int *qtdAlunos){
    Aluno *alunos = (Aluno *) malloc((*qtdAlunos) * sizeof(Aluno));

    if(alunos == NULL){
        printf("Erro ao alocar memória");
        exit(1);
    }

    FILE *arq;
    arq = fopen("alunos.txt", "r");

    if(arq){
        for(int i = 0; i < *qtdAlunos; i++){
            fscanf(arq, "%99[^\n]", alunos[i].nome);
            fseek(arq, sizeof(alunos[i].nome) + 1, SEEK_SET); //Posiciona o indicador de posição no começo da segunda linha
            fscanf(arq, "%11[^\n]", alunos[i].CPF);
            fseek(arq, sizeof(alunos[i].CPF) + 1, SEEK_CUR);
            fscanf(arq, "%d", alunos[i].qtd_notas);
        }
    }
    else{
        printf("Erro ao abrir o arquivo");
    }
    fclose(arq);
    return alunos;
}

float *leNotas(int *qtdNotas){
    float *notas = (float *)malloc (sizeof(float));
    int i = 0;

    printf("Digite as notas do aluno: %d\n", i);
    while(scanf("%f", &notas[i]) > -1){
        notas = (float *)realloc (sizeof(float) + 1);
        *qtdNotas++;
        i++;
    }
    return notas;
}

float media(float *notas, int qtdNotas){
    float aux = 0, media = 0;

    for(int i = 0; i < qtdNotas; i++){
        aux += notas[i];
    }

    media = aux / qtdNotas;
    return media;
}

void ordena(Aluno *alunos, int qtdAlunos){
    Aluno cache;
    for(int i = 0; i < qtdAlunos; i++){
        for(int j = 0; j < qtdAlunos - i - 1; j++){
            if(alunos[j].media < alunos[j+1].media){
                cache = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = cache;
            }
        }
    }

}
void salvaAlunos(Aluno *alunos, int qtdAlunos){
    FILE *arq;
    arq = fopen("alunos.bin", "wb");

    if(arq){
        for(int i = 0; i < qtdAlunos; i++){
            fwrite(alunos[i].nome, sizeof(alunos[i].nome), 1, arq);
            fseek(arq, sizeof(alunos[i].nome + 1), SEEK_SET);
            fwrite(alunos[i].CPF, sizeof(alunos[i].CPF), 1, arq);
            fseek(arq, sizeof(alunos[i].CPF + 1), SEEK_CUR);
            fwrite(alunos[i].qtd_notas, sizeof(alunos[i].qtd_notas), 1, arq);
            fseek(arq, sizeof(alunos[i].qtd_notas + 1), SEEK_CUR);
            for(int j = 0; j < alunos[i].qtd_notas; j++){
                fwrite(alunos[i].notas[j], sizeof(alunos[i].notas[j]), 1, arq);
                fseek(arq, sizeof(float), SEEK_CUR);
            }
        }
    }
    else{
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fclose(arq);
}

int main(void){
    int qtdAlunos, qtdNotas;
    printf("Digite a quantidade de alunos:\n");
    scanf("%d", &qtdAlunos);

    Aluno *alunos = carregaAlunos(&qtdAlunos);

    for(int i = 0; i < qtdAlunos; i++){
        alunos[i].notas = leNotas(&qtdNotas);
        alunos[i].media = media(&alunos[i].notas, qtdNotas);
        ordena(alunos, qtdAlunos);
    }

    salvaAlunos(alunos, qtdAlunos);

    free(alunos);
    return 0;
}