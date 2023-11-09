/*
Escreva uma função que calcule a área da superfície e o volume de uma esfera de raio R.
A função deve seguir o seguinte protótipo:

void param_esfera(float r, float *area, float *volume);
Equações para o cálculo das medidas, onde pi = 3.14:
area = 4 * pi * R²
volume = (3/4) * pi * R³

Input Format
Na primeira linha da entrada deve ser lido um único float.


Output Format
A área e o volume devem ser impressos, com duas casas decimais, na segunda linha.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14

void param_esfera(float r, float *area, float *volume){
    *area = 4 * pi * r*r;
    *volume = (3.0/4.0) * pi * r*r*r;
}

int main() {
    float r, a, b;

    scanf("%f", &r);

    param_esfera(r, &a, &b);

    printf("%.2f %.2f", a, b);
    return 0;
}
