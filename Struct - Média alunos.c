/*
Crie uma estrutura representando os alunos de um determinado curso.
A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova,
nota da segunda prova e nota da terceira prova.

(a) Permita ao usuário entrar com os dados de n alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando a média 6 para aprovação.

Input Format

A primeira linha é composta por um número n de alunos. Seguem a matricula (numérico até 65000),
nome (string max 255 caracteres) e 3 notas (float com 1 casa de precisão)

Output Format

A saída devera informar, para cada aluno se ele foi aprovado ou reprovado.
Seguido das soluções para as questões (b), (c) e (d)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[255];
    float nota[3];
}aluno;

float media(float nota[], int n){
    int i;
    float soma = 0.0;
    for(i=0; i<n; i++){
        soma += nota[i];
    }
    return soma/(float)n;
}

void imprimir_resultado(aluno v[], int n){
    int i;

    for(i=0; i<n; i++){
        if(media(v[i].nota, 3) < 6.0)
        {
            printf("Reprovado!\n");
        }
        else
        {
            printf("Aprovado!\n");
        }
    }
}

void maior(aluno v[], int n){
    int i, p;
    float aux, maior;

    p=0;
    maior = media(v[0].nota, 3);

    for(i=1; i<n; i++){
        aux = media(v[i].nota, 3);
            if(aux > maior){
                p = i;
                maior = aux;
            }
    }
    printf("O aluno com maior media e: %d %s %.1f\n", v[p].matricula, v[p].nome, maior);
}

void menor(aluno v[], int n){
    int i, p;
    float aux, menor;

    p=0;
    menor = media(v[0].nota, 3);

    for(i=1; i<n; i++){
        aux = media(v[i].nota, 3);
            if(aux < menor){
                p = i;
                menor = aux;
            }
    }
    printf("O aluno com menor media e: %d %s %.1f\n", v[p].matricula, v[p].nome, menor);
}

void maior_P1(aluno v[], int n){
    int i, p;
    float aux, maior;
    p=0;
    maior = v[0].nota[0]; //media(v[0].nota, 3);

    for(i=1; i<n; i++){
        aux = v[i].nota[0];
            if(aux > maior){
                p = i;
                maior = aux;
            }
    }
    printf("O aluno com maior P1 e: %d %s %.1f\n", v[p].matricula, v[p].nome, maior);
}

int main() {
    int n, i;

    scanf("%d", &n);

    aluno v[n];

    for(i=0; i<n; i++){
        scanf("%d", &v[i].matricula);
        scanf("%s", v[i].nome);
        scanf("%f %f %f", &v[i].nota[0], &v[i].nota[1], &v[i].nota[2]);
    }

    imprimir_resultado(v, n);
    maior(v, n);
    menor(v, n);
    maior_P1(v, n);

    return 0;
}
