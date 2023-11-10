/*
Implemente um TAD para hashing estático aberto,
onde as colisões devem ser resolvidas por meio de listas encadeadas ordenadas.
A função hash deve ser resto de divisão, ou seja, h(k) = k % B, onde k é uma chave e B é o tamanho da tabela hash.

Input Format
Na primeira linha deve ser lido o tamanho da tabela hash.
Na segunda linha deve ser lida a quantidade de chaves que serão alocadas.
Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Output Format
Imprimir as posições onde as chaves foram colocadas na tabela.
Em seguida, imprimir a tabela hash inteira. Para isso, deve ser considerado o seguinte formato:
"linha_i: -> item_0 -> item_1 -> ... -> item_n"
Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct
{
    unsigned int tam;
    int **buckets;
}HashT;

struct Cell
{
    int item;

    Cell *next;
};



struct ListaE
{
    Cell *head;

    int tam;
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


/*int remover(int key, ListaE *l){
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
}*/


void imprimir_lista(ListaE *l)
{
    Cell *aux;

    if(!listaE_vazia(l))
    {
        aux = l->head;

        while(aux != NULL)
        {
            if(aux->item >= 0)
            {
                printf("%d ", aux->item);
                if(aux->next != NULL)
                    printf("-> ");
            }

            aux = aux->next;
        }

        printf("\n");
    }
}


/*int liberar_LE(ListaE *l){
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
}*/



HashT *criarHash(unsigned int tam)
{
    HashT *t = malloc(sizeof(HashT));

    t->tam = tam;
    t->buckets = malloc(sizeof(ListaE) * tam);

    for (int i = 0; i < tam; i++)
    {
        t->buckets[i] = criar_listaE();
        inserir_ultimo(-1, t->buckets[i]);
    }

    return t;
}

int hashing(int key, int tam)
{
    return key%tam;
}

/*static int hashingF(int k, int B){
    return k % B;
}


static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}*/


int buscar_bucket(int key, HashT *t)
{
    int x = hashing(key, t->tam);

    if(procurar(key, t->buckets[x]))
        return x;

    return -1;
}


void inserirT(int key, HashT *t)
{
    int x;

    if((t != NULL) && (key > 0))
    {
        x = hashing(key, t->tam);

        if(procurar(key, t->buckets[x]) <= 0)
            inserir_ultimo(key, t->buckets[x]);
        else
            inserir_ultimo(key, t->buckets[x]);
    }
}


void remover_bucket(int key, HashT *t)
{
    int x;

    if(t != NULL)
    {
        x = buscar_bucket(key, t);

        if(x >= 0)
        {
            t->buckets[x] = 0;

        }
    }
}


void imprimir(HashT *t)
{
    if(t != NULL)
    {
        for (int i = 0; i < t->tam; i++)
        {
            printf("%d: -> ", i);
            imprimir_lista(t->buckets[i]);
        }
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
    int tam, n, *key;

    scanf("%d %d", &tam, &n);

    key = malloc(sizeof(int) * n);

    HashT *tHash = criarHash(tam);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &key[i]);
        inserirT(key[i], tHash);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d\n", buscar_bucket(key[i], tHash));
    }
    printf("\n");

    imprimir(tHash);

    liberar(tHash);
    return 0;
}
