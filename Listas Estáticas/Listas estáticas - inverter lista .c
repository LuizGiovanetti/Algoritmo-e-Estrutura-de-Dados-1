/*
Implemente uma função que receba uma lista estática. A função deverá inverter a lista recebida como entrada.

Input Format
Enquanto -1 não for lido, ler números inteiros.


Output Format
Imprimir a lista invertida.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    return (l == NULL) || (l->tam == 0);
}


int lista_cheia(Lista *l){
    return (l != NULL) && (l->tam == MAX_SIZE);
}


int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }


    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}


void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

void inverter(Lista *l){
    int i, j, aux;

    if(!lista_vazia(l)){
        for(i=0, j = l->tam - 1; i < j; i++, j--){
            aux = l->item[i];
            l->item[i] = l->item[j];
            l->item[j] = aux;
        }
    }
}

int main(){
    int aux=0;
    Lista *l = criar_lista();

    while(aux != -1){
        scanf("%d", &aux);

        if(aux != -1){
            inserir(l, aux);
        }
    }

    inverter(l);

    imprimir_lista(l);

    free(l);

    return 0;
}
