/*
Implemente a função que receba quatro parâmetros: número inteiro a ser procurado, vetor de inteiros (v[] ou *v), tamanho do vetor (n) e um número inteiro representando tamanho mínimo (m).
Nessa função, enquanto o espaço de busca (espaço coberto entre os índices esquerdo e direito em uma busca binária, ou seja, direito - esquerdo + 1) for maior que m, o método de busca binária deve ser aplicada. 
Quando o espaço de busca ficar menor ou igual a m, a busca sequencial deverá ser executada. Se a busca sequencial for aplicada, o espaço de busca deverá ser impresso (caso houver). 
Ao final a posição do item procurado no vetor é retornada. Caso o item não seja encontrado, a função deverá retornar -1.

Input Format
Na primeira linha deve ser lido um número inteiro que deverá ser procurado. Na segunda linha deve ser lido o tamanho do vetor. Na terceira devem ser lidos os elementos do vetor. 
Na quarta linha deve ser lida o tamanho mínimo da partição (m) para fazer a busca binária.

Output Format
Na primeira linha deve ser impresso o subvetor referente ao espaço de busca a partir do momento em que a busca sequencial é executada. Na próxima linha deve ser impressa a posição retornada pela função.
Caso a busca sequencial não tenha sido executada, apenas a posição retornada pela função deve ser impressa.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int combinar(int item, int *v, int n, int min)
{
    int pivo;
    int esq = 0;
    int dir = n - 1;
    
    while((dir - esq + 1) > min)
    {
        pivo = esq + (dir - esq) / 2;
        
        if(item == v[pivo])
            return pivo;
        else if(item < v[pivo])
            dir = pivo - 1;
        else
            esq = pivo + 1;
    }
    
    for(int i = esq; i <= dir; i++)
        printf("%d ", v[i]);
    
    printf("\n");
    
    for(int i = esq; i <= dir; i++)
    {
        if(item == v[i])
            return i;
    }
    
    return -1;
}

int main(void)
{
    int item, n, min;
    
    scanf("%d %d", &item, &n);
    
    int *v = (int*)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    scanf("%d", &min);
    
    printf("%d", combinar(item, v, n, min));
    
    free(v);
    
    return 0;
}
