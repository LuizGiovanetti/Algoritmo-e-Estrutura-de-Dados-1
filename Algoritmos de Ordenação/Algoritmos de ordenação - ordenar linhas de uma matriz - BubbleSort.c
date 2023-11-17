/*
Implemente uma função que receba uma matriz de números inteiros. A função deverá ordenar,
em ordem decrescente, cada linha da matriz.

Input Format
Na primeira linha, devem ser lidos dois números inteiros: l (linhas) e c (colunas).
Para cada uma das l linhas seguintes devem ser lidos c números inteiros.

Output Format
Imprimir a matriz com as linhas ordenadas.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ordenar_linhas_decrescente(int l, int c, int m[l][c])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            for(int k = 0; k < c - 1 - j; k++)
            {
                if(m[i][k] < m[i][k + 1])
                {
                    int aux = m[i][k];
                    m[i][k] = m[i][k + 1];
                    m[i][k + 1] = aux;
                }
            }
        }
    }
}

void imprimir_matriz(int l, int c, int m[l][c])
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int l, c;

    scanf("%d %d", &l, &c);
    int m[l][c];

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
            scanf("%d", &m[i][j]);
    }

    ordenar_linhas_decrescente(l - 1, c, m);
    imprimir_matriz(l, c, m);

    return 0;
}
