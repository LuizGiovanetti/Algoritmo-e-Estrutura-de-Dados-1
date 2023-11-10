/*
Escreva uma função que receba três variáveis (altura, largura e comprimento) do tipo float para a representação de um paralelepípedo reto e três ponteiros do tipo float. Nessa função, cada ponteiro deverá armazenar uma medida relacionada ao palalepípedo, como:
área = 2*altura*largura+2*altura*comprimento+2*largura*comprimento
volume = altura*largura*comprimento
comprimento da diagonal = √(altura^2+largura^2+comprimento^2)

Input Format
Ler três variáveis do tipo float.

Constraints
A impressão dos floats deve considerar apenas uma casa decimal.

Output Format
Em cada linha, imprimir o conteúdo de um ponteiro seguido o seguinte padrão:
"area: valor"
"volume: valor"
"comprimento da diagonal: valor"
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void paralelepipedo(float *altura, float *largura, float *comprimento){
    float area, volume, comprimento_da_diagonal;

    area = (2 * *altura * *largura) + (2 * *altura * *comprimento) + (2 * *largura * *comprimento);

    volume = *altura * *largura * *comprimento;

    comprimento_da_diagonal = sqrtf((*altura * *altura) + (*largura * *largura) + (*comprimento * *comprimento));

    printf("area: %.1f\n", area);
    printf("volume: %.1f\n", volume);
    printf("comprimento da diagonal: %.1f", comprimento_da_diagonal);
}

int main() {
    float alt, lar, comp;
    float *altura;
    float *largura;
    float *comprimento;

    scanf("%f %f %f", &alt, &lar, &comp);
    altura = &alt;
    largura = &lar;
    comprimento = &comp;

    paralelepipedo(altura, largura, comprimento);
    return 0;
}
