/*
Implemente um TAD para hashing estático fechado utilizando as seguintes abordagens vistas para a sala de aula:
-> função hash: método da multiplicação
-> rehash: segunda função hash
--> h1(k) = método da multiplicação
--> h2(k) = 1 + k % (B - 1)
--> rh(k, i) = (h1(k) + i * h2(k)) % B

Input Format
Na primeira linha devem ser lidos a constante c considerada na alocação de chaves (tipo float),
sendo que 0 < c < 1 e o tamanho n da tabela hash (tipo int).
Na segunda linha deve ser lida a quantidade de chaves que serão alocadas.
Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Output Format
Imprimir a posição onde cada chave foi alocada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;


HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}


static int hashingF(int k, int B, float c)
{
    return (int)(B * ((k * c) - (int)(k * c)));
}


/*static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}*/

static int rehashingF(int k, int B)
{
    return 1 + k%(B - 1);
}


int buscar(int key, HashT *t, float c)
{
    int h = hashingF(key, t->tam, c);
    int h1 = rehashingF(key, t->tam);
    int i = 0;

    while(i < t->tam)
    {
        int idx = (h + i * h1)%t->tam;

        if(t->buckets[idx] == key)
            return idx;
        else if(t->buckets[idx] == -1)
            break;

        i++;
    }
    return -1;
}


int inserir(int key, HashT *t, float c)
{
    int h = hashingF(key, t->tam, c);
    int h1 = rehashingF(key, t->tam);
    int i = 0;

    while(i < t->tam)
    {
        int idx = (h + i * h1)%t->tam;

        if(t->buckets[idx] == -1)
        {
            t->buckets[idx] = key;
            return idx;
        }
        i++;
    }
    return -1;
}


/*int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(key, t);

        if (x >= 0){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}*/


void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] > 0)
                printf("%d\n", t->buckets[i]);
    }
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
}

int main(void)
{
    int n, key, tam;
    float c;

    scanf("%f %d", &c, &n);

    HashT *tHash = criar(n);

    scanf("%d", &tam);

    for(int i = 0; i < tam; i++)
    {
        scanf("%d", &key);
        int pos = buscar(key, tHash, c);
        if(pos != -1)
        {
            printf("%d\n", pos);
        }else
        {
            pos = inserir(key, tHash, c);
            printf("%d\n", pos);
        }
    }

    liberar(tHash);

    return 0;
}
