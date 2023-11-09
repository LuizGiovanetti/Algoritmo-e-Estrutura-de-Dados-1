/*
Implemente uma função que receba duas matrizes de números inteiros com dimensões iguais.
A função deverá retornar uma matriz (int**), alocada dinamicamente, resultante da soma das duas matrizes de entrada.

Input Format
Na primeira linha devem ser lidos dois números inteiros:
um para a quantidade de linhas (l) e outro para a quantidade de colunas (c).
Em seguida, ler o conteúdo de duas matrizes lxc.

Output Format
Imprimir o conteúdo da matriz resultante da soma.
*/
#include <stdio.h>
#include <stdlib.h>

int **soma_matrizes(int **matriz1, int **matriz2, int linhas, int colunas) {
    int **matriz_resultante = (int **) malloc(linhas * sizeof(int *));
    if (matriz_resultante == NULL) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        matriz_resultante[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz_resultante[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            return NULL;
        }
        for (int j = 0; j < colunas; j++) {
            matriz_resultante[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matriz_resultante;
}
int main() {
    int l, c, i, j;

    // Ler as dimensões da matriz
    scanf("%d %d", &l, &c);

    // Alocar dinamicamente a primeira matriz
    int** matriz1 = (int**) malloc(l * sizeof(int*));
    for (i = 0; i < l; i++) {
        matriz1[i] = (int*) malloc(c * sizeof(int));
    }

    // Ler a primeira matriz
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Alocar dinamicamente a segunda matriz
    int** matriz2 = (int**) malloc(l * sizeof(int*));
    for (i = 0; i < l; i++) {
        matriz2[i] = (int*) malloc(c * sizeof(int));
    }

    // Ler a segunda matriz
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Chamar a função soma_matrizes para obter a matriz resultante
    int** matriz_resultante = soma_matrizes(matriz1, matriz2, l, c);

    // Imprimir a matriz resultante
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", matriz_resultante[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória alocada dinamicamente
    for (i = 0; i < l; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(matriz_resultante[i]);
    }
    free(matriz1);
    free(matriz2);
    free(matriz_resultante);
    return 0;
}
