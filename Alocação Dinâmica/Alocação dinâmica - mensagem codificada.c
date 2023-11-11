/*
Luciano Capitão América tem um quadro no seu programa "Geladeira do Capitão América" onde é passada uma sequência de caracteres (string) que representa um alfabeto e uma sequência de números inteiros, 
sendo cada número a posição de um determinado caractere. 
O participante deve decifrar a mensagem utilizando o alfabeto e a sequência de números inteiros.

Exemplo de alfabeto: oabeucis,-gfk Mensagem codificada: 1 7 9 10 4 5 10 8 1 5 10 1 10 11 1 13 5 Mensagem decodificada: oi,-eu-sou-o-goku

Para ajudar os participantes desse quadro no programa, implemente uma função que receba uma string (alfabeto) e um vetor de números inteiros (mensagem codificada) alocado dinamicamente. 
A função deverá retornar uma string resultante da decodificação da mensagem utilizando o alfabeto.

Input Format
Na primeira linha deve ser lida uma string Na segunda linha, enquanto -1 não for lido, deve ser lido um número inteiro.

Output Format
Deve ser impressa a mensagem decodificada.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *tradutor(char *alfa, int * cod, int n)
{
    char *str = (char*)malloc(sizeof(char) * (n + 1));
    
    for(int i = 0; i < n; i++)
        str[i] = alfa[cod[i] - 1];
        
    return str;
}

int main(void)
{
    char alfa[255];
    char * str = NULL;
    
    int n = 0;
    int x = 0;
    int cod[1000];
    
    scanf("%s", alfa);
    
    while(x != -1)
    {
        scanf("%d", &x);
        if(x != -1)
        {
            cod[n] = x;
            n++;
        }
    }
    
    str = tradutor(alfa, cod, n);
    
    printf("%s", str);
    
    free(str);
    
    return 0;
}
