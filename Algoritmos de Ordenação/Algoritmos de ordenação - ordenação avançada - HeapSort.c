/*
Implemente um dos algoritmos de ordenação avançados apresentados em sala de aula (quicksort, shellsort ou heaport)

Input Format
Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.

Output Format
Imprimir o vetor ordenado.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void heapify(int *v, int n, int raiz)
{
    int maior = raiz;
    int esquerda = (2 * raiz) + 1;
    int direita = (2 * raiz) + 2;

    if((esquerda < n) && (v[esquerda] > v[maior]))
        maior = esquerda;
    
    if((direita < n) && (v[direita] > v[maior]))
        maior = direita;
    
    if(maior != raiz)
    {
        troca(&v[raiz], &v[maior]);
        heapify(v, n, maior);
    }
}

void heapSort(int *v, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        troca(&v[0], &v[i]);
        heapify(v, i, 0);
    }
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

    int *v = malloc(sizeof(int) *n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    heapSort(v, n);

    imprimir_vet(v, n);
    
    free(v);

    return 0;
}
