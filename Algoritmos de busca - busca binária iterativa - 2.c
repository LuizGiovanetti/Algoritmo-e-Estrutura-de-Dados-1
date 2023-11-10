/*
Implemente a versão iterativa da busca binária.

Input Format
Na primeira linha deve ser lido o tamanho do vetor. Na segunda linha devem ser lidos os elementos do vetor. 
Na terceira linha deve ser lido o número de casos de teste (quantidade de chaves que deverão ser procuradas). 
A partir da próxima linha, as chaves que serão procuradas devem ser lidas.

Output Format
Para cada chave procurada (caso de teste) deve ser impressa a posição no vetor ou -1 (se não for encontrada)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int buscaB_inter(int item, int *v, int ini, int fim)
{
    if((ini == fim) && (item == v[ini]))
        return ini;
    else if(ini <= fim)
    {
        while(ini <= fim)
        {
            int pivo = ini + (fim - ini) / 2;
            
            if(item == v[pivo])
                return pivo;
            else if(item < v[pivo])
                fim = pivo - 1;
            else
                ini = pivo + 1;
        }
    }
    
    return -1;
}

int main(void)
{
    int n, qnt, item;
    
    scanf("%d", &n);
    
    int *v = (int*)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    scanf("%d", &qnt);
    
    for(int i = 0; i < qnt; i++)
    {
        scanf("%d", &item);
        printf("%d\n", buscaB_inter(item, v, 0, n - 1));
    }
    
    free(v);
      
    return 0;
}
