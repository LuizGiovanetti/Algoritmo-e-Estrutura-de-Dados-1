/*
Implemente um TAD (tipo abstrato de dados) para números racionais.
O TAD deve ter as seguintes funções: criar número racional; soma; subtração; divisão; e mutiplicação entre números racionais.
Para isso, pode ser considerada a estrutura e os protótipos de função abaixo:

typedef struct{
    int num, den; // numerador e denominador, respectivamente
}RAC;

RAC *criar(int num, int den);

RAC *somar(RAC *r1, RAC *r2);

RAC *subtrair(RAC *r1, RAC *r2);

RAC *multiplicar(RAC *r1, RAC *r2);

RAC *dividir(RAC *r1, RAC *r2);

Input Format
A primeira linha é composta pelo numerador e denominador, respectivamente, do primeiro número racional.
A segunda linha é composta pelo numerador e denominador, respectivamente, do segundo número racional.

Output Format
Na primeira linha deve ser impresso o primeiro número racional no seguinte formato: "r1: num/den".

Na segunda linha deve ser impresso o segundo número racional no seguinte formato: "r2: num/den".

Na terceira linha deve ser impresso o resultado da soma entre os números racionais r1 e r2 seguindo o seguinte formato: "r1+r2=num/den".

Na quarta linha deve ser impresso o resultado da subtração entre os números racionais r1 e r2 seguindo o seguinte formato: "r1-r2=num/den".

Na quinta linha deve ser impresso o resultado da multiplicação entre os números racionais r1 e r2 seguindo o seguinte formato: "r1*r2=num/den".

Na sexta linha deve ser impresso o resultado da divisão entre os números racionais r1 e r2 seguindo o seguinte formato: "r1/r2=num/den".
*/
/*#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
}RAC;

RAC *criar(int num, int den)
{
    RAC *r = (RAC *)malloc(sizeof(RAC));
    r->num = num;
    r->den = den;
    return r;
}

RAC *somar(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den + r1->den * r2->num;
    int den = r1->den * r2->den;

    RAC *r = criar(num, den);
    return r;
}

RAC *subtrair(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den - r1->den * r2->num;
    int den = r1->den * r2->den;

    RAC *r = criar(num, den);
    return r;
}

RAC *multiplicar(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->num;
    int den = r1->den * r2->den;

    RAC *r = criar(num, den);
    return r;
}

RAC *dividir(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den;
    int den = r1->den *r2->num;

    RAC *r = criar(num, den);
    return r;
}

int main(void)
{
    int den1, num1, den2, num2;
    scanf("%d %d %d %d", &num1, &den1, &num2, &den2);

    if(den1 == 0 || den2 == 0)
    {
        return 1;
    }

    RAC *r1 = criar(num1, den1);
    RAC *r2 = criar(num2, den2);

    printf("r1: %d/%d\n", r1->num, r1->den);
    printf("r2: %d/%d\n", r2->num, r2->den);

    RAC *soma = somar(r1, r2);
    printf("r1+r2=%d/%d\n", soma->num, soma->den);

    RAC *subtracao = subtrair(r1, r2);
    printf("r1-r2=%d/%d\n", subtracao->num, subtracao->den);

    RAC *multiplicacao = multiplicar(r1, r2);
    printf("r1*r2=%d/%d\n", multiplicacao->num, multiplicacao->den);

    RAC *divisao = dividir(r1, r2);
    printf("r1/r2=%d/%d\n", divisao->num, divisao->den);

    free(r1);
    free(r2);
    free(soma);
    free(subtracao);
    free(multiplicacao);
    free(divisao);

    return 0;
}*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
}RAC;

RAC *criar(int num, int den)
{
    RAC *r = (RAC *)malloc(sizeof(RAC));
    r->num = num;
    r->den = den;
    return r;
}

RAC *somar(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den + r1->den * r2->num;
    int den = r1->den * r2->den;
    if((num%2 == 0 && den%2==0) && (r1->num != r1->den || r2->num != r2->den))
    {
        num = num/2;
        den = den/2;
    }

    RAC *r = criar(num, den);
    return r;
}

RAC *subtrair(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den - r1->den * r2->num;
    int den = r1->den * r2->den;
    if((num%2 == 0 && den%2==0) && (r1->num != r1->den || r2->num != r2->den))
    {
        num = num/2;
        den = den/2;
    }

    RAC *r = criar(num, den);
    return r;
}

RAC *multiplicar(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->num;
    int den = r1->den * r2->den;

    RAC *r = criar(num, den);
    return r;
}

RAC *dividir(RAC *r1, RAC *r2)
{
    int num = r1->num * r2->den;
    int den = r1->den *r2->num;

    RAC *r = criar(num, den);
    return r;
}

int main(void)
{
    int den1, num1, den2, num2;
    scanf("%d %d %d %d", &num1, &den1, &num2, &den2);

    if(den1 == 0 || den2 == 0)
    {
        return 1;
    }

    RAC *r1 = criar(num1, den1);
    RAC *r2 = criar(num2, den2);

    printf("r1: %d/%d\n", r1->num, r1->den);
    printf("r2: %d/%d\n", r2->num, r2->den);

    RAC *soma = somar(r1, r2);
    printf("r1+r2=%d/%d\n", soma->num, soma->den);

    RAC *subtracao = subtrair(r1, r2);
    printf("r1-r2=%d/%d\n", subtracao->num, subtracao->den);

    RAC *multiplicacao = multiplicar(r1, r2);
    printf("r1*r2=%d/%d\n", multiplicacao->num, multiplicacao->den);

    RAC *divisao = dividir(r1, r2);
    printf("r1/r2=%d/%d\n", divisao->num, divisao->den);

    free(r1);
    free(r2);
    free(soma);
    free(subtracao);
    free(multiplicacao);
    free(divisao);

    return 0;
}


