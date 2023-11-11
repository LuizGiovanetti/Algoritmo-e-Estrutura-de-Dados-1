/*
Implemente uma combinação entre o quicksort e um método de ordenação simples. 
A função deve, pelo menos, receber três parâmetros: vetor de stings (**vstr), tamanho do vetor (n) e um número inteiro representando tamanho mínimo (m). 
Nessa função, enquanto a partição for maior que m, o método de ordenação que deve ser aplicado é quicksort.
Caso contrário, um método de ordenação simples (bubblesort, select sort ou insert sort) deve ser utilizado na partição.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. A partir segunda linha, devem ser lidos os elementos do vetor. Após a leitura do vetor, deve ser lido um número inteiro que represente o tamanho mínimo de partição.

Output Format
Imprimir o vetor ordenado.
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

int comparar(char *str1, char *str2)
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

void comb_Quick(char **vstr, int esq, int dir, int min)
{
    int i = esq;
    int j = dir;
    
    if(dir - esq > min)
    {
        char pivo[50];
        strcpy(pivo, vstr[(esq + dir) / 2]);

        do{
            while(comparar(pivo, vstr[i]) > 0)
                i++;
            while(comparar(vstr[j], pivo) > 0)
                j--;

            if(i <= j)
            {
               troca(vstr, i, j);
                i++;
                j--;
            }

        }while(i <= j);

        if(j > esq)
            comb_Quick(vstr, esq, j, min);

        if(i < dir)
            comb_Quick(vstr, i, dir, min);

    }
    else
    {
        for(i = esq; i < dir; i++)
        {
            int p = i;

            for(j = i; j <= dir; j++)
            {
                if(comparar(vstr[p], vstr[j]) > 0)
                    p = j;
            }
            if(p != j)
            {
                troca(vstr, p, i);
            }
        }
    }
}

int main(void)
{
    int n, min;
    char **vstr;

    scanf("%d", &n);

    vstr = (char**) malloc(sizeof(char*) * n);

    for(int i = 0; i < n; i++)
    {
        vstr[i] = (char*) malloc(sizeof(char) * 50);
        scanf("%s", vstr[i]);
    }

    scanf("%d", &min);
    
    comb_Quick(vstr, 0, n - 1, min);

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", vstr[i]);
    }

    free(vstr);

    return 0;
}
