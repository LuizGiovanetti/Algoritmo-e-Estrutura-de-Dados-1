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

int bubble(int *v, int n, int ini)
{
    if(ini >= n)
        return -1;
    
    int aux;
    
    for(int i = ini + 1; i < n; i++)
    {
        if(v[ini] > v[i])
        {
            aux = v[ini];
            v[ini] = v[i];
            v[i] = aux;
        }
    }
    
    return bubble(v, n, ini + 1);   
}

void imprimir_vet(int *v, int n)
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
        scanf("%d", &v[i]);
    
    bubble(v, n, 0);
    imprimir_vet(v, n);
    
    free(v);

    return 0;
}
