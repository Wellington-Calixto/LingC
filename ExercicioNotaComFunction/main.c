#include <stdio.h>
#include <stdlib.h>
int bilhete[6][10]={{0}};
int aposta[6];
int sorteio [6];
int linha;
int coluna;
int i,j;
int num=1;
int jogo=0;
int qtd=0;
void sorteioDaMegaCena();
void sorteioDosNumeros();
void imprimir(int vt);

int main()
{

    sorteioDaMegaCena();
}

void sorteioDaMegaCena()
{
    srand(time(NULL));
    while(jogo<=5){
        sorteioDosNumeros();
    jogo++;
   }
}

void sorteioDosNumeros()
{
    printf("-------------------------------- %da Rodada do Jogo --------------------------------\n\n", jogo+1);

    for(i=0;i<6;i++){
        printf("Digite a sua aposta para o %do jogo \n", jogo+1);
        scanf("%d", &aposta[i]);
    }

    printf("\n|");

    for (i = 0; i<6; i++){
        sorteio[i] = rand()%60;
        printf(" %d |", sorteio[i]);
    }

    printf("\n\n");

    for (i=0;i<6;i++){
        if (sorteio[i] % 10 == 0){
           linha = (sorteio[i] / 10)-1;
           coluna = 9;

        }
        else{
            coluna = (sorteio[i] % 10 -1 );
            linha = ((sorteio[i]-coluna)/10);

        }
        bilhete[linha][coluna] = 1;
    }

    for (i=0;i<6;i++){
        for(j=0;j<6;j++){
            if (sorteio[j] == aposta[i]){
                qtd+=1;
            }

        }
    }
    for(i=0;i<6;i++){
        for(j=0;j<10;j++){
            printf("%4d", bilhete[i][j]);
        }
        printf("\n");
    }
    imprimir(qtd);
}

void imprimir(int vt)
{
    if (qtd>2){
            printf("Voce acertou %d numeros\n\n",qtd);
        }else{
            if(qtd==0){
            printf("Voce nao acertou nenhum numeros\n\n");
            }else {
            printf("Voce acertou menos de 2 numeros\n\n");
            }
        }
        qtd=0;
}
