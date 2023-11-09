/*
Tr�s estradas movimentadas ligam a uma �nica rodovia (principal), conforme a figura abaixo.
Para o gerenciamento do tr�nsito, um sem�foro foi adicionado para cada estrada,
na qual, enquanto o sinal estiver verde, os ve�culos que chegaram primeiro podem acessar a rodovia principal.
Quando o sinal estiver verde para uma estrada, para as outras duas estradas, o sinal ser� vermelho.
No entanto, como as estradas est�o cheias de buracos e os ve�culos devem transitar vagarosamente,
para cada vez que o sinal estiver verde para uma estrada,
apenas tr�s ve�culos conseguem acessar a estrada principal antes do sinal ficar vermelho.
Por outro lado, os sem�foros possuem um sistema inteligente, no qual, enquanto a estrada estiver vazia,
o sinal ser� vermelho. Tamb�m, durante o sinal verde, quando a estrada tiver menos que tr�s ve�culos,
assim que os mesmos acessarem a rodovia principal, o sinal ficar� vermelho antecipadamente.

Implemente uma fun��o para o gerenciamento do tr�nsito conforme ilustrado acima.
A fun��o dever� receber, como par�metro, 4 filas encadeadas (E1, E2, E3, R).
Na fun��o, os elementos de E1, E2 e E3 devem ser transferidos para R de forma que simule o tr�nsito descrito acima.

Input Format
Em cada uma das 3 primeiras linhas, enquanto -1 n�o for lido, ler n�meros inteiros e inser�-los em suas respectivas filas (E1, E2 e E3).

Constraints
O acesso aos elementos da fila deve ser atrav�s da fun��o desenfileirar.

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
