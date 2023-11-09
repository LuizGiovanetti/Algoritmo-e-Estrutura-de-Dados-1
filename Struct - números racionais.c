/*
Crie uma struct para representar um n�mero racional, ou seja,
nessa estrutura deve haver os seguintes campos: numerador e denominador.
Em seguida, crie uma fun��o que receba dois n�meros racionais.
A fun��o dever� retornar um outro n�mero racional resultante da divis�o dos n�meros fornecidos como entrada.

Input Format
A primeira linha � composta pelo numerador e denominador, respectivamente, do primeiro n�mero racional.
A segunda linha � composta pelo numerador e denominador, respectivamente, do segundo n�mero racional.

Constraints
As entradas lidas devem ser armazenadas em var�aveis do tipo de estrutura que voc� criou.

Output Format
N�mero racional resultante da divis�o dos n�meros fornecidos como entrada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
}rac;

rac divisao(rac r1, rac r2){
    rac r3;

    r3.num = r1.num * r2.den;
    r3.den = r2.num * r1.den;

    return r3;
}

int main() {
    rac r1, r2, r3;

    scanf("%d %d", &r1.num, &r1.den);
    scanf("%d %d", &r2.num, &r2.den);

    r3 = divisao(r1, r2);

    printf("%d %d", r3.num, r3.den);

    return 0;
}
