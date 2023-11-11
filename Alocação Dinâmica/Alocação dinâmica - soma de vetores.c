/*
Implemente uma função que receba dois vetores de números inteiros.
A função deverá retornar um vetor resultante da soma dos vetores entrada.
Cabeçalho da solução proposta, onde v1 e v2 são vetores, n1 é o comprimento de v1 e v2 é o comprimento de v2:
int* soma(int *v1, int n1, int *v2, int n2);

Input Format
Deve ser lido um valor inteiro n que representa a quantidade de elementos de um v. Em seguida,
devem ser lidos os n elementos do vetor. Repetir o processo para o segundo vetor.

Output Format
Vetor resultante da soma dos vetores de entrada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* soma(int *v1, int n1, int *v2, int n2){
    int i, n3;
    int *v3 = NULL;

    if((v1 != NULL) && (v2 != NULL)){
        if(n1 > n2)
            n3 = n1;
        else
            n3 = n2;

        v3 = (int*) malloc(sizeof(int) * n3);

        for(i = 0; (i < n1) && (i < n2); i++)
            v3[i] = v1[i] + v2[i];

        for(i = n2; i < n1; i++)
            v3[i] = v1[i];

        for(i = n1; i < n2; i++)
            v3[i] = v2[i];
    }

    return v3;
}

int main() {
    int n1, n2, i;
    int *v1 = NULL;
    int *v2 = NULL;
    int *v3 = NULL;

    scanf("%d", &n1);

    v1 = (int*) malloc(sizeof(int) * n1);

    for(i = 0; i < n1; i++)
        scanf("%d", &v1[i]);

    scanf("%d", &n2);

    v2 = (int*) malloc(sizeof(int) * n2);

    for(i = 0; i < n2; i++)
        scanf("%d", &v2[i]);

    v3 = soma(v1, n1, v2, n2);

    for(i = 0; (i < n1) || (i < n2); i++)
        printf("%d ", v3[i]);

    return 0;
}
