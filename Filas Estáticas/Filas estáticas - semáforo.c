/*
Três estradas movimentadas ligam a uma única rodovia (principal), conforme a figura abaixo. 
Para o gerenciamento do trânsito, um semáforo foi adicionado para cada estrada, na qual, enquanto o sinal estiver verde, os veículos que chegaram primeiro podem acessar a rodovia principal. 
Quando o sinal estiver verde para uma estrada, para as outras duas estradas, o sinal será vermelho. No entanto, como as estradas estão cheias de buracos e os veículos devem transitar vagarosamente, 
para cada vez que o sinal estiver verde para uma estrada, apenas três veículos conseguem acessar a estrada principal antes do sinal ficar vermelho. 
Por outro lado, os semáforos possuem um sistema inteligente, no qual, enquanto a estrada estiver vazia, o sinal será vermelho. 
Também, durante o sinal verde, quando a estrada tiver menos que três veículos, assim que os mesmos acessarem a rodovia principal, o sinal ficará vermelho antecipadamente.

         Antes                             Depois
Estrada 1 ... - 9 7 4 1
Estrada 2 ... - - - 5 2 => Rodovia Principal ... - 9 8 5 3 5 2 7 4 1  
Estrada 3 ... - - 8 5 3

Implemente uma função para o gerenciamento do trânsito conforme ilustrado acima. 
A função deverá receber, como parâmetro, 4 filas estáticas (E1, E2, E3, R). Na função, os elementos de E1, E2 e E3 devem ser transferidos para R de forma que simule o trânsito descrito acima.

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
#include <stdlib.h>
#include <limits.h>

#define TAM_MAX 10

typedef struct Fila Fila;

struct Fila{
    int item[TAM_MAX];
    int ini;
    int fim;
    int tam;
};

Fila* criar_fila(){
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

int fila_cheia(Fila *f){

    if (f == NULL)
        return -1;
    else if (f->tam < TAM_MAX)
        return 0;
    else
        return 1;
}

int fila_vazia(Fila *f){
    if (f == NULL)
        return -1;
    else if (f->tam > 0)
        return 0;
    else
        return 1;
}

int enfileirar(Fila *f, int chave){
    if (f == NULL)
        f = criar_fila();
    
    if (!fila_cheia(f)){
        if (f->ini < 0)
            f->ini = 0;
        
        if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        f->item[f->fim] = chave;

        f->tam++;

        return 1;
    }

    return 0;
}

int desenfileirar(Fila *f){
    int item = INT_MIN;

    if (!fila_vazia(f)){
        item = f->item[f->ini];

        if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}

void imprimir_fila(Fila *f){
    Fila aux = *f;
    int item;

    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

int tamanho_fila(Fila *f){
    if (f != NULL)
        return f->tam;
    else
        return 0;
}


int verificar_inicio(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->ini];
    else
        return INT_MIN;
}


int verificar_fim(Fila *f){
    if (!fila_vazia(f))
        return f->item[f->fim];
    else
        return INT_MIN;
}

void semaforo(Fila *f1, Fila *f2, Fila *f3, Fila *r)
{
    int sinal = 1;

    while((f1->tam > 0 || f2->tam > 0 || f3->tam > 0))
    {
        Fila *atual;
        if(sinal == 1)
            atual = f1;
        else if(sinal == 2)
            atual = f2;
        else
            atual = f3;
        
        int fila = 0;

        if((sinal == 1 && atual == f1) || (sinal == 2 && atual == f2) || (sinal == 3 && atual == f3))
        {
            while(fila < 3 && atual->tam > 0)
            {
                int veiculo = desenfileirar(atual);
                
                enfileirar(r, veiculo);
                fila++;
            }
        }

        sinal = (sinal % 3) + 1;
    }
}

int main(void)
{
    Fila *f1 = criar_fila();
    Fila *f2 = criar_fila();
    Fila *f3 = criar_fila();
    Fila *r = criar_fila();
    int item = 0;
    
    while(item != -1)
    {
        scanf("%d", &item);
        
        if(item != -1)
            enfileirar(f1, item);
    }
    

    item = 0;
    while(item != -1)
    {
        scanf("%d", &item);
        
        if(item != -1)
            enfileirar(f2, item);
    }
    
    item = 0;
    while(item != -1)
    {
        scanf("%d", &item);
        
        if(item != -1)
            enfileirar(f3, item);
    }
    
    semaforo(f1, f2, f3, r);
    
    imprimir_fila(r);
    
    liberar_fila(f1);
    liberar_fila(f2);
    liberar_fila(f3);
    liberar_fila(r);
    
    return 0;
}
