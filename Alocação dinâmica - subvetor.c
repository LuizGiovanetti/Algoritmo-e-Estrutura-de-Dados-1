/*
Implemente uma função que receba um vetor de números inteiros, o tamanho do vetor e dois números inteiros, sendo um para posição inicial e o outro para a posição final. 
A função deverá retornar um vetor com elementos entre as posições inicial e a final do vetor de entrada. Para a implementação da solução, pode ser considerado o protótipo abaixo:

int* subvetor(int *v, int n, int ini, int fim);

Input Format
Na primeira linha deve ser lido o tamanho do vetor.
Na segunda linha, todos os elementos do vetor deverão ser lidos.
Na terceira linha, deverão ser lidos dois números inteiros, sendo o primeiro para a posição inicial e o segundo, para a posição final.

Output Format
Após a geração do subvetor, o conteúdo do mesmo deverá ser impresso.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int *subvetor(int *v, int n, int ini, int fim)
{
    int *sv = NULL;
    
    if((v != NULL) && (ini >=0) && (ini <= fim) && (fim < n))
    {
        sv = malloc(sizeof(int) * (fim - ini + 1));
        
        for(int i = ini; i <=fim; i++)
            sv[i - ini] = v[i];
    }
    
    return sv;
}

void imprimir_vetor(int *v, int n)
{
    if(v != NULL)
    {
        for(int i = 0; i < n; i++)
            printf("%d ", v[i]);
    } 
}

int main(void)
{
    int n, ini, fim;
    
    scanf("%d", &n);
    
    int *sv = NULL;
    int *v = malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    scanf("%d %d", &ini, &fim);
    
    sv = subvetor(v, n, ini, fim);
    
    imprimir_vetor(sv, fim-ini+1);
    
    free(v);
    free(sv);
    
    return 0;
}
