/*
Implemente uma função que receba duas listas encadeadas (l1 e l2).
A função deverá retornar uma lista encadeada ordenada com os elementos existentes nas duas listas de entrada.
Exemplo:
Entrada:
l1 = {1, 2, 3, 4, 5, 6}

l2 = {6, 8, 10, 1, 7, 4}

Saída:
l3= {1, 4, 6}

Para a implementação do exercício, utilize um TAD de listas encadeadas,
podendo ser um dos códigos que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Na primeira linha, enquanto -1 não for lido, ler números inteiros e colocá-los na lista l1.
Na segunda linha, enquanto -1 não for lido, ler números inteiros e colocá-los na lista l2.

Output Format
Imprimir o conteúdo da lista (l3) retornada pela função.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    int item;

    Cell *next;
};



struct ListaE{
    Cell *head;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

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


int procurar(int key, ListaE *l){
    Cell *aux;

    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}



void inserir_primeiro(int key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}


void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;

    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l){
    Cell *aux = NULL;

    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

void inserir_iguais(ListaE *l1, ListaE *l2, ListaE *l3)
{
    Cell *aux = l1->head;

    while(aux != NULL)
    {
        if(procurar(aux->item, l2))
        {
            if(!procurar(aux->item, l3))
            {
                Cell *novo = criar_celula(aux->item);
                Cell *atual = l3->head;
                Cell *anterior = NULL;

                while(atual != NULL && atual->item < aux->item)
                {
                    anterior = atual;
                    atual = atual->next;
                }

                if(anterior == NULL)
                {
                    novo->next = l3->head;
                    l3->head = novo;
                }
                else
                {
                    anterior->next = novo;
                    novo->next = atual;
                }
            }
        }

        aux = aux->next;
    }
}

int main(void)
{
    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();
    ListaE *l3 = criar_listaE();

    int aux=0;

    while(aux != -1)
    {
        scanf("%d", &aux);

        if(aux != -1)
            inserir_ultimo(aux, l1);
    }

    aux = 0;
    while(aux != -1)
    {
        scanf("%d", &aux);

        if(aux != -1)
            inserir_ultimo(aux, l2);
    }

    inserir_iguais(l1, l2, l3);

    imprimir(l3);

    liberar_LE(l1);
    liberar_LE(l2);
    liberar_LE(l3);


    return 0;
}
