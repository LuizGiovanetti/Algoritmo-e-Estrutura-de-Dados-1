/*
Um treinador de voleibol gostaria de manter estatísticas sobre sua equipe. 
A cada jogo, seu auxiliar anota quantas tentativas de saques, bloqueios e ataques cada um de seus jogadores fez, bem como quantos desses saques, bloqueios e ataques tiveram sucesso (resultaram em pontos). 
Seu programa deve mostrar qual o percentual de saques, bloqueios e ataques do time todo tiveram sucesso.

O programa deve ter a seguinte struct:
typedef struct {
    char nome[255];
    int saquesTotal;
    int bloqueiosTotal;
    int ataquesTotal;
    int saquesSucesso;
    int bloqueiosSucesso;
    int ataquesSucesso;
}Jogador;

A taxa de sucesso de cada jogador deve ser calculada em porcentagem (%) para cada um individualmente.
Para isso crie uma função que recebe a struct como REFERÊNCIA e preencha as variáveis dentro dessa função.

Input Format
A entrada é dada pelo número de jogadores N, seguido pelo nome de cada um dos jogadores.
Abaixo do nome de cada jogador, seguem duas linhas com três inteiros cada. 
Na primeira linha S, B e A representam a quantidade de tentativas de saques, bloqueios e ataques e na segunda linha, S1, B1 e A1 com o número de saques, bloqueios e ataques deste jogador que tiveram sucesso.

Output Format
A saída deve conter o percentual total de saques, bloqueios e ataques do time todo que resultaram em pontos, conforme mostrado nos exemplos.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    char nome[255];
    int saquesTotal;
    int bloqueiosTotal;
    int ataquesTotal;
    int saquesSucesso;
    int bloqueiosSucesso;
    int ataquesSucesso;
}Jogador;

void percentual(Jogador *jogadores, int n)
{
    float pS, pB, pA;
    int auxST = 0, auxBT = 0, auxAT = 0, auxSS = 0, auxBS = 0, auxAS = 0;
    
    for(int i = 0; i < n; i++)
    {
        auxST += jogadores[i].saquesTotal;
        auxSS += jogadores[i].saquesSucesso;
        auxBT += jogadores[i].bloqueiosTotal;   
        auxBS += jogadores[i].bloqueiosSucesso;
        auxAT += jogadores[i].ataquesTotal;
        auxAS += jogadores[i].ataquesSucesso;
    }
    
    pS = (float)(100 * auxSS) / auxST;
    pB = (float)(100 * auxBS) / auxBT;
    pA = (float)(100 * auxAS) / auxAT;
    
    printf("Pontos de Saque: %.2f%\n", pS);
    printf("Pontos de Bloqueio: %.2f%\n", pB);
    printf("Pontos de Ataque: %.2f%\n", pA);
}

int main(void)
{
    int n;
    
    scanf("%d", &n);
    
    Jogador *jogadores;
    
    jogadores = (Jogador*)malloc(sizeof(Jogador) * n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%s", jogadores[i].nome);
        scanf("%d %d %d", &jogadores[i].saquesTotal, &jogadores[i].bloqueiosTotal, &jogadores[i].ataquesTotal);
        scanf("%d %d %d", &jogadores[i].saquesSucesso, &jogadores[i].bloqueiosSucesso, &jogadores[i].ataquesSucesso);
    }
    
    percentual(jogadores, n);
    
    free(jogadores);
    
    return 0;
}
