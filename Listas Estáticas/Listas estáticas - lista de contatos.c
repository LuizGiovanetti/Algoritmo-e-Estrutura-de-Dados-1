/*
Dada uma função que receba uma lista estática de contatos e uma string. 
Essa função deverá imprimir os contatos que contêm essa string no nome. Por exemplo, para a string "son", podem ser encontrados nomes como: Son**ia, Ander**son, Jeffer**son**.

Input Format
A primeira linha a ser lida deve ser a string que deve ser procurada. Em seguida, deve ser lida um número inteiro referente à quantidade de nomes que devem ser incluídos na lista.

Constraints
Usar TAD de listas estáticas.

Output Format
Imprimir os nomes que contêm a string procurada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Contato{
    char nome[MAX_SIZE];
}Contato;

typedef struct Lista{
    Contato item[MAX_SIZE];
    int tam;
}Lista;


Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}


int lista_vazia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam > 0)
        return 0;
    else
        return 1;
}


int lista_cheia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam < MAX_SIZE)
        return 0;
    else
        return 1;
}

int inserir(Lista *l, char *busca){
    if (!lista_cheia(l)){
        strcpy(l->item[l->tam].nome, busca);

        l->tam++;

        return 1;
    }

 
    return 0;
}

int compare_indice(char *str,  char *busca)
{
    while(*str && *busca)
    {
        if(*str != *busca)
        {
            return 0;
        }
 
        str++;
        busca++;
    }
    
    return (*busca == '\0');
}
 
char *comparar(char *str,  char *busca)
{
    while(*str != '\0')
    {
        if((*str == *busca) && compare_indice(str, busca))
        {
            return str;
        }
        str++;
    }
 
    return NULL;
}

void imprimir_lista_de_contato(Lista *l, char *busca)
{
    if(!lista_vazia(l))
    {
        for(int i = 0; i < l->tam; i++)
        {
            if(comparar(l->item[i].nome, busca) != NULL)
                printf("%s\n", l->item[i].nome);
        }
    }
}



int main(void)
{
    char busca[MAX_SIZE];
    int n;
    
    Lista *l = criar_lista();
    
    scanf("%s", busca);
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        char nome[MAX_SIZE];
        
        scanf("%s", nome);
        inserir(l, nome);
    }
    
    imprimir_lista_de_contato(l, busca);
    
    free(l);
      
    return 0;
}
