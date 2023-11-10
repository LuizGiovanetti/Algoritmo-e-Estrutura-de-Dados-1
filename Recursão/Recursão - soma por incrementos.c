/*
A soma de dois números inteiros pode ser feita através de sucessivos incrementos, por exemplo, 7 + 4 = (++(++(++(++7)))) = 11. 
Implemente uma função que calcule a soma entre dois números naturais, através de incrementos, utilizando recursão.

Input Format
Na primeira linha deve ser lido um número inteiro N referente a quantidade de leituras de entradas.
Para cada uma das N próximas linhas, ler dois números inteiros (a e b)


Output Format
Em cada uma das N linhas, imprimir o resultado da soma dos respectivos números inteiros.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_rec(int a, int b, int i)
{
    if((a + b) == i)
        return i;
    else
        return soma_rec(a, b, i+1);
}

int main(void)
{
    int n, a, b;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", soma_rec(a, b, 0));
    }
     
    return 0;
}
