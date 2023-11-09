/*
Implemente uma combina��o entre o quicksort e um m�todo de ordena��o simples.
A fun��o deve, pelo menos, receber tr�s par�metros: vetor de inteiros (v[] ou *v),
tamanho do vetor (n) e um n�mero inteiro representando tamanho m�nimo (m). Nessa fun��o,
enquanto a parti��o for maior que m, o m�todo de ordena��o que deve ser aplicado � quicksort.
Caso contr�rio, um m�todo de ordena��o simples (bubblesort, select sort ou insert sort) deve ser utilizado na parti��o.

Input Format
Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.
Na terceira linha deve ser lido um n�mero inteiro que represente o tamanho m�nimo de parti��o.

Output Format
Imprimir o vetor ordenado.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void jeffersort(int v[], int esq, int dir, int m)
{
    int i = esq, j = dir, pivo;

    if(dir - esq > m)
    {
        pivo = v[(esq + dir) / 2];

        do{
            while(v[i] < pivo)
                i++;
            while(v[j] > pivo)
                j--;

            if(i <= j)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;
            }

        }while(i <+j);

        if(j > esq)
            jeffersort(v, esq, j, m);

        if(i < dir)
            jeffersort(v, i, dir, m);

    }
    else
    {
        for(i = esq; i < dir; i++)
        {
            int p = i;

            for(j = i; j <= dir; j++)
            {
                if(v[p] > v[j])
                    p = j;
            }
            if(p != j)
            {
                int aux = v[p];
                v[p] = v[i];
                v[i] = aux;
            }
        }
        /*
        int troca = 1;

        for(i = esq; (i < dir) && (troca); i++)
        {
            troca = 0;

            for(j = esq; j <= dir - i - 1; j++)
                if(v[j] > v[j + 1])
                {
                    int aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                    troca = 1;
                }
        }*/
    }
}

int main(void)
{
    int n, m;
    int *v;

    scanf("%d", &n);

    v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    jeffersort(v, 0, n - 1, m);

    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    free(v);

    return 0;
}
