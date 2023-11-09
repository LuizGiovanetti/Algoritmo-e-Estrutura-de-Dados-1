/*
Considerando uma estrutura para representar um vetor no R2,
implemente uma fun��o que receba dois vetores de acordo com a estrutura e prot�tipo abaixo:

typedef struct{
    int x;
    int y;
}vetor_r2;

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2);
A fun��o dever� retornar um vetor resultante da soma entre v1 e v2.

Input Format
Na primeira linha dever�o ser lidos os campos referentes ao v1 (x e y).
Na segunda linha dever�o ser lidos os campos referentes ao v2.

Output Format
Imprimir o vetor resultante da soma entre v1 e v2.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}vetor_r2;

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2){
    vetor_r2 v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;

    return v3;
}

int main() {

    vetor_r2 v1, v2, v3;


    scanf("%d %d", &v1.x, &v1.y);
    scanf("%d %d", &v2.x, &v2.y);

    v3 = soma_vec(v1, v2);

    printf("%d %d", v3.x, v3.y);
    return 0;
}
