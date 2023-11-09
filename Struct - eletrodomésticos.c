/*
Implemente um programa que fa�a o controle do consumo de energia dos eletrodom�sticos de um im�vel. Primeiro leia os N eletrodom�sticos que contendo nome, pot�ncia (inteiro, em kW) e tempo ativo por dia (real, em horas). Em seguida, leia um n�mero inteiro d (quantidade de dias) e calcule:
O consumo total no imovel
O consumo total de cada eletrodom�stico
O consumo relativo de cada eletrodom�stico ((consumo/consumo total) * 100) nesse per�odo de tempo.

Input Format
Na primeira linha deve ser lido o n�mero de eletrodom�stico.
Para cada uma das N linhas seguintes, leia as seguintes informa��es para cada eletrodom�stico: nome (string), potencia (inteiro) e tempo (real).
Por fim, leia um n�mero inteiro que represente a quantidade de dias.

Constraints
N�o utize a fun��o gets para ler as strings. Em vez disso, use scanf (nos casos de teste n�o h� o caractere espa�o em branco)

Output Format
A primeira linha deve exibir o consumo total no im�vel seguido de N linhas com o consumo relativo de cada eletrodom�stico.
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
