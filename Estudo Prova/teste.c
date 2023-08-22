char *jogada(char pecaEscolhida, char extremidade, char *pecasJogador, char *tamPecasJog, Peca *todasPecas, char *Mesa, char *tamMesa) {
    // Verificar se a jogada é válida
    if (extremidade == 0) {
        // Verificar se a peça escolhida pode ser colocada no início da mesa
        if (todasPecas[pecaEscolhida].parte1 != Mesa[0] && todasPecas[pecaEscolhida].parte2 != Mesa[0]) {
            printf("Jogada inválida!\n");
            return pecasJogador;
        }
    } else {
        // Verificar se a peça escolhida pode ser colocada no final da mesa
        if (todasPecas[pecaEscolhida].parte1 != Mesa[*tamMesa - 1] && todasPecas[pecaEscolhida].parte2 != Mesa[*tamMesa - 1]) {
            printf("Jogada inválida!\n");
            return pecasJogador;
        }
    }

    // Remover a peça escolhida das peças do jogador
    int i;
    for (i = 0; i < *tamPecasJog; i++) {
        if (pecasJogador[i] == pecaEscolhida) {
            break;
        }
    }
    for (; i < *tamPecasJog - 1; i++) {
        pecasJogador[i] = pecasJogador[i + 1];
    }
    (*tamPecasJog)--;

    // Adicionar a peça escolhida na mesa
    if (extremidade == 0) {
        // Adicionar a peça no início da mesa
        for (i = *tamMesa; i > 0; i--) {
            Mesa[i] = Mesa[i - 1];
        }
        Mesa[0] = pecaEscolhida;
    } else {
        // Adicionar a peça no final da mesa
        Mesa[*tamMesa] = pecaEscolhida;
    }
    (*tamMesa)++;

    return pecasJogador;
}
