#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;

}lista; 


typedef struct elemento{
    int valor;
    struct elemento * prox;

}elemento;

// funcoes <<<<<<<<<<<<<<<<<<<<<<<<<
void inclui_elemento(lista *l, int x);
void mostra_elementos(lista *l);
elemento* aloca_elemento();
void remove_elemento(lista *l, int num);
int achou_numero(lista *l, int n);

// funcoes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main()
{
    lista * numeros;

    numeros = (lista*)malloc(sizeof(lista));
    numeros->qtd = 0;
    numeros->inicio = NULL;

    int opcao = 1, num;
    while(opcao <=3 && opcao > 0){
        printf("\n1 - cadastra\n2 - mostra\n3 - remove\nopcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Num: ");
            scanf("%d", &num);
            inclui_elemento(numeros, num);
        }else if(opcao == 2){
            mostra_elementos(numeros);
        }else if(opcao == 3){
            printf("remover numero: ");
            scanf("%d", &num);
            remove_elemento(numeros, num);
        }
    }

    return 0;
}

int achou_numero(lista *l, int n)
{
    int achou = 0;

    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux)
        {
            if(aux->valor == n){
                achou = 1;
                break;
            }
            aux = aux->prox;
        }
    }

    return achou;
}

void remove_elemento(lista *l, int num)
{
    if(achou_numero(l, num)){

        if(l->qtd == 1){
            l->inicio = NULL;
            l->qtd -= 1;
            printf("\nNumero removido\n\n");
        }else{
            elemento *aux, *ant;
            int primeira_exec = 1;

            aux = l->inicio;
            while(aux){
                
                if(aux->valor == num){
                    if(primeira_exec){
                        l->inicio = aux->prox;
                        break;
                    }else{
                        ant->prox = aux->prox;
                        break;
                    }
                }
                
                if(primeira_exec){
                    ant = l->inicio;
                    primeira_exec++;
                }else{
                    ant = ant->prox;
                }

                aux = aux->prox;
            }
        }

    }else{
        printf("\nO numero nao esta na lista\n\n");
    }
    
}

elemento* aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void mostra_elementos(lista *l)
{
    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux)
        {
            printf("> %d\n", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\tLista vazia\n");
    }
}

void inclui_elemento(lista *l, int x)
{
    elemento *novo;

    novo = aloca_elemento();

    novo->valor = x;

    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }else{
        l->inicio = novo; 
    }

    l->qtd += 1;
}