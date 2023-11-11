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

void inverter_linha(int l, int c, int m[l][c])
{
    for(int i = 0; i <= l; i++)
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

/*int inverter_linha(int l, int c, int m[l][c])
{
    int aux;
    if(( l < 0) || (c < 0))
        return 0;
    else
    {
        for(int j = 0; j < c; j++)
        {
            int i = 0;
            while((m[l][i] < m[l][i + 1]) && (i < c - 1))
            {
                aux = m[l][i];
                m[l][i] = m[l][i + 1];
                m[l][i + 1] = aux;
                i++;
            }
        }

    }
    return inverter_linha(l - 1, c, m);
}*/

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

    inverter_linha(l - 1, c, m);
    imprimir_matriz(l, c, m);

    return 0;
}
