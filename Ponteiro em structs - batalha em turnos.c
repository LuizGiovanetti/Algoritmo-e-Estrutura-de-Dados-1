/*
p�s ter o prot�tipo de jogo de RPG aprovado pelo CEO de uma importante empresa de games,
Gladstone decide fazer melhorias na jogabilidade. Dessa vez o jogo dever� ter mais recursos.
Consequentemente, a estrutura de cada personagem deve ter os seguintes campos:
nome, energia, defesa, for�a e tr�s golpes diferentes (A1, A2, A3), sendo cada um com um valor diferente.
Ap�s a execu��o de um golpe, o dano � dado pela seguinte equa��o:
dano = forca(atacante)+golpe(atacante)-defesa(atacado)
Caso o valor da equa��o acima for negativo, o dano ser� de 1 ponto apenas. Em cada batalha, o perdedor ser� o personagem que tiver a energia zerada ou que tiver o menor valor de energia. Tamb�m, poder� ocorrer empate. � importante ressaltar que o personagem com energia zerada n�o pode mais atacar!
O jogo tamb�m tem mais novidades novidades: o personagem, em vez de atacar, pode tomar uma po��o de cura, que restaura 200 pontos; quem inicia o ataque n�o � necessariamente o primeiro personagem; o valor m�ximo de energia � 1000 (personagem completamente saud�vel).

Implemente fun��es para o gerenciamento de batalha entre dois personagens.
Para isso, devem ser utilizados ponteiros de structs. Exemplo de prot�tipos:
void reduzir_energia(Tipo *p, int pontos_dano); //reduz pontos_dano pontos na sa�de do personagem (valor m�nimo de sa�de: 0)
void restaurar(Tipo *p); //aumenta 200 pontos na sa�de do personagem (valor m�ximo de sa�de: 1000)

Input Format
Nas duas primeiras linhas, devem ler lidos os dados dos personagens.
Cada uma das duas primeiras linhas tem a seguinte segu�ncia:
"nome (vetor de char) energia (int) defesa (int), for�a (int), ataque 1 (int), ataque 2 (int), ataque 3 (int)""
Na linha seguinte, deve ser lida a quantidade de a��es (N) que dever� ter a batalha.
A leitura das pr�ximas N linhas devem ser no formato:
"P A" (o personagem toma uma po��o de cura) ou P A G (o personagem realiza um ataque), onde:
P: do tipo inteiro, representa o personagem que executa a a��o. O valor pode ser 1 (primeiro persongem lido) ou 2
A: � um caractere que representa uma a��o, que pode ser "C" (cura) ou "A" ataque.
Caso a a��o representada pelo caractere "A",
ainda dever� ser definido qual dos 3 tr�s golpes poss�veis deve ser executado, ou seja, o valor deve ser 1, 2 ou 3

Output Format
Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e do segundo personagem,
ap�s a execu��o das rodadas de ataques.
Na terceira lunha, imprimir o nome do personagem vencedor ou "empate",
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
    int ataque_1;
    int ataque_2;
    int ataque_3;
}PER;

int ataque(PER *p1, PER *p2, int atacar)
{
    int dano = 0;
    if(atacar == 1)
    {
        return dano = p1->forca + p1->ataque_1 - p2->defesa;
    }
    else if(atacar == 2)
    {
        return dano = p1->forca + p1->ataque_2 - p2->defesa;
    }
    else if(atacar == 3)
    {
        return dano = p1->forca + p1->ataque_3 - p2->defesa;
    }
    else
        return -1;
}

void reduzir_energia(PER *p, int dano)
{
    p->energia = p->energia - dano;
}

void restaurar(PER *p)
{
    p->energia = p->energia + 200;
    if(p->energia >= 1000)
    {
        p->energia = 1000;
    }
}

void rodada(PER *p1, PER *p2, int rod)
{
    char escolha;
    int i, dano, personagem, ataque1, ataque2;
    for(i = 0; i < rod; i++)
    {
        scanf("%d %c", &personagem, &escolha);
        if(escolha == 'A' && personagem == 1)
        {
            scanf("%d", &ataque1);
            dano = ataque(p1, p2, ataque1);
            reduzir_energia(p2, dano);
        }
        else if(escolha == 'C' && personagem == 1)
        {
            restaurar(p1);
        }
        if(escolha == 'A' && personagem == 2)
        {
            scanf("%d", &ataque2);
            dano = ataque(p2, p1, ataque2);
            reduzir_energia(p1, dano);
        }
        else if(escolha == 'C' && personagem == 2)
        {
            restaurar(p2);
        }

    }
        if(p1->energia > p2->energia){
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("%s\n", p1->nome);
    }
    else if(p2->energia > p1->energia){
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("%s\n", p2->nome);
    }
    else if(p2->energia==p1->energia){
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("empate\n");
    }
}

int main(void)
{
    PER *a = malloc(sizeof(PER));
    PER *b = malloc(sizeof(PER));
    int rod;

    scanf("%s %d %d %d %d %d %d", a->nome, &a->energia, &a->defesa, &a->forca, &a->ataque_1, &a->ataque_2, &a->ataque_3);
    scanf("%s %d %d %d %d %d %d", b->nome, &b->energia, &b->defesa, &b->forca, &b->ataque_1, &b->ataque_2, &b->ataque_3);

    scanf("%d", &rod);

    rodada(a, b, rod);

    free(a);
    free(b);
    return 0;
}
