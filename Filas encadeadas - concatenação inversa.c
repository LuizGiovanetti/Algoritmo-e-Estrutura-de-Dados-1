/*
Implemente uma função que receba 3 filas encadeadas (f1, f2, f3).
A função deve concatenar f1 e f2, de forma que ambas sejam invertidas, em f3.
Durante a concatenação, as filas f1 e f2 devem ser esvaziadas. Dica: utilizar pilhas como auxiliar.
Exemplo:
Antes
f1 = {1, 2, 3}

f2 = {4, 5, 6, 7}

f3 = {}

Depois
f1 = {}

f2 = {}

f3 = {3, 2, 1, 7, 6, 5, 4}

Para a implementação do exercício, utilize um TAD de filas encadeadas,
podendo ser um dos códigos que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Na primeira linha, enquanto "-1" não for lido, ler números inteiros e inserir na primeira fila.
Na segunda linha, enquanto "-1" não for lido, ler números inteiros e inserir na segunda fila.

Constraints
As filas devem ser manipuladas apenas por funções. As únicas operações permitidas são: enfileirar e desenfileirar.

Output Format
Imprimir a fila concatenada
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};


Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}


int pilha_cheia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}


int pilha_vazia(Pilha *p){
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}


int empilhar(Pilha *p, int item){
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++;

        p->item[p->topo] = item;

        return 1;
    }

    return 0;
}


int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}


void imprimir_pilha(Pilha *p){
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d", item);
    }

    printf("\n");
}

void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}

int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}

int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}

typedef struct Cell Cell;


typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};


struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));

    f->inicio = NULL;
    f->fim = NULL;

    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;

        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

void concatenarFilas(FilaE* f1, FilaE* f2, FilaE* f3)
{
    Pilha* p1 = criar_pilha();
    Pilha* p2 = criar_pilha();

    while(!filaE_vazia(f1))
    {
        int item = desenfileirar(f1);
        empilhar(p1, item);
    }

    while(!filaE_vazia(f2))
    {
        int item = desenfileirar(f2);
        empilhar(p2, item);
    }


    while(!pilha_vazia(p1))
    {
        int item = desempilhar(p1);
        enfileirar(item, f3);
    }


    while(!pilha_vazia(p2))
    {
        int item = desempilhar(p2);
        enfileirar(item, f3);
    }

    liberar_pilha(p1);
    liberar_pilha(p2);
}

int main(void)
{
    FilaE* f1 = criar_filaE();
    FilaE* f2 = criar_filaE();
    FilaE* f3 = criar_filaE();

    int item;

    scanf("%d", &item);

    while(item != -1)
    {
        enfileirar(item, f1);
        scanf("%d", &item);
    }


    scanf("%d", &item);

    while(item != -1)
    {
        enfileirar(item, f2);
        scanf("%d", &item);
    }

    concatenarFilas(f1, f2, f3);

    imprimir_fila(f3);

    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);

    return 0;
}
