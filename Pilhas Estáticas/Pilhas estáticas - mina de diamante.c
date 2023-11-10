/*
O Sr. Alcídes está trabalhando em uma mina para extrair o máximo que consegue de diamantes "<>".
Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante,
novos diamantes poderão ser encontrados. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados:
"O primeiro é retirado de "<..>", "<>" e "<.......>".
Implemente uma função que receba uma string representado a carga com areia e diamante.
A função deverá retornar a quantidade de diamantes contidas na carga.
Para a solução do problema, deve ser utilizada uma pilha estática.
Para a implementação do exercício, utilize um TAD de pilhas estáticas,
podendo ser um dos códigos que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste.
Cada linha a seguir é uma string que contém apenas os seguintes caracteres: "<", ">" e ".".

Constraints
Os elementos da pilha podem ser manipulados apenas utilizando funções de empilhar e desempilhar.

Output Format
A quantidade de diamantes possíveis de serem extraídos em cada caso de entrada deve ser impressa.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TAM_MAX 150

typedef struct{
    int topo;
    char item[TAM_MAX];
}Pilha;

int pilha_cheia(Pilha *p) {
    return (p->topo == TAM_MAX - 1); //Se o valor do topo da pilha for igual ao Maximo menos 1, ela retorna 0 para verdadeiro, 1 para falso.
}
//A verificacao de pilha cheia e vazia retorna valores booleanos.
int pilha_vazia(Pilha *p) {
    return (p->topo == -1); //Se a pilha estiver -1 ela retorna 0 para verdadeiro, 1 para falso, e erro quando é NULL, -1 no caso.
}

void empilhar(Pilha *p, char item)
{
    if(!pilha_cheia(p))
    {
        p->topo++; //Incrementa o valor do topo da pilhar. Ex: [-1] ++ [0].
        p->item[p->topo] = item; //O item que a funcao esta recebendo vai para o topo da pilha.
    }
}

char desempilhar(Pilha *p)
{
    if(!pilha_vazia(p))
    {
        char c = p->item[p->topo]; //Passa o item do topo da pilha para a variavel.
        p->topo--; //Desincrementa o topo.
        return c; //Retorna o item que estava no topo.
    }
    return '\0';
}


int caca_tesouro(char *str)
{
    int tesouro = 0; //Seria os diamantes que sao pedidos no exercicio.
    int i;
    Pilha p;
    p.topo = -1; //Pois quando empilhar algo sobe pro primeiro indice do vetor [0].

    for(i=0; str[i] != '\0'; i++)
    {
        if(str[i] == '<')
        {
            empilhar(&p, str[i]);
        }
        else if(str[i] == '>' && desempilhar(&p) == '<')
        {
            tesouro++;
        }
    }

    return tesouro;
}

int main(void)
{
    int n; //Quantidade de strings para analisar os casos.
    int i;
    scanf("%d", &n);

    char str[TAM_MAX];

    for(i = 0; i < n; i++)
    {
        scanf("%s", str);
        printf("%d\n", caca_tesouro(str));
    }

    return 0;
}
