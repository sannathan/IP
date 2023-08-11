#include <stdio.h>

int main(void){
    FILE *arq;

    arq = fopen("teste.txt", "at");

    if(arq == NULL){
        printf("Deu erro manehJH");
    }
    fprintf(arq, "%s\n", "Alexandre e Mota");
    printf("Deu tudo certo");
    fclose(arq);


    return 0;
}

void realizar_entrega(Filial *filiais, Produto produto, int n_filiais)
{
    // Declaração das variáveis para armazenar as distâncias mínimas e os índices das filiais.
    float DistOrigem, DistDestino;
    float minOrigem = max, minDestino = max;
    int indexOrigem = -1, indexDestino = -1;

    // Loop que itera através de todas as filiais.
    for (int i = 0; i < n_filiais; i++)
    {
        // Cálculo da distância entre a origem do produto e a localização da filial atual.
        DistOrigem = sqrt(pow(produto.origem_x - filiais[i].loc_x, 2) + pow(produto.origem_y - filiais[i].loc_y, 2));

        // Verifica se a distância é menor que a distância mínima encontrada anteriormente.
        // Se sim, atualiza a distância mínima e o índice da filial de origem mais próxima.
        if (DistOrigem < minOrigem)
        {
            minOrigem = DistOrigem;
            indexOrigem = i;
        }

        // Cálculo da distância entre o destino do produto e a localização da filial atual.
        DistDestino = sqrt(pow(produto.destino_x - filiais[i].loc_x, 2) + pow(produto.destino_y - filiais[i].loc_y, 2));

        // Verifica se a distância é menor que a distância mínima encontrada anteriormente.
        // Se sim, atualiza a distância mínima e o índice da filial de destino mais próxima.
        if (DistDestino < minDestino)
        {
            minDestino = DistDestino;
            indexDestino = i;
        }
    }

    // Remove um caminhão da filial de origem mais próxima e o armazena na variável 'add'.
    Caminhao add = remover_caminhao(filiais, indexOrigem);

    // Cadastra o caminhão na filial de destino mais próxima.
    cadastrar_caminhao(filiais, add, indexDestino);

    return;
}
