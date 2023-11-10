/*
Implemente uma função que receba uma matriz quadratica de numeros inteiros.
A função devera retornar um vetor (ponteiro) alocado dinamicamente com os elementos da diagonal principal da matriz.

Input Format
Na primeira linha deve ser lido um numero inteiro N representando a dimensão da matriz.

Em seguida, ler os elementos de uma matriz NxN de numeros inteiros.

Output Format
Em uma unica, linha, imprimir o conteudo do vetor com os elementos da diagonal da matriz.
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
    scanf("%d", &n); // lendo a dimensão da matriz
    int **matriz = (int**) malloc(n * sizeof(int*)); // alocando matriz dinamicamente
    for (i = 0; i < n; i++) {
        matriz[i] = (int*) malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]); // lendo os elementos da matriz
        }
    }
    int *vetor = diagonal(matriz, n); // chamando a função diagonal para obter o vetor com a diagonal principal
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]); // imprimindo os elementos do vetor
    }
    printf("\n");
    free(vetor); // liberando a memoria alocada dinamicamente para o vetor
    for (i = 0; i < n; i++) {
        free(matriz[i]); // liberando a memoria alocada dinamicamente para cada linha da matriz
    }
    free(matriz); // liberando a memoria alocada dinamicamente para a matriz
    return 0;
}
