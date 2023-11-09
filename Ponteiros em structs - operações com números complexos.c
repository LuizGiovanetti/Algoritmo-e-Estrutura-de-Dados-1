/*
Dada a estrutura abaixo:

typedef struct{
    float real, img, mod;
}complexo;

Implemente uma função que receba um ponteiro do tipo complexo e duas variáveis estáticas do tipo float
que represente as partes real e imaginária de um número complexo. A partir das varáveis do tipo float,
os campos das estrutura devem ser atualizados.
Em seguida, imprima os campos do "complexo" no seguinte formato: real sinal img i.
Para a implementação do exercício proposto considere o seguinte protótipo de função e a equação abaixo:
void atualizar_complexo(complexo *c, float real, float img);
Módulo de um número complexo:
z = sqrt(real * real + img * img);
Para o cálculo da raiz quadrada, você pode utilizar a função sqrt da biblioteca math.h.

Input Format
Na primeira linha deve ser lido dois dados do tipo float.


Output Format
Na primeira linha deve ser impresso o número complexo no seguinte formato: real sinal_numero_imaginário img i
Na segunda linha, deve ser impresso o módulo do número complexo.
Para a impressão de floats, considere a precisão de uma casa decimal (%.1f).
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    float real, img, mod;
}complexo;

void atualizar_complexo(complexo *c, float real, float img){
    if(c != NULL){
        c->real = real;
        c->img = img;
        c->mod = sqrt(real * real + img * img);
    }
}

int main() {
    float r, i;
    complexo c;

    scanf("%f %f", &r, &i);

    atualizar_complexo(&c, r, i);

    printf("%.1f", c.real);

    if(c.img >= 0 )
        printf("+%.1fi\n", c.img);
    else
        printf("%.1fi\n", c.img);

    printf("%.1f\n", c.mod);
    return 0;
}
