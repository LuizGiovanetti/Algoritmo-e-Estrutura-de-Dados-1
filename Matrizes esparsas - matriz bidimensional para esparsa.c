/*
Implemente uma função que converta uma matriz de números em uma matriz esparsa.

Input Format
A primeira linha contém os números de linhas e de colunas. Em seguida, uma matriz deve ser lida.

Output Format
Matriz esparsa impressa no seguinte formato: "linha_i: -> coluna_j,item -> coluna_k,item"
Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".
Exemplo de matriz 3x3 e sua respectiva representação esparsa: 1 0 2 0 0 0 3 3 3
0: -> 0,1 -> 2,2 1: -> 2: -> 0,3 -> 1,3 -> 2,3
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;
typedef struct ListaE ListaE;
typedef struct Spa_Mat Spa_Mat;

struct Cell{
        int item;
        int col;
        Cell *next;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
};


Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int col){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->item = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}


static int procurar_lista(int item, ListaE *l){
        Cell *aux;

        if (l != NULL){
                aux = l->head;

                while ((aux != NULL) && (aux->item != item))
                    aux = aux->next;
        }

        if ((aux != NULL) && (aux->item == item))
                return 1;
        else
                return 0;
}


int buscar(int item, Spa_Mat* mat){
        int i;
        int aux = 0;

        for (i = 0; (i < mat->n_lin) && (aux == 0); i++)
                aux = procurar_lista(item, mat->lin[i]);

        return aux;
}


static int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}


int buscar_pos(int l, int c, Spa_Mat* mat){
    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c > aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}


static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head;
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next;
            auxA->next = novo;
        }
    }
}


static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (l->head != NULL){
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA;

            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }

            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}


void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}


void imprimir(Spa_Mat* mat){
    int i, j;
    Cell* aux;

    for (i = 0; i < mat->n_lin; i++){
        aux = mat->lin[i]->head;
        j = 0;

        while (aux != NULL){
            while (j < aux->col){
                printf("0 ");
                j++;
            }

            printf("%d ", aux->item);
            j++;
            aux = aux->next;
        }

        for (j = 0; j < mat->n_col; j++)
            printf("0 ");

        printf("\n");
    }
}

Spa_Mat* bidimensional_2_esparsa(int **m, int l, int c)
{
    int i, j;
    Spa_Mat *me = NULL;

    if(m != NULL)
    {
        me = criar(l, c);

        for(i = 0; i < l; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(m[i][j] != 0)
                    trocar(m[i][j], i, j, me);
            }
        }
    }

    return me;
}

void imprimir_listas(Spa_Mat *m)
{
    if(m != NULL)
    {
        for(int i = 0; i < m->n_lin; i++)
        {
            printf("%d:", i);

            if(m->lin[i]->head != NULL)
            {
                Cell *aux = m->lin[i]->head;

                while(aux != NULL)
                {
                    printf(" -> %d,%d", aux->col, aux->item);

                    aux = aux->next;
                }
            }else
                printf(" -> ");

            printf("\n");
        }
    }
}

int main(void)
{
    int l, c;
    Spa_Mat *mat;
    int **m;

    scanf("%d %d", &l, &c);

    m = (int**)malloc(sizeof(int*) * l);

    for(int i = 0; i < l; i++)
    {
        m[i] = (int*)malloc(sizeof(int) * c);
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    mat = bidimensional_2_esparsa(m, l, c);

    imprimir_listas(mat);

    return 0;
}
