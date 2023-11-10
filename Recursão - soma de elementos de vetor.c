/*
Implemente uma função recursiva que retorne a soma de todos os elementos de um vetor.

Input Format
Na primeira linha, ler o tamanho do vetor.
Na segunda linha, ler os elementos do vetor.

Output Format
Imprimir o resultado da soma de todos os elementos do vetor
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_rec_vet(int *v, int n, int i, int soma)
{
    if(i == n)
    {
        return soma;
    }
    else
        return soma_rec_vet(v, n, i+1, soma+v[i]);
}

int main(void)
{
    int n;
    
    scanf("%d", &n);
    
    int *v = (int*)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    printf("%d", soma_rec_vet(v, n, 0, 0));
       
    free(v);
    
    return 0;
}
