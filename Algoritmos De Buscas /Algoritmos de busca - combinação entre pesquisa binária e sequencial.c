/*
Implemente a função que receba quatro parâmetros:
número inteiro a ser procurado, vetor de inteiros (v[] ou *v),
tamanho do vetor (n) e um número inteiro representando tamanho mínimo (m).
Nessa função, enquanto o espaço de busca (espaço coberto entre os índices esquerdo e direito em uma busca binária,
ou seja, direito - esquerdo + 1) for maior que m, o método de busca binária deve ser aplicada.
Quando o espaço de busca ficar menor ou igual a m, a busca sequencial deverá ser executada.
Se a busca sequencial for aplicada, o espaço de busca deverá ser impresso (caso houver).
Ao final a posição do item procurado no vetor é retornada. Caso o item não seja encontrado,
a função deverá retornar -1.

Input Format
Na primeira linha deve ser lido um número inteiro que deverá ser procurado. Na segunda linha deve ser lido o tamanho do vetor. Na terceira devem ser lidos os elementos do vetor. Na quarta linha deve ser lida o tamanho mínimo da partição (m) para fazer a busca binária.

Output Format

Na primeira linha deve ser impresso o subvetor referente ao espaço de busca a partir do momento em que
a busca sequencial é executada. Na próxima linha deve ser impressa a posição retornada pela função.
Caso a busca sequencial não tenha sido executada, apenas a posição retornada pela função deve ser impressa.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int combinacao(int key, int v[], int n, int m)
{
    int ini = 0;
    int fim = n - 1;

    while(fim - ini + 1 > m)
    {
        int meio = (ini + fim) / 2;

        if(v[meio] == key)
            return meio;
        else if(v[meio] < key)
            ini = meio + 1;
        else
            fim = meio - 1;
    }

    for(int i = ini; i <= fim; i++)
        printf("%d ", v[i]);

    printf("\n");

    for(int i = ini; i<=fim; i++)
    {
        if(v[i] == key)
            return i;
    }

    return -1;
}

int main(void)
{
    int key, n, m;

    scanf("%d", &key);

    scanf("%d", &n);

    int v[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &m);

    printf("%d\n", combinacao(key, v, n, m));

    return 0;
}
