/*
Implemente uma função que receba uma matriz esparsa e um vetor de números inteiros.
A função deverá comparar o vetor com cada linha da matriz. Caso o vetor seja encontrado,
deve ser retornada a linha em que o mesmo foi localizado. Caso contrário, a função deverá retornar -1.

Input Format
A primeira linha contém os números de linhas (l) e de colunas (c).
Em seguida, uma matriz deve ser lida. Lembre-se: 0 é valor nulo, ou seja, deve ser ignorado.
Por fim, deve ser lido um vetor com c elementos.

Constraints
Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.
Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez de matriz esparsa.

Output Format
Imprimir a posição da primeira linha em que o vetor foi encontrado. Caso o vetor não seja em encontrado, imprimir -1
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
        Cell *aux = NULL;

        if (l != NULL){
                aux = l->head;

                while ((aux != NULL) && (aux->item != item))
                    aux = aux->next;
        }

        if((aux != NULL) && (aux->item == item))
        {
            return 1;
        }
        else
                return 0;
}


int buscar(int item, Spa_Mat* mat){
        int i;
        int aux = 0;

        for (i = 0; ((i < mat->n_lin) && (aux == 0)); i++)
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

int verificar_linha(Spa_Mat *m, int v[], int l)
{
   if (m != NULL)
   {
        for (int i = 0; i < m->n_lin; i++)
        {
            int aux1 = 0;
            int j;
            for (j = 0; j < m->n_col; j++)
            {
                int valor = buscar_pos(i, j, m);
                if (v[j] != valor)
                    break;
                aux1++;
            }
            if (aux1 == m->n_col)
                return i;
        }
    }
    return -1;
}


int main(void)
{
    int l, c, item;

    scanf("%d %d", &l, &c);

    Spa_Mat *m = criar(l, c);

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &item);
            if(item != 0)
            {
                trocar(item, i, j , m);
            }
        }
    }

    int v[c];

    for(int i = 0; i < c; i++)
    {
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < c; i++)
    {
        if(verificar_linha(m, v, i) != -1)
        {
            printf("%d", verificar_linha(m, v, i));
            break;
        }else if(i == c - 1)
        {
            printf("%d", verificar_linha(m, v, i));
        }
    }

    return 0;
}

