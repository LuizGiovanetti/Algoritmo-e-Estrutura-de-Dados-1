/*
Crie um TAD para processamento de matrizes com a seguinte estrutura e operações, onde m é a matriz, l é a quantidade de linhas e c é a quantidade de colunas:

typedef struct{
    int **arr; // Matriz l x c (arranjo bidimensional)
    int l; // quantidade de linhas
    int c; // quantidade de colunas
}Matriz;

Matriz * iniciar(int l, int c);


// A matriz recebe x na posição [i][j]
void alterar(Matriz *m, int x, int i, int j);


// Retorna a linha da matriz na posição i

Exemplo:
arr[][] = {{1, 2, 3, 4},
	   {5, 6, 7, 8},
       {9, 10, 11, 12}
}

Linha na posição 1: {5, 6, 7, 8} 

int *obter_linha(Matriz *m, int i);


// Retorna a coluna da matriz na posição i

Exemplo:
arr[][] = {{1, 2, 3, 4},
	   {5, 6, 7, 8},
       {9, 10, 11, 12}
}
Coluna na posição 2: {3, 7, 11} 

int *obter_coluna(Matriz *m, int i);

// obter sub-matriz

Exemplo:
arr[][] = {{1, 2, 3, 4},
	   {5, 6, 7, 8},
       {9, 10, 11, 12}
}
li = 1, ci = 1, lf = 2, cf = 2

submat = {{6, 7},
	      {10, 11}}

Matriz *obter_submat(Matriz *m, int li, int ci, int lf, int cf);
Observação: não é necessário considerar o arquivo .h, já que no HackerRank não tem como "upar" arquivos .h e .c.

Input Format
Na primeira linha, devem ser lidos dois números inteiros (e.g. l e c).
Em seguida, ler l x c elementos.
Após, ler dois números inteiros, sendo o primeiro a posição de uma linha (pl) e o segundo, a posição de uma coluna (pc).
Por fim, ler quatro números inteiros referentes a posição de uma submatriz.

Output Format
Na primeira linha, imprimir a linha da posição pl retornada pela função obter_linha.
Na segunda linha, imprimir '\n'.
Na terceira linha, imprimir a coluna da posição pc retornada pela função obter_coluna.
Na quarta linha, imprimir '\n'.
A partir da quinta linha, imprimir a submatriz.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int **m;
    int l; 
    int c; 
}Matriz;

Matriz *iniciar(int l, int c)
{
    Matriz *m = (Matriz*)malloc(sizeof(Matriz));
    
    m->l = l;
    m->c = c;
    
    m->m = (int**)malloc(sizeof(int*) * l);
        
    for(int i = 0; i < l; i++)
        m->m[i] = (int*)malloc(sizeof(int) * c);
    
    return m;
}

void inserir(Matriz *m, int x, int i, int j)
{
    if(m != NULL)
        m->m[i][j] = x;
}

int *obter_linha(Matriz *m, int pl)
{
    if((m != NULL) && (pl >= 0) && (pl < m->l))
    {
        int *v = (int*)malloc(sizeof(int) * m->c);
        for(int i = 0; i < m->c; i++)
            v[i] = m->m[pl][i];
        return v;
    }
    return NULL;
}

int *obter_coluna(Matriz *m, int pc)
{
    if((m != NULL) && (pc >= 0) && (pc < m->c))
    {
        int *v = (int*)malloc(sizeof(int) * m->l);
        for(int i = 0;i < m->l; i++)
                v[i] = m->m[i][pc];
        
        return v;
    }
    return NULL;
}

Matriz *obter_submat(Matriz *m, int li, int ci, int lf, int cf)
{
    if((m != NULL) && (m->m != NULL) && (li >= 0) && (ci >= 0) && (lf < m->l) && (cf < m->c) && (li < lf) && (ci < cf))
    {
        int submat_l = (lf - li) + 1;
        int submat_c = (cf - ci) + 1;
        Matriz *submat = iniciar(submat_l, submat_c);
        
        if(submat != NULL)
        {
            for(int i = 0; i < submat_l; i++)
            {
               for(int j = 0; j < submat_c; j++)
                   submat->m[i][j] = m->m[li + i][ci + j];
            }
            return submat;
        } 
    }
    
    return NULL;
}

void imprimir_vetor(int *v, int n)
{
    if(v != NULL)
    {
        for(int i = 0; i < n; i++)
            printf("%d ", v[i]);

        printf("\n\n");
    }
}

void imprimir_submat(Matriz *m)
{
    if((m != NULL) && (m->m != NULL))
    {
        for(int i = 0; i < m->l; i++)
        {
            for(int j = 0; j < m->c; j++)
                printf("%d ",m->m[i][j]);
            
            printf("\n");
        }
    }
    
}

int main(void)
{
    int l, c, pl, pc, li, lf, ci, cf, item;
    
    scanf("%d %d", &l, &c);
    
    Matriz *m = iniciar(l, c);
    
    for(int i = 0; i < l; i ++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &item);
            inserir(m, item, i, j);
        }
    }
      
    scanf("%d %d", &pl, &pc);
    
    scanf("%d %d %d %d", &li, &ci, &lf, &cf);
    
    int *v_lin = obter_linha(m, pl);
    int *v_col = obter_coluna(m, pc);
    Matriz *submat = obter_submat(m, li, ci, lf, cf);
    
    imprimir_vetor(v_lin, c);
    imprimir_vetor(v_col, l);
    imprimir_submat(submat);
    
    
    free(m);
    free(v_lin);
    free(v_col);
    free(submat);
    
    return 0;
}
