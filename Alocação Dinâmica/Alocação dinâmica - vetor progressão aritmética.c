/*
Implemente uma função que receba dois números inteiros, sendo uma para o tamanho do vetor (n) e a outra para razão (r). 
A função deverá retornar um vetor de tamanho n ordenado de forma crescente representado uma sequência de elementos de uma progressão aritmética iniciada por 0.

Para a implementação da solução, considere o protótipo de função abaixo:
int * prog_arit(int n, int r);

Input Format
Na primeira linha devem ser lidos dois números inteiros, sendo o primeiro referente ao tamanho do vetor e o segundo, à razão da progressão aritmética.

Output Format
Vetor que represente uma sequência de elementos de uma progressão aritmética.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *prog_arit(int n, int r)
{
    int *v = (int*) malloc(sizeof(int) * n);;
    int aux = 0;
    
    for(int i = 0; i < n; i++)
    {
        v[i] = aux;
        aux += r;
    }
    
    return v;
}
 
void imprimir_vet(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int main(void)
{
    int n, r;
    
    scanf("%d %d", &n, &r);
    
    int *v;
    
    v = prog_arit(n, r);
    
    imprimir_vet(v, n);
      
    free(v);
    
    return 0;
}
