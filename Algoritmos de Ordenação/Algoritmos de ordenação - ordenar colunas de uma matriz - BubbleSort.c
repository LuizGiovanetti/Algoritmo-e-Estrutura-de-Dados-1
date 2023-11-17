/*
Implemente uma função que receba uma matriz de números reais. A função deverá ordenar, em ordem decrescente, cada coluna da matriz.

Input Format
Na primeira linha, devem ser lidos dois números inteiros: l (linhas) e c (colunas).
Para cada uma das l linhas seguintes devem ser lidos c números inteiros.

Output Format
Imprimir a matriz com as colunas ordenadas.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troca(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(float **m, int l, int c)
{
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < l - 1; j++)
        {
            for(int k = 0; k < l - j - 1; k++)
            {
                if(m[k][i] < m[k+1][i])
                    troca(&m[k][i], &m[k + 1][i]);
            }
        }
    }
}

void imprimir_mat(float **m, int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
            printf("%.1f ", m[i][j]);
        
        printf("\n");
    }
    
}

void liberar_m(float **m, int l)
{
    for(int i = 0; i < l; i++)
        free(m[i]);
    
    free(m);
}

int main(void)
{
    int l, c;
    
    scanf("%d %d", &l, &c);
    
    float **m = (float**)malloc(sizeof(float*) * l);
    
    for(int i = 0; i < l; i++)
    {
        m[i] = (float*)malloc(sizeof(float) * c);
        for(int j = 0; j < c; j++)
            scanf("%f", &m[i][j]);
    }
    
    bubble_sort(m, l, c);
    
    imprimir_mat(m, l, c);
    
    liberar_m(m, l);
    
    return 0;
}
