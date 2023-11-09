/*
Implemente uma fun��o recursiva que calcule o resto da divis�o entre dois n�meros inteiros.

Input Format
Na primeira linha deve ser lido um n�mero inteiro N referente a quantidade de leituras de entradas.
Para cada uma das N pr�ximas linhas, ler dois n�meros inteiros (a e b)

Output Format
Em cada uma das N linhas, imprimir o resultado do resto da divis�o dos respectivos n�meros inteiros.
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
