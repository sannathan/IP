#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char aluno_nome[100];
    long int aluno_cpf;
    int aluno_qtdNotas;
    float aluno_notas[];
}Aluno;

Aluno *carregaAlunos(int *qtdNotas);
float *leNotas(int *qtdNotas);
float media(float *notas, int qtdNotas);
void ordena(Aluno *alunos, int qtdAlunos);
void salvaAlunos(Aluno *alunos, int qtdAlunos);
//declara a função

int main(void){
    FILE *file;
    file = fopen("alunos.txt", "r"); //Abre o arquivo para leitura

    if(file == NULL){
        printf("Deu erro no diretorio");
        exit(0); //caso meu arquivo não seja encontrado, o programa fecha.
    }

// os nomes e cpfs dos alunos estão nos arquivos, logo vou usar funções para entrar nesse arquivo e armazenar os dados
    Aluno alunos; //crio uma variável que vou apontar com meu vetor dinamico
    int *Din_vet; //crio um vetor de ponteiro
    Din_vet = (int *) malloc(sizeof(Aluno)); //aloco memória para ele

    Din_vet = &alunos; //aponto o vetor dinamico para a struct
    int qtd_Alunos = sizeof(Din_vet)/sizeof(Aluno); //faço uma divisão para atribuir a quantidade de alunos, visto que o vetor dinamico vai alocar quantidade x de alunos, e a quantidade de memória alocada é um multiplo do tamanho de memória que a struct alunos tem
    int *pAlunos = &qtd_Alunos; //ponteiro que aponta para o endereço de memória da quantidade de alunos.
    int qtd_Notas = sizeof(Din_vet)/sizeof(Aluno); //faço uma divisão para atribuir a quantidade de alunos, visto que o vetor dinamico vai alocar quantidade x de alunos, e a quantidade de memória alocada é um multiplo do tamanho de memória que a struct alunos tem
    int *pNotas = &qtd_Notas; 

    leNotas(pNotas); //chama a função que vai ler e armazenar as notas do aluno
    media(Din_vet, qtd_Notas);//pega as notas e faz a media delas
    ordena(Din_vet, qtd_Alunos); //ordena as notas
    salvaAlunos(Din_vet, qtd_Alunos);

    fclose(file);// Fecha o arquivo
    free(Din_vet); // Libera a memória alocada
    return 0;
}

Aluno *carregaAlunos(int *qtdAlunos){
    for(int x = 0; x < qtdAlunos; x++){//loop que vai rodar todos os alunos
        fprintf(file, qtdAlunos); //armazena na variavel qtdAlunos os dados do arquivo file
    }
    
}
float *leNotas(int *qtdNotas){
    printf("Digite suas notas:\n");
    while(*qtdNotas > -1){
        scanf("%d", *qtdNotas); //armazena a quantidade de notas do aluno x até que ele digite uma nota negativa, ai a função retorna o vetor com as notas
    }
        return qtdNotas;
    }
float media(float *notas, int qtdNotas){
    int med;

    med = *notas/qtdNotas; //pega as notas e divide pela quantidade de exames feitos
    return media;
}
void ordena(Aluno *alunos, int qtdAlunos){
    int x, y, cache_cpf;
    char cache_nome[100];

    for(x = 0; x < qtdAlunos; x++){ //Pega aluno por aluno e compara com os demais
        for(y = x+1; y < qtdAlunos; y++){ //Pega o aluno da posição e compara com os outros
            if(alunos[x] < alunos[y]){
                cache_cpf = alunos[x].aluno_cpf;
                cache_nome[x] = alunos[x].aluno_nome;
                alunos[x].aluno_cpf = alunos[y].aluno_cpf;
                alunos[x].aluno_nome = alunos[y].aluno_nome;
                alunos[y] = cache_cpf;
                alunos[y] = cache_nome[x];
            } //bubble sorting para fazer a ordem decrescente
        }
    }

}
void salvaAlunos(Aluno *alunos, int qtdAlunos){
    FILE *cripto;
    cripto = fopen("alunos.bin", "wb");

    fwrite(alunos, cripto); // salva o vetor no arquivo
    fclose(cripto);
}