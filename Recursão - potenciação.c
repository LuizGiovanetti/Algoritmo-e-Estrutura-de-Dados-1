/*
Implemente uma fun��o recursiva que receba dois n�meros naturais: a e n.
A fun��o dever� calcular a pot�ncia de a em rela��o � n (a^n, ou "a" elevada � "n") multiplica��es sucessivas.
Exemplo para a = 5 e n = 3: 5 * 5 * 5.

Input Format
Na primeira linha devem ser lidos dois n�meros inteiros >= 0.

Output Format
Imprimir o resultado da fun��o.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pot(unsigned int a, unsigned int n)
{
    if(n==0)
        return 1;
    else
        return a * pot(a, n - 1);
}

int main(void){
    int a, n;

    scanf("%d %d", &a, &n);

    printf("%d", pot(a, n));


    return 0;
}
