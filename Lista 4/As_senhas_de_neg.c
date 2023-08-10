#include <stdio.h>
#include <string.h>

int main(void){
    int qtdSenhas, total_characters = 0;
    scanf("%d", &qtdSenhas);

    char senhas[qtdSenhas][100], senhaCripto[100], senhasCripto[100];

    for(int i = 0; i < qtdSenhas; i++){
        fgets(senhas[i], sizeof(senhas[i]), stdin); //input das strings
        senhas[i][strcspn(senhas[i],"\n")] = '\0'; //A função strcspn nos coloca na posição do caractere '\n' na string senhas[i] e substitui por '\0'

        int valid_password = 1;
        for(int j = 0; j < strlen(senhas[i]); j++){
            if(!((senhas[i][j] >= 'A' && senhas[i][j] <= 'Z')|| (senhas[i][j] >= '0' && senhas[i][j] <= '9'))){
                valid_password = 0;
                break;
            }
        }

        if(valid_password == 0){
            printf("Alguma senha eh invalida!");
            return 0;
        }

        total_characters += strlen(senhas[i]);
    }

    for(int i = 0; i < qtdSenhas; i++){
        for(int j = 0; j < strlen(senhas[i]); j++){
            if((senhas[i][j] >= 'A' && senhas[i][j] <= 'Z')|| (senhas[i][j] >= '0' && senhas[i][j] <= '9')){
                if(senhas[i][j] == '0'){
                    strcat(senhaCripto, "6");
                }
                else if(senhas[i][j] == '1'){
                    strcat(senhaCripto, "7");
                }
                else if(senhas[i][j] == '2'){
                    strcat(senhaCripto, "9");
                }
                else if(senhas[i][j] == '3'){
                    strcat(senhaCripto, "8");
                }
                else if(senhas[i][j] == '4'){
                    strcat(senhaCripto, "A");
                }
                else if(senhas[i][j] == '5'){
                    strcat(senhaCripto, "2");
                }
                else if(senhas[i][j] == '6'){
                    strcat(senhaCripto, "B");
                }
                else if(senhas[i][j] == '7'){
                    strcat(senhaCripto, "F");
                }
                else if(senhas[i][j] == '8'){
                    strcat(senhaCripto, "1");
                }
                else if(senhas[i][j] == '9'){
                    strcat(senhaCripto, "C");
                }
                else if(senhas[i][j] == 'A'){
                    strcat(senhaCripto, "0");
                }
                else if(senhas[i][j] == 'B'){
                    strcat(senhaCripto, "D");
                }
                else if(senhas[i][j] == 'C'){
                    strcat(senhaCripto, "E");
                }
                else if(senhas[i][j] == 'D'){
                    strcat(senhaCripto, "3");
                }
                else if(senhas[i][j] == 'E'){
                    strcat(senhaCripto, "5");
                }
                else if(senhas[i][j] == 'F'){
                    strcat(senhaCripto, "4");
                }
            }
            else{
                char temp[2] = {senhas[i][j], '\0'};
                strcat(senhaCripto, temp);
            }
        }
        strcat(senhasCripto, senhaCripto);
        if(i != qtdSenhas - 1){
            strcat(senhasCripto, "-");
        }
    }

    printf("%s %d\n", senhasCripto, total_characters);
    return 0;
}