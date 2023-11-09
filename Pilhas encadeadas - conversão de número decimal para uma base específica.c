/*
Implemente um n�mero que receba dois n�meros inteiros: n�mero na base decimal (n) e a base (b).
A fun��o dever� retornar uma pilha encadeada resultante da convers�o de n na base b.
Para a implementa��o do exerc�cio, utilize um TAD de pilhas encadeadas,
podendo ser um dos c�digos que foi apresentado em aula (dispon�vel no reposit�rio da disciplina no GitHub).

Input Format
Ler dois n�meros inteiros na seguinte sequ�ncia:
n�mero na base decimal e a base em que o n�mero decimal ser� convertido.

Constraints
1 - Para acessar um elemento na pilha, deve ser utilizada a fun��o desempilhar
ou implementar uma fun��o que retorne o elemento que est� no topo da pilha.
Para inserir um elemento na pilha, deve ser utilizada a fun��o empilhar.
2 - o n�mero que representa a base deve estar entre a seguinte faixa de valores: 2 <= b <= 16.

Output Format
Imprimir o n�mero convertido na base b esvaziando a pilha encadeada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

struct Cell{
    char item;
    Cell *next;
};


struct PilhaE{
    Cell *topo;
};


Cell* criar_celula(char key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(char key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


char desempilhar(PilhaE *p){
    Cell *aux;
    char item = ' ';

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}


void imprimir_pilha(PilhaE *p, int base)
{
    Cell *aux = p->topo;
    char car;
    int item;

    if (!pilhaE_vazia(p))
    {
        while (aux != NULL)
        {
            item = aux->item;
            if(base == 16)
            {
                if(item >= 10 && item <=15)
                {
                    car = 'a' + (item - 10);
                    printf("%c", car);
                }
                else
                    printf("%d", item);
            }
            else
                printf("%d", item);

            aux = aux->next;
        }
        printf("\n");
    }
}


int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

void conversao(int dec, int *base, PilhaE *p)
{
    int resto = 0;

    if((*base >= 2) && (*base <= 16))
    {
        if(dec == 0)
            empilhar(0, p);

        while(dec > 0)
        {
            resto = dec % *base;
            empilhar(resto, p);
            dec = dec / *base;
        }
    }

}

int main(void)
{
    PilhaE *p = criar_pilhaE();
    int dec, base;

    scanf("%d %d", &dec, & base);

    conversao(dec, &base, p);

    imprimir_pilha(p, base);

    liberar_pilha(p);
    return 0;
}
