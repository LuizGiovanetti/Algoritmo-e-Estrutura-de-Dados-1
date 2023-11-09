/*
Implemente uma função que receba uma lista encadeada.
Nessa função deverá ser implementado o método de recuperação recorrente transposição,
no qual, cada vez que um registro é recuperado com sucesso,
ele tem a posição trocada com o registro imediatamente anterior.
Por exemplo, suponha que procuramos a chave 2 na seguinte: {7, 3, 4, 2, 6}.
Após recuperar a chave 2, a mesma tem a posição trocada com a chave 3: {7, 3, 2, 4, 6}.

Input Format
Na primeira linha, enquanto -1 não for lido, devem ser lidos os elementos da lista encadeada.
Na segunda linha deve ser lida a quantidade de chaves que deverão ser procuradas).
A partir da próxima linha, as chaves que serão procuradas devem ser lidas.


Output Format
Após execução do algoritmo para cada caso teste, imprimir a lista encadeada.
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

int transposicao(ListaE *l, int key)
{
    Cell *aux, *auxA; //aux atual = auxA
    int t; //troca

    if(!listaE_vazia(l))
    {
        if(key == l->head->item)
            return 1;
        else
        {
            aux = auxA = l->head;

            while((auxA != NULL) && (key != auxA->item))
            {
                aux = auxA;
                auxA = auxA->next;
            }

            if(auxA != NULL)
            {
                t = aux->item;
                aux->item = auxA->item;
                auxA->item = t;

                return 1;
            }
        }

    }

    return 0;
}

int main(void){
    ListaE *l = criar_listaE();
    int c, key = 0;

    while(key != -1)
    {
        scanf("%d", &key);

        if(key != -1)
            inserir_ultimo(key, l);
    }

    scanf("%d", &c);

    while(c > 0)
    {
        scanf("%d", &key);

        transposicao(l, key);
        c--;
    }

    imprimir(l);

    liberar_LE(l);

    return 0;
}
