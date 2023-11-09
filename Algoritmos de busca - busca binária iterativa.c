/*
Implemente a versão iterativa da busca binária.

Input Format
Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor.
Na terceira linha deve ser lido o número de casos de teste (quantidade de chaves que deverão ser procuradas).
A partir da próxima linha, as chaves que serão procuradas devem ser lidas.

Output Format
Para cada chave procurada (caso de teste) deve ser impressa a posição no vetor ou -1 (se não for encontrada)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int busca_bi_it(int x, int v[], int n)
{
    int ini = 0;
    int fim = n - 1;
    int m;

    while(ini <= fim)
    {
        m = (ini + fim) / 2;

        if(x == v[m])
            return m;

        else if(x < v[m])
            fim = m - 1;

        else
            ini = m + 1;

    }

    return -1;

}

int main(void)
{
    int n, m, x, *v;

    scanf("%d", &n);

    v = (int*) malloc(sizeof(int) *n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    while(m > 0)
    {
        scanf("%d", &x);
        printf("%d\n", busca_bi_it(x, v, n));
        m--;
    }

    free(v);

    return 0;
}
