#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jogo.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL,"portuguese");
    struct tabuleiro m[11][11];
    int y=0;
    srand(time(NULL));
    int tam=6;
    char *pilha=(char*)malloc(36*sizeof(char));
    int *casa=(int*)malloc(tam*sizeof(int));
    int *valorKza=(int*)malloc(tam*sizeof(int));
    char *valores=(char*)malloc(tam*sizeof(char));
    int escolha,x;
    do{
        escolha=dificuldade(0);
        limpar();
        switch (escolha){
                case 1:{
                    printf("Voce pode revelar o valor de 3 casas!\n");
                    x=3;
                    break;
                }
                case 2:{
                    printf("Voce pode revelar o valor de 2 casas!\n ");
                    x=2;
                    break;
                }
                case 3:{
                    printf("Voce pode revelar o valor de 1 casas!\n");
                    x=1;
                    break;
                }
                case 4:{
                    printf("Saindo do jogo!!!\n");
                    x=4;
                    break;
                }
                default:
                        printf("Escolha invalida!!!\n");
                }
        }while(x!=1 && x!=2 && x!=3 && x!=4);
    preencher(valores,valorKza);
    embaralharValor(valores,tam,valorKza);
    limpar();
    printf("Digite os valores das casas que deseja revelar dentre 0 , 1 , 2 , 3, 4 e 6:\n");
    for(int i=0;i<x;i++){
        do{
            scanf("%d",&casa[i]);
            if (casa[i]==5 || casa[i]>6) printf("Digite um numero valido!");
        }while(casa[i]==5 || casa[i]>6);
    }
    limpar();
    for(int i=0;i<x;i++){
        if(casa[i]==0)printf("A casa com valor 0  e: %c\n", valores[0]);
        else if (casa[i]==1) printf("A casa com valor 1: %c\n", valores [1]);
        else if (casa[i]==2) printf("A casa com valor 2: %c\n", valores [2]);
        else if (casa[i]==3) printf("A casa com valor 3: %c\n", valores [3]);
        else if (casa[i]==4) printf("A casa com valor 4: %c\n", valores [4]);
        else if (casa[i]==6) printf("A casa com valor 6: %c\n", valores [5]);
        }
    embaralhar(pilha);
    preparaJogo(m);
    fasedeExpansao(m,pilha);
    intriga(m,pilha,valorKza,valores);

}



