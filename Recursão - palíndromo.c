/*
Implemente uma função recursiva que verifique se uma string é palíndromo.

Input Format
Na primeira linha, deve ser lida uma string.

Constraints
Se a função não for recursiva, será atribuída nota 0 (zero).

Output Format
Imprimir "palindromo" se a string de entrada for palíndromo, ou imprimir "não palindromo", caso contrário.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void palindromo(char *str, int i, int j)
{   
    if(i == j || (str[i] == str[j] && (i == j-1)))
    {
        printf("palindromo");
    }
    else if(str[i] != str[j])
    {
        printf("nao palindromo");
    }
    else if(str[i] == str[j])
        palindromo(str, i-1, j+1);
    
}

int main(void)
{
    char str[100];
        
    scanf("%s", str);
    
    palindromo(str, strlen(str) - 1, 0);
     
    return 0;
}
