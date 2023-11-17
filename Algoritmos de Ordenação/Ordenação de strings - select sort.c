/*
Implemente o algoritmo selection sort para ordenar vetor de strings.

Input Format
Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler as strings do vetor.

Output Format
Imprimir o vetor após a ordenação.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int comparar_char(char c1, char c2)
{
    if(c1 < c2)
        return -1;
    else if(c1 == c2)
        return 0;
    else
        return 1;
}

int comparar(char str1[], char str2[])
{
    int i;
    for(i = 0; (str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'); i++);

    return comparar_char(str1[i], str2[i]);
}

void troca(char **vstr, int p1, int p2)
{
    char *str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void select_sort(char **vstr, int n)
{
    int p, i, j;

    for(i = 0; i < n - 1; i++)
    {
        p = i;

        for(j = i; j < n; j++)
        {
            if(comparar(vstr[p], vstr[j]) > 0)
                p = j;
        }

        if(p != i)
            troca(vstr, p, i);
    }
}

int main(void)
{
    int n;
    char **vstr;

    scanf("%d", &n);

    vstr = (char**) malloc(sizeof(char*) * n);

    for(int i = 0; i < n; i++)
    {
        vstr[i] = (char*) malloc(sizeof(char) * 50);
        scanf("%s", vstr[i]);
    }

    select_sort(vstr, n);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", vstr[i]);
    }

    free(vstr);

    return 0;
}
