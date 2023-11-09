/*
Implemente uma fun��o que receba duas filas compostas por n�meros naturais.
A fun��o dever� intercalar as duas filas. Em cada intercala��o, o maior elemento deve ser enfileirado primeiro.

Exemplo:

Antes
f1 = {1, 5, 3}

f2 = {4, 2, 3, 4}

f3 = {}

Depois
f1 = {}

f2 = {}

f3 = {4, 1, 5, 2, 3, 3, 4}

Input Format
Na primeira linha, enquanto "-1" n�o for lido, ler n�meros inteiros. Na segunda linha, a mesma restri��o da primeira linha deve ser aplicada.

Constraints
O acesso aos elementos da fila deve ser atrav�s da fun��o desenfileirar.

Output Format
Imprimir a fila intercalada.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 10

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
};


Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}


int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}


int enfileirar(Fila *f, int chave){
    if (f == NULL)
        f = criar_fila();

    if (!fila_cheia(f)){
        if (f->ini < 0)
            f->ini = 0;

        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}


int desenfileirar(Fila *f){
    int item = INT_MIN;

    if (!fila_vazia(f)){
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}


void imprimir_fila(Fila *f){
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }

    printf("\n");
}

void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

int tamanho_fila(Fila *f){
    if (f != NULL)
        return f->tam;
    else
        return 0;
}

static void troca_maior(int *a, int *b)
{
    int aux;

    if(*a < *b)
    {
        aux = *a;
        *a = *b;
        *b = aux;
    }
}

static void concatenar_subfila(Fila *dest, Fila *orig)
{
    if((dest != NULL) && (orig != NULL))
    {
        while(!fila_vazia(orig))
            enfileirar(dest, desenfileirar(orig));
    }
}

Fila * intercalar(Fila *f1, Fila *f2)
{
    Fila *f3 = NULL;
    int a, b;

    if(f1 == NULL)
        return f2;
    else if(f2 == NULL)
        return f1;
    else
    {
        f3 = criar_fila();

        while(!fila_vazia(f1) && !fila_vazia(f2))
        {
            a = desenfileirar(f1);
            b = desenfileirar(f2);

            troca_maior(&a, &b);
            enfileirar(f3, a);
            enfileirar(f3, b);
        }
        concatenar_subfila(f3, f1);
        concatenar_subfila(f3, f2);
        return f3;
    }
}

int main(void)
{
    int item = 0;
    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = NULL;

    while(item != -1)
    {
        scanf("%d", &item);
        if(item != -1)
            enfileirar(f1, item);
    }

    item = 0;

    while(item != -1)
    {
        scanf("%d", &item);
        if(item != -1)
            enfileirar(f2, item);
    }
    f3 = intercalar(f1, f2);

    imprimir_fila(f3);

    liberar_fila(f1);
    liberar_fila(f2);
    liberar_fila(f3);

    return 0;
}

