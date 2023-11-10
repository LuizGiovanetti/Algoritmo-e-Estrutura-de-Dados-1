/*
Implemente uma função recursiva que calcule o máximo divisor comum entre dois números inteiros:
-> mdc(x, y) = y, se x >= y e x mod y = 0 -> mdc(x, y) = mdc(y, x), se x < y -> mdc(x, y) = mdc(x, x mod y),
caso contrário

Input Format
Na primeira linha devem ser lidos dois números inteiros.

Output Format
Imprimir o máximo divisor comum entre os dois números.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return mdc(b, a % b);
}

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d", mdc(a, b));

    return 0;
}
