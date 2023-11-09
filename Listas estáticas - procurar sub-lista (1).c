/*
Implemente uma fun��o que receba duas listas est�ticas (l1, l2).
A fun��o dever� retornar a posi��o lista l2 dentro de l1. Caso a lista l2 n�o estiver na l1, retornar "-1".

Exemplo:
l1 = {1, 2, 3, 4, 5, 6, 7,** 8, 7, 6, 8**, 9, 10}
l2 = {8, 7, 6, 8}

No exemplo acima, l2 est� (inicia) na posi��o 7 da lista l2.
Para a implementa��o do exerc�cio, utilize um TAD de listas est�ticas,
podendo ser o c�digo que foi apresentado em aula (dispon�vel no reposit�rio da disciplina no GitHub).

Input Format
Na primeira linha, enquanto "-1" n�o for lido, ler n�meros inteiros.
Na segunda linha, a mesma restri��o da primeira linha deve ser aplicada.

Output Format
Imprimir a posi��o da lista l2 na l1.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM_MAX 150

typedef struct{
    int item[TAM_MAX];
    int ultimo;
}Lista;

void criar_lista(Lista *l)
{
    l->ultimo = -1; //Cria a lista, quando for adicionar algo na lista o indice comeca no 0.
}

int lista_vazia(Lista *l)
{
    return (l->ultimo == -1); //Se for diferente de -1 ela retorna falso, ja que � uma verificacao booleana.
}

int lista_cheia(Lista *l)
{
    return (l->ultimo == TAM_MAX - 1);//Verifica se o tamanho da lista esta no intervalo de 0 ate tamanho maximo, e retorna booleano.
}

int inserir_elemento(Lista *l, int item)
{
    if(lista_cheia(l))
    {
        return 0;
    }
    l->ultimo++; //Incrementa o indice.
    l->item[l->ultimo] = item; //Coloca o elemento, "item", dentro da lista.
    return 1; //Validacao da insercao do item.
}

int buscar_elemento(Lista *l, int item)
{
    int i;
    for(i = 0;i <= l->ultimo; i++) //De 0 ate a ultima posicao da lista.
    {
        if(l->item[i] == item) //Verifica se a lista na posicao "i", � igual ao item.
        {
            return i; //Retorna a posicao da lista.
        }
    }
    return -1;
}

int remover_elemento(Lista *l, int item)
{
    int posicao = buscar_elemento(l, item);
    int i;

    if(posicao == -1) //Verifica se o item esta dentro da lista.
    {
        return 0;
    }

    for(i=posicao; i < l->ultimo; i++)
    {
        l->item[i] = l->item[i+1]; //Move as posicoes da lista um para tras.
    }
    l->ultimo--;

    return 1;
}

int sublista_existente(Lista *l1, Lista *l2)
{

    if (lista_vazia(l1) || lista_vazia(l2))//Verifica se alguma das listas � vazia.
    {
        return 0; //Retorna 0, indicando que a sublista n�o existe.
    }

    int i, j;

    for (i = 0; i <= l1->ultimo - l2->ultimo; i++)//Percorre a lista l1 at� que n�o haja mais elementos suficientes para formar a sublista l2.
    {
        if (l1->item[i] == l2->item[0])//Percorre as listas enquanto os elementos forem iguais.
        {
            for (j = 0; j < l2->ultimo && l2->item[j] == l1->item[i+j]; j++)// Se j for igual ao �ltimo �ndice de l2, ent�o todos os elementos de l2 foram encontrados em l1.
            if (j == l2->ultimo)
            {
                return i; //Retorna i, indicando que a sublista existe em l1.
            }
        }
    }

    return 0; //Retorna 0, indicando que a sublista n�o existe.
}

int main(void)
{
    Lista l1, l2;
    int item;
    criar_lista(&l1);
    criar_lista(&l2);

    while(1)//Loop infinito que s� ser� interrompido pelo comando 'break'.
    {
        scanf("%d", &item);
        if(item == -1)
        {
            break;
        }
        inserir_elemento(&l1, item);
    }
    while(1)//Loop infinito que s� ser� interrompido pelo comando 'break'.
    {
        scanf("%d", &item);
        if(item == -1)
        {
            break;
        }
        inserir_elemento(&l2, item);
    }

    printf("%d\n", sublista_existente(&l1, &l2));
    return 0;
}
