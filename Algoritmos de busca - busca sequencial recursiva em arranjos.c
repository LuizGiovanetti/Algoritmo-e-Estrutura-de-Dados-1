/*
Implemente uma função que receba, pelo menos, uma chave e um vetor do tipo inteiro.
A função deverá efetuar, utilizando recursão, busca sequencial em vetores.

Input Format
Na primeira linha deve ser lido o tamanho do vetor.
Na segunda linha devem ser lidos os elementos do vetor.
Na terceira linha deve ser lido o número de casos de teste (quantidade de chaves que deverão ser procuradas).
A partir da próxima linha, as chaves que serão procuradas devem ser lidas.

Output Format
Para cada chave procurada (caso de teste) deve ser impressa a posição no vetor ou -1 (se não for encontrada)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int buscar(int key, int v[], int i, int n)
{
    if(i < n)
    {
        if(key == v[i])
            return i;
        else
            return buscar(key, v, i+1, n);
    }
    else
        return -1;

}

int buscar_2(int key, int v[], int n)
{
    if(n > 0)
    {
        if(v[n-1] == key)
            return n-1;
        else
            return buscar_2(key, v, n-1);
    }
    else
        return -1;
}

int main(void){
    int n;
    int *v;

    scanf("%d", &n);

    v = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int c; //casos de teste

    scanf("%d", &c);

    while(c > 0)
    {
        int key;

        scanf("%d", &key);

        printf("%d\n", buscar(key, v, 0, n));
        c--;
    }

    free(v);

    return 0;
}
