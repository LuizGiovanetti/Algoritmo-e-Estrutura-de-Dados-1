/*
Implemente um programa que receba dois números inteiros. A função deverá retornar a soma dos números.

Input Format
Na primeira linha devem ser lidos 2 números inteiros

Output Format
A soma dos números deve ser impresso.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int somar(int a, int b){
    int soma;
    
    soma=a+b;
    
    return soma;
}

int main() {
    int a, b, soma;
    
    scanf("%d %d", &a, &b);
    
    soma = somar(a, b);
    
    printf("%d", soma);
    
    return 0;   
}
