/*
Implemente, utilizando recursão, um dos algoritmos de ordenação simples apresentados em sala de aula (bublesort, selection sort ou insertion sort).

Input Format
Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.

Constraints
Dica: para os códigos apresentados em aulas, transforme apenas o for externo em recursão. Em outras palavras, na sua função pode ter, no máximo, apenas um laço for.

Output Format
Imprimir o vetor ordenado.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int select_rec(int *v, int i, int n)
{
    if (i >= n - 1)
        return -1;
    
    int min = i;
    
    for (int j = i + 1; j < n; j++)
    {
        if (v[j] < v[min])
            min = j;
    }

    if(min != i)
    {
        int aux = v[min];
        v[min] = v[i];
        v[i] = aux;
    }
    
    return select_rec(v, i + 1, n);
    
}

void imprimir_vet(int v[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int main(void)
{
    int n;
    
    scanf("%d", &n);
    
    int *v = malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    select_rec(v, 0, n);
      
    imprimir_vet(v, n);
    
    free(v);
    
    return 0;
}
