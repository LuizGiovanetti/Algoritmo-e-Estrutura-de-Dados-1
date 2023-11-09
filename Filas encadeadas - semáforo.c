/*
Três estradas movimentadas ligam a uma única rodovia (principal), conforme a figura abaixo.
Para o gerenciamento do trânsito, um semáforo foi adicionado para cada estrada,
na qual, enquanto o sinal estiver verde, os veículos que chegaram primeiro podem acessar a rodovia principal.
Quando o sinal estiver verde para uma estrada, para as outras duas estradas, o sinal será vermelho.
No entanto, como as estradas estão cheias de buracos e os veículos devem transitar vagarosamente,
para cada vez que o sinal estiver verde para uma estrada,
apenas três veículos conseguem acessar a estrada principal antes do sinal ficar vermelho.
Por outro lado, os semáforos possuem um sistema inteligente, no qual, enquanto a estrada estiver vazia,
o sinal será vermelho. Também, durante o sinal verde, quando a estrada tiver menos que três veículos,
assim que os mesmos acessarem a rodovia principal, o sinal ficará vermelho antecipadamente.

Implemente uma função para o gerenciamento do trânsito conforme ilustrado acima.
A função deverá receber, como parâmetro, 4 filas encadeadas (E1, E2, E3, R).
Na função, os elementos de E1, E2 e E3 devem ser transferidos para R de forma que simule o trânsito descrito acima.

Input Format
Em cada uma das 3 primeiras linhas, enquanto -1 não for lido, ler números inteiros e inserí-los em suas respectivas filas (E1, E2 e E3).

Constraints
O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format
Imprimir a fila R.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

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

FilaE *leituraF()
{
    FilaE *f = criar_filaE();
    int aux = 0;

    while(aux != -1)
    {
        scanf("%d", &aux);

        if(aux != -1)
            enfileirar(aux, f);
    }
    return f;
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

static void sinal_verde(FilaE *e, FilaE *r)
{
    int count = 3;

    while(!filaE_vazia(e) && (count > 0))
    {
        enfileirar(desenfileirar(e), r);
        count--;
    }
}

void semaforo(FilaE *e1, FilaE *e2, FilaE *e3, FilaE *r)
{
    if(r == NULL)
        r = criar_filaE();

    while(!filaE_vazia(e1) || !filaE_vazia(e2) || !filaE_vazia(e3))
    {
        sinal_verde(e1, r);
        sinal_verde(e2, r);
        sinal_verde(e3, r);
    }
}

int main(void){
    FilaE *e1 = leituraF();
    FilaE *e2 = leituraF();
    FilaE *e3 = leituraF();
    FilaE *r = criar_filaE();

    semaforo(e1, e2, e3, r);

    imprimir_fila(r);

    liberar_filaE(e1);
    liberar_filaE(e2);
    liberar_filaE(e3);
    liberar_filaE(r);
    return 0;
}
