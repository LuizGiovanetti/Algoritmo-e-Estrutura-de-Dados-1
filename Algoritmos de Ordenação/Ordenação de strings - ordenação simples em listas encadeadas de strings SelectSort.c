/*
Implemente um algoritmo de ordenação simples para ordenar uma lista encadeada de strings.

Input Format
Na primeira linha deve ser lida a quantidade de elementos que serão inseridos na lista encadedade. A partir da segunda linha, ler as strings e colicá-las na lista encadeada.

Output Format
Imprimir o conteúdo da lista encadeada após a ordenação.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell
{
    char item[20];

    Cell *next;
};



struct ListaE{
    Cell *head;
};


Cell* criar_celula(char key[20])
{
    Cell *c = (Cell*) malloc(sizeof(Cell));
    strcpy(c->item, key);

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(char key[20], ListaE *l)
{
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void imprimir(ListaE *l)
{
    Cell *aux;

    if (!listaE_vazia(l))
    {
        aux = l->head;

        while (aux != NULL)
        {
            printf("%s\n", aux->item);

            aux = aux->next;
        }
    }
}

void liberar_LE(ListaE *l)
{
    Cell *aux = NULL;

    if(l != NULL)
    {
        while(l->head != NULL)
        {
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }
        free(l);
    }
}

void select_sort(ListaE *l)
{
    Cell *atual, *prox, *menor;
    char aux[20];

    for(atual = l->head; atual != NULL; atual = atual->next)
    {
        menor = atual;
        for(prox = atual->next; prox != NULL; prox = prox->next)
        {
            if(strcmp(prox->item, menor->item) < 0)
                menor = prox;
        }
        if(menor != atual)
        {
            strcpy(aux, atual->item);
            strcpy(atual->item, menor->item);
            strcpy(menor->item, aux);
        }
    }
}

int main(void)
{
    int n;

    scanf("%d", &n);

    ListaE *l = criar_listaE();

    for(int i = 0; i < n; i++)
    {
        char nome[20];
        scanf("%s", nome);
        inserir_primeiro(nome, l);
    }

    select_sort(l);
    imprimir(l);
    liberar_LE(l);

    return 0;
}
