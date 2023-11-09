/*
Implemente uma fun��o que receba tr�s vari�veis: duas do tipo float e uma do tipo int.
A fun��o dever� retornar a parte inteira (int) e a fracion�ria (float) de um n�mero do real.
Para isso utilize o seguinte prot�tipo:

void frac(float n, int * in, float * fr)

Input Format
A primeira linha da entrada cont�m um �nico inteiro N, indicando o n�mero de casos de teste.

Constraints
Os floats devem ser impressos considerando 3 casas decimais, ou seja, usando ".3f"

Output Format
Para cada caso de teste de entrada dever� ser apresentada uma linha de sa�da, no seguinte formato: N=n I=in F=fr
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void frac(float n, int *in, float *fr){
    *in = (int) n;
    *fr = n - (float) *in;
}
int main() {
    int m, in;
    float n, fr;

    scanf("%d", &m);
    while(m>0){
        scanf("%f", &n);
        frac(n, &in, &fr);
        printf("N=%.3f I=%d F=%.3f\n", n, in, fr);
        m--;
    }
    return 0;
}
