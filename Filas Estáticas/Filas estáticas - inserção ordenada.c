/*
Implemente uma função que receba um fila estática de números inteiros e uma chave, também do tipo inteiro.
A função deverá inserir a chave na fila de forma que os elementos sejam mantidos ordenados em ordem descrescente.
Para a inserção de novos elementos será necessário o uso uma fila auxiliar,
já que apenas as operações de enfileirar e desenfileirar são permitidas para a manipulação dos elementos.
Adicionalmente, pode ser usada/implementada uma função para verificar qual elemento está no início e no fim da fila.
Para a implementação do exercício, utilize um TAD de filas estáticas,
podendo ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Enquanto "-1" não for lido, ler números inteiros.

Constraints
O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format
Imprimir a fila ordenada em ordem decrescente.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 100

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


int verificar_inicio(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->ini];
    else
        return INT_MIN;
}


int verificar_fim(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->fim];
    else
        return INT_MIN;
}

Fila* inserir_ordenado(int key, Fila *f)
{
    Fila *aux = criar_fila();

    while(!fila_vazia(f) && (key < verificar_inicio(f)))
        enfileirar(aux, desenfileirar(f));

    enfileirar(aux, key);

    while(!fila_vazia(f))
        enfileirar(aux, desenfileirar(f));

    free(f);

    return aux;
}
int main(void){
    Fila *f = criar_fila();
    int aux = 0;

    while(aux != -1)
    {
        scanf("%d", &aux);

        if(aux != -1)
            f = inserir_ordenado(aux, f);
    }

    imprimir_fila(f);

    liberar_fila(f);

    return 0;
}
