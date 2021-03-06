/*
Faça um programa que receba do usuario um número N inteiro positivo, e aloque dinamicamente um vetor de N sanduíches.
Cada sanduíche deve armazenara as segunites informações:
    nome
    valor
    peso
    avaliacao
Solicite ao usuário que preencha os N sanduíches e mostre na tela:
    a) A lista dos sanduiches que comecam com a letra A:
    b) Qual é o sanduíche melhor avaliado
    c) Qual é o peso médio dos sanduíches.
    d) Em caso de compra de 3 de cada um dos sanduíches qual será o valor da compra?
*/
// pronto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct burger{
    char * nome;
    float valor;
    float peso;
    float avaliacao;
}burger;

void cadastra_sanduiche(burger *sand);
void mostra_letra_a(burger *sand, int n);
void mostra_melhor_avaliado(burger *sand, int n);
void mostra_peso_medio(burger *sand, int n);
void mostra_preco_total(burger *sand, int n);

int main()
{

    int n;
    burger *sand;

    printf("Digite um numero N: ");
    scanf("%d", &n);

    sand = (burger*)malloc(sizeof(burger)*n);

    for(int i = 0; i < n; i++){
        printf("%d:\n", i+1);
        cadastra_sanduiche(&sand[i]);
    }

    mostra_letra_a(sand, n);

    mostra_melhor_avaliado(sand, n);

    mostra_peso_medio(sand, n);

    mostra_preco_total(sand, n);

    printf("\n");
    return 0;
}

void mostra_letra_a(burger *sand, int n)
{
    int tem_letra = 0;

    printf("\nNomes que comecam com \'a\':");
    for(int i = 0; i < n; i++){
        if(sand[i].nome[0] == 'a' || sand[i].nome[0] == 'A'){
            tem_letra = 1;
            printf("\n%s", sand[i].nome);
        }
    }

    if(!tem_letra){
        printf("\nNenhum nome comeca com \'a\'\n");
    }

}

void mostra_melhor_avaliado(burger *sand, int n)
{
    float melhor = 0;
    for(int i = 0; i < n; i++){
        if(sand[i].avaliacao >= melhor){
            melhor = sand[i].avaliacao;
        }
    }

    printf("\nSanduiche com melhor avaliacao:");
    for(int i = 0; i < n; i++){
        if(sand[i].avaliacao == melhor){
            printf("\n%s\nAvaliacao: %.2f\nR$%.2f\n%.2f gramas\n", sand[i].nome, sand[i].avaliacao, sand[i].valor, sand[i].peso);
        }
    }

}

void mostra_peso_medio(burger *sand, int n)
{
    float peso = 0;
    for(int i = 0; i < n; i++){
        peso += sand[i].peso;
    }

    printf("\nPeso medio dos sanduiches: %.2f gramas", peso/n);
}

void mostra_preco_total(burger *sand, int n)
{
    float preco_total = 0;
    for(int i = 0; i < n; i++){
        preco_total += (sand[i].valor * 3);
    }

    printf("\nPreco se pedir 3 de cada: R$%.2f", preco_total);
}

void cadastra_sanduiche(burger *sand)
{
    char nome[50];

    printf("\nNome: ");
    scanf("%s", nome);

    sand->nome = (char*)malloc(sizeof(char)*strlen(nome));
    strcpy(sand->nome, nome);

    printf("\nValor: ");
    scanf("%f", &sand->valor);

    printf("\nPeso: ");
    scanf("%f", &sand->peso);

    printf("\nAvaliacao: ");
    scanf("%f", &sand->avaliacao);
}
