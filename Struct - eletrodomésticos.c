/*
Implemente um programa que faça o controle do consumo de energia dos eletrodomésticos de um imóvel. Primeiro leia os N eletrodomésticos que contendo nome, potência (inteiro, em kW) e tempo ativo por dia (real, em horas). Em seguida, leia um número inteiro d (quantidade de dias) e calcule:
O consumo total no imovel
O consumo total de cada eletrodoméstico
O consumo relativo de cada eletrodoméstico ((consumo/consumo total) * 100) nesse período de tempo.

Input Format
Na primeira linha deve ser lido o número de eletrodoméstico.
Para cada uma das N linhas seguintes, leia as seguintes informações para cada eletrodoméstico: nome (string), potencia (inteiro) e tempo (real).
Por fim, leia um número inteiro que represente a quantidade de dias.

Constraints
Não utize a função gets para ler as strings. Em vez disso, use scanf (nos casos de teste não há o caractere espaço em branco)

Output Format
A primeira linha deve exibir o consumo total no imóvel seguido de N linhas com o consumo relativo de cada eletrodoméstico.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    char nome[101];
    int pot; //Potencia.
    float temp; //Tempo ativo.
}ele; //Eletrodomestico.

void imprimir(ele e, float conT){
    float cRel=0; //Consumo relativo.

    cRel = ((e.pot * e.temp) / conT) * 100;
    printf("%s %.1f\n",  e.nome, cRel);
}

int main() {
    int n; //Numero de eletrodomesticos.
    int i, dias;
    float conT=0; //Consumo total.
    float conTdias=0;
    scanf("%d", &n);

    ele eletro[n];

    for(i=0; i<n; i++){
        fflush(stdin);
        scanf("%s %d %f", &eletro[i].nome, &eletro[i].pot, &eletro[i].temp);
        conT += (eletro[i].pot * eletro[i].temp);
    }

    scanf("%d", &dias);
    conTdias = conT;
    conTdias *= dias;
    printf("%.0f\n", conTdias);
    for(i=0; i<n; i++){
        imprimir(eletro[i], conT);
    }

    return 0;
}
