/*
Implemente um programa que leia tr�s valores do tipo float (A, B e C).
Em seguida fa�a uma fun��o que receba tr�s ponteiros do tipo float.
Essa fun��o dever� dobrar o valor em cada ponteiro e retornar a soma desses valores dobrados.Exemplo:
se a fun��o receber ponteiros com os valores
A=3.0, B=4.0 e C=0.0, ao final da execu��o da fun��o, A=6.0, B=8.0 e C=0.0 e retorno ser� 14.0.

Input Format
A primeira linha cont�m um �nico inteiro N, indicando a quantidade de vezes que ser�o lidos os par�metros da fun��o.
Nas pr�ximas N linhas, ler tr�s valores do tipo float.

Constraints
.

Output Format
Para cada vez em que os par�metros da fun��o forem lidos dever� ser apresentada uma linha de sa�da no seguinte formato:
 "A=X B=Y C=Z SOMA=TOTAL", sendo todos com precis�o de uma casa decimal.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float somar(float *a, float *b, float *c){
    float *x = a;
    float *y = b;
    float *z = c;
    float soma;
    *x = *a + *a;
    *y = *b + *b;
    *z = *c + *c;

    soma = *a + *b + *c;

    *a = *x;
    *b = *y;
    *c = *z;
    return soma;
}

int main() {
    int n, i;
    float soma;

    scanf("%d", &n);
    float a[n], b[n], c[n];
    for(i=0; i<n; i++){
        scanf("%f %f %f", &a[i], &b[i], &c[i]);
    }

    for(i=0; i<n; i++){
        soma=0;
        soma = somar(&a[i], &b[i], &c[i]);
        printf("A=%.1f B=%.1f C=%.1f SOMA=%.1f\n", a[i], b[i], c[i], soma);
    }

    return 0;
}
