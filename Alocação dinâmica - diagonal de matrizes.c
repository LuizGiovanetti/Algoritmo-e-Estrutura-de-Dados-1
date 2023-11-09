/*
Implemente uma fun��o que receba uma matriz quadr�tica de n�meros inteiros.
A fun��o dever� retornar um vetor (ponteiro) alocado dinamicamente com os elementos da diagonal principal da matriz.

Input Format
Na primeira linha deve ser lido um n�mero inteiro N representando a dimens�o da matriz.

Em seguida, ler os elementos de uma matriz NxN de n�meros inteiros.

Output Format
Em uma �nica, linha, imprimir o conte�do do vetor com os elementos da diagonal da matriz.
*/
#include <stdio.h>
#include <stdlib.h>

int* diagonal(int **matriz, int n) {
    int *vetor = (int*) malloc(n * sizeof(int)); // alocando vetor dinamicamente
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) { // se o elemento estiver na diagonal principal
                vetor[i] = matriz[i][j]; // copiando o elemento para o vetor
            }
        }
    }
    return vetor; // retornando o vetor
}

int main() {
    int n, i, j;
    scanf("%d", &n); // lendo a dimens�o da matriz
    int **matriz = (int**) malloc(n * sizeof(int*)); // alocando matriz dinamicamente
    for (i = 0; i < n; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]); // lendo os elementos da matriz
        }
    }
    int *vetor = diagonal(matriz, n); // chamando a fun��o diagonal para obter o vetor com a diagonal principal
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]); // imprimindo os elementos do vetor
    }
    printf("\n");
    free(vetor); // liberando a mem�ria alocada dinamicamente para o vetor
    for (i = 0; i < n; i++) {
        free(matriz[i]); // liberando a mem�ria alocada dinamicamente para cada linha da matriz
    }
    free(matriz); // liberando a mem�ria alocada dinamicamente para a matriz
    return 0;
}
