/*
Implemente uma função recursiva que receba dois números naturais: a e n.
A função deverá calcular a potência de a em relação à n (a^n, ou "a" elevada à "n") multiplicações sucessivas.
Exemplo para a = 5 e n = 3: 5 * 5 * 5.

Input Format
Na primeira linha devem ser lidos dois números inteiros >= 0.

Output Format
Imprimir o resultado da função.
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
