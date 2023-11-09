/*
Implemente uma fun��o que receba um arranjo de n�meros inteiros.
Nessa fun��o dever� ser implementado, utilizando recurs�o,
o m�todo de recupera��o recorrente mover-para-frente, no qual,
cada vez que um registro � recuperado com sucesso, ele � movimentado para a primeira posi��o.

Input Format
Na primeira linha, ler um n�mero inteiro (n) referente ao tamanho do arranjo.
Na segunda linha, ler os n elementos do vetor
Na terceira linha deve ser lida a quantidade de chaves que dever�o ser procuradas).
A partir da pr�xima linha, as chaves que ser�o procuradas devem ser lidas.


Output Format
Ap�s execu��o do algoritmo para cada caso teste, imprimir o arranjo.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mover_frente(int n, int v[], int key, int i)
{
     if(n <= 0 && n < i)
        return -1;

    int cont = 0;
    for(int j = 0; j < n; j++)
    {
        if(v[j] == key)
        {
            cont++;
        }
    }

    if(cont == 0)
        return 0;
    else if(v[i] == key)
    {
        for(int j = i; j > 0; j--)
            v[j] = v[j-1];

        v[0] = key;
        return 1;
    }
    else
        return mover_frente(n, v, key, i + 1);

}

void imprimir_vetor(int n, int v[n])
{
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

int main(void)
{
    int n, qntKey, key;

    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &qntKey);

    for(int i = 0; i < qntKey; i++)
    {
        scanf("%d", &key);
        mover_frente(n, v, key, 0);
    }

    imprimir_vetor(n, v);

    return 0;
}
