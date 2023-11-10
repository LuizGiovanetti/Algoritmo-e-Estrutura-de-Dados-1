/*
Implemente uma função que receba uma string (str), uma variável do tipo char (c), um ponteiro do tipo int e um ponteiro do tipo float. 
Na função, a quantidade de vezes que o caratere c aparece na string de entrada deve ser armazenada no ponteiro do tipo int e a taxa de incidência desse caractere dentro da string (quantidade / tamanho da string) 
deve ser armazenada no ponteiro de float.

Input Format
Na primeira linha deve ser lida uma string.
Na segunda linha, um caractere.

Constraints
A impressão do número real deve ter duas casas decimais.

Output Format
Na primeira linha deve ser impressa a quantidade de caracteres e na segunda, a taxa de incidência desse caractere dentro da string.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void qnt_incidencia(char str[], char c, int *qnt, float *inc)
{
    int i = 0;
    
    while(str[i] != '\0')
    {
        if(str[i] == c)
        {
            (*qnt)++;
        }
        i++;
    }
    *inc = (float)*qnt / i;
}

int main(void)
{
    char str[50];
    char c;
    /*int qnt = 0;
    float inc = 0;*/
    
    int aux = 0;
    int *qnt = &aux; 
    
    float auxf = 0;
    float *inc = &auxf;
    
    scanf("%s %c", str, &c);
       
    //qnt_incidencia(str, c, &qnt, &inc);
    
    qnt_incidencia(str, c, qnt, inc);
    
    //printf("%d\n%.2f", qnt, inc);
    
    printf("%d\n%.2f", *qnt, *inc);
    
    return 0;
}
