/*
Implemente uma função que receba um arranjo de números inteiros.
Nessa função deverá ser implementado, utilizando recursão,
o método de recuperação recorrente mover-para-frente, no qual,
cada vez que um registro é recuperado com sucesso, ele é movimentado para a primeira posição.

Input Format
Na primeira linha, ler um número inteiro (n) referente ao tamanho do arranjo.
Na segunda linha, ler os n elementos do vetor
Na terceira linha deve ser lida a quantidade de chaves que deverão ser procuradas).
A partir da próxima linha, as chaves que serão procuradas devem ser lidas.


Output Format
Após execução do algoritmo para cada caso teste, imprimir o arranjo.
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
