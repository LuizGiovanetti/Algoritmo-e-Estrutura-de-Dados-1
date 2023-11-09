/*
Gladstone est� desenvolvendo um jogo simples de RPG em que h� batalhas, os quais s�o por turnos,
onde, em cada luta, os jogadores se revezam em cada ataque. Cada personagem, al�m do nome (string),
tem os seguintes atributos representados por n�meros inteiros: energia, defesa e for�a. Em cada ataque,
a energia do personagem que est� sofrendo o golpe � reduzida.
O dano (redu��o de energia) � dado pela subtra��o entre o atributo de for�a (F) do atacante
e o atributo de defesa do personagem atacado, o qual pode ter redu��o de energia.
Caso a diferen�a entre for�a (atacante) e defesa (atacado) seja menor igual a zero, o dano ser� de 1 ponto.
Se o dano resultar em energia negativa, o valor da mesma para o personagem derrotado dever� ser "0". Em cada batalha,
o perdedor ser� o personagem que tiver a energia zerada ou que tiver o menor valor de energia. Tamb�m, poder� ocorrer empate.
� importante ressaltar que o personagem com energia zerada n�o pode mais atacar!

Implemente uma fun��o que receba duas vari�veis referentes aos personagens e um n�mero inteiro
que represente a quantidade de turnos, onde o primeiro personagem fornecido como par�metro come�a o ataque.
Ao final, a fun��o dever� imprimir o resultado, indicando o nome personagem vencedor ou se houve empate.

Input Format
Nas duas primeiras linhas, devem ler lidos os dados dos personagens. "
nome (vetor de char) energia (int) defesa (int), for�a (int)".
Na linha seguinte, deve ser lida a quantidade de rodadas que dever� ter a batalha.

Output Format
Na primeira e segunda linha,
imprimir o nome e a energia restante do primeiro e do segundo personagem, ap�s a execu��o das rodadas de ataques.
Na terceira lunha,
imprimir o nome do personagem vencedor ou "empate",
caso os personagens tiverem a mesma quantidade de energia
(neste exerc�cio n�o levando em conta que os personagens possam iniciar uma batalha com diferentes valores de energia).
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM_MAX 100

typedef struct{
    char nome[TAM_MAX];
    int energia;
    int defesa;
    int forca;
}PER;

void rodada(PER a, PER b, int rod)
{
    int i;
    int ataque=0;
    for(i = 0; i<rod; i++)
    {
        if(b.energia <= 0)
        {
            b.energia=0;
            break;
        }

        if(a.defesa>b.forca)
        {
            ataque = 1;
            b.energia = b.energia - ataque;
        }
        else
        {
            a.energia = a.energia + (a.defesa - b.forca);
        }


        if(b.defesa>a.forca)
        {
            ataque = 1;
            a.energia = a.energia - ataque;
        }
        else
        {
            b.energia = b.energia + (b.defesa - a.forca);
        }

    }

    if(a.energia > b.energia){
        printf("%s %d\n", a.nome, a.energia);
        printf("%s %d\n", b.nome, b.energia);
        printf("%s\n", a.nome);
    }
    else if(b.energia > a.energia){
        printf("%s %d\n", a.nome, a.energia);
        printf("%s %d\n", b.nome, b.energia);
        printf("%s\n", b.nome);
    }
    else if(b.energia==a.energia){
        printf("%s %d\n", a.nome, a.energia);
        printf("%s %d\n", b.nome, b.energia);
        printf("empate\n");
    }
}

int main(void)
{
    PER a;
    PER b;
    int rod;

    scanf("%s %d %d %d", a.nome, &a.energia, &a.defesa, &a.forca);

    scanf("%s %d %d %d", b.nome, &b.energia, &b.defesa, &b.forca);

    scanf("%d", &rod);

    rodada(a, b, rod);

    return 0;
}

