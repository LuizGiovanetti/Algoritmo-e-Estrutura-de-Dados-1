/*
Implemente um número que receba dois números inteiros: número na base decimal (n) e a base (b).
A função deverá retornar uma pilha encadeada resultante da conversão de n na base b.
Para a implementação do exercício, utilize um TAD de pilhas encadeadas,
podendo ser um dos códigos que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Ler dois números inteiros na seguinte sequência:
número na base decimal e a base em que o número decimal será convertido.

Constraints
1 - Para acessar um elemento na pilha, deve ser utilizada a função desempilhar
ou implementar uma função que retorne o elemento que está no topo da pilha.
Para inserir um elemento na pilha, deve ser utilizada a função empilhar.
2 - o número que representa a base deve estar entre a seguinte faixa de valores: 2 <= b <= 16.

Output Format
Imprimir o número convertido na base b esvaziando a pilha encadeada.
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
