/*
Implemente, utilizando recursão, um dos algoritmos de ordenação simples apresentados em sala de aula
(bublesort, selection sort ou insertion sort) para a ordenação de uma lista encadeada de floats.

Input Format
Enquanto -1 não for lido, ler um float e colocá-lo na lista encadeada de floats.

Constraints
No seu código pode ter, no máximo, apenas um loop.

Output Format
Imprimir o contrúdo da lista ordenada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell {
    float item;
    struct Cell* next;
} Cell;

typedef struct ListaE {
    Cell* head;
} ListaE;

Cell* criar_celula(float key) {
    Cell* c = (Cell*)malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}

ListaE* criar_listaE() {
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

int listaE_vazia(ListaE* l) {
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(float key, ListaE* l) {
    Cell* aux = criar_celula(key);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(float key, ListaE* l) {
    if (listaE_vazia(l)) {
        inserir_primeiro(key, l);
    } else {
        Cell* aux = l->head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = criar_celula(key);
    }
}

void imprimir(ListaE* l) {
    if (listaE_vazia(l)) {
        printf("\n");
    } else {
        Cell* aux = l->head;
        while (aux != NULL) {
            printf("%.1f ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

void liberar_LE(ListaE* l) {
    if (l != NULL) {
        Cell* aux = l->head;
        while (aux != NULL) {
            Cell* temp = aux;
            aux = aux->next;
            free(temp);
        }
        free(l);
    }
}

void bubble_sort_recursivo(ListaE *l)
{
    Cell *ini = l->head;
    if(ini == NULL || ini->next == NULL)
        return;

    int troca = 0;
    Cell *atual = ini;
    Cell *proximo = ini->next;

    while(proximo != NULL)
    {
        if(atual->item > proximo->item)
        {
            float aux = atual->item;
            atual->item = proximo->item;
            proximo->item = aux;
            troca = 1;
        }
        atual = proximo;
        proximo = proximo->next;
    }

    if(troca == 1)
        bubble_sort_recursivo(l);
}

int main(void)
{
    ListaE* lista = criar_listaE();
    float valor;

    while(valor != -1)
    {
        scanf("%f", &valor);
        if(valor != -1)
            inserir_ultimo(valor, lista);
    }

    bubble_sort_recursivo(lista);
    imprimir(lista);
    liberar_LE(lista);
    sleep(10);
    return 0;
}
