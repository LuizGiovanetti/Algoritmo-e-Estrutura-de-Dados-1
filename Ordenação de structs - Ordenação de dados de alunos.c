/*
Adapte um dos algorimos de ordenação para o vetor de elementos da seguinte estrutura:

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;
A ordenação deve ser por nome. Caso haja registros com o mesmo nome, o critério de ordenação nesse caso é a matrícula.

Input Format
Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler os dados de cada elemento do vetor.

Output Format
Imprimir os registro ordenados. Diferentemente da forma leitura, cada registro deve ser impresso em uma linha.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

void bubbleSort(Aluno *vet, int tam)
{
    Aluno aux;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = 0; j < tam - i - 1; j++)
        {
            int resultado = strcmp(vet[j].nome, vet[j + 1].nome);

            if(resultado > 0 || (resultado == 0 && vet[j].matricula > vet[j + 1].matricula))
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

int main(void)
{
    int tam;
    scanf("%d", &tam);

    Aluno *alunos = (Aluno*)malloc(sizeof(Aluno) * tam);

    for(int i = 0; i < tam; i++)
    {
        alunos[i].nome = (char*)malloc(sizeof(char) * 100);
        alunos[i].curso = (char*)malloc(sizeof(char) * 100);

        scanf("%d", &alunos[i].matricula);
        scanf("%s", alunos[i].nome);
        scanf("%s", alunos[i].curso);
        scanf("%f", &alunos[i].coef);
    }

    bubbleSort(alunos, tam);

    for(int i = 0; i < tam; i++)
    {
        printf("%s %d %s %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].curso, alunos[i].coef);
    }

    for(int i = 0; i < tam; i++)
    {
        free(alunos[i].nome);
        free(alunos[i].curso);
    }

    free(alunos);

    return 0;
}

