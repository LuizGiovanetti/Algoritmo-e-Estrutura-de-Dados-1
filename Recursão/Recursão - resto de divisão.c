/*
Implemente uma função recursiva que calcule o resto da divisão entre dois números inteiros.

Input Format
Na primeira linha deve ser lido um número inteiro N referente a quantidade de leituras de entradas.
Para cada uma das N próximas linhas, ler dois números inteiros (a e b)

Output Format
Em cada uma das N linhas, imprimir o resultado do resto da divisão dos respectivos números inteiros.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int resto_div(int a, int b)
{
    int aux;
    if(a == 0)
        return a;
    else if(a > b)
    {
        aux = a % b;
        return resto_div(aux, b);
    }
    else
        return a % b;
}

int main(void)
{
    int a, b, n;

    scanf("%d", &n);

    for(int i=0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", resto_div(a, b));
    }

    return 0;
}
