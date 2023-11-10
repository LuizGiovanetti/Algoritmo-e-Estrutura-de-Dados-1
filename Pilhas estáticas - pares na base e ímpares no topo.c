/*
Implemente uma função que receba duas pilhas de números inteiros positivos.
A função deverá retornar uma terceira pilha resultante da concatenação das duas pilhas, mas os números ímpares deverão estar próximos à base e os pares próximos do topo (utilizar apenas operações de empilhar e desempilhar).

Input Format
Na primeira linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na primeira pilha.
Na segunda linha, enquanto "-1" não for lido, ler números inteiros e colocá-los na segunda pilha pilha.

Constraints
Os elementos da pilha devem ser acessados através da função desempilhar.

Output Format
Imprimir o resultado da concatenação das duas pilhas.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

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

        printf("%d ", item);
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

Pilha *concatenar(Pilha *p1, Pilha *p2)
{
    if(p1 == NULL)
        p1 = criar_pilha();
    
    if(p2 == NULL)
        p2 = criar_pilha();
    
    Pilha *p3 = criar_pilha();

    for(int i = 0; i <= p2->topo; i++)
    {
        if(p2->item[i] % 2 != 0)
            empilhar(p3, p2->item[i]);
    }
    
    for(int i = 0; i <= p1->topo; i++)
    {
        if(p1->item[i] % 2 != 0)
            empilhar(p3, p1->item[i]);
    }

    for(int i = 0; i <= p2->topo; i++)
    {
        if(p2->item[i] % 2 == 0)
            empilhar(p3, p2->item[i]);
    }
    
    for(int i = 0; i <= p1->topo; i++)
    {
        if(p1->item[i] % 2 == 0)
            empilhar(p3, p1->item[i]);
    }

    return p3;
}

int main(void)
{
    int item = 0;
    Pilha *p1 = criar_pilha();
    Pilha *p2 = criar_pilha();
    Pilha *p3 = NULL;
    
    while(item != -1)
    {
        scanf("%d", &item);
        if(item != -1)
            empilhar(p1, item);
    }
    
    item = 0;
    
    while(item != -1)
    {
        scanf("%d", &item);
        if(item != -1)
            empilhar(p2, item);
    }
    
    p3 = concatenar(p1, p2);
    
    imprimir_pilha(p3);
    
    liberar_pilha(p3);
    liberar_pilha(p1);
    liberar_pilha(p2);
    
    return 0;
}
