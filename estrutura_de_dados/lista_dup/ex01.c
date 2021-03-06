/* 
1) Construa uma estrutura de lista duplamente ligada que permita as seguintes operações:
    a) Incluir no inicio da lista
    b) incluir no final da lista
    c) mostrar lista
    d) mostrar primos da lista
    e) mostrar lista de tras pra frente
    f) remover elemento da lista
    g) remover primos da lista
*/

// pronto
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

typedef struct elemento{
    int valor;
    struct elemento * prox;
    struct elemento * ant;
}elemento;

int escolhe_opcao();
lista * aloca_lista();
elemento * aloca_elemento();
void inclui_no_inicio(lista *l);
void inclui_no_final(lista *l);
void mostra_lista(lista *l);
void mostra_primos(lista *l);
void mostra_pelo_final(lista *l);
void remove_elemento(lista *l);
void remove_primos(lista *l);
int verifica_primo(int num);

int main()
{
    lista * numeros;
    int opcao, num;

    numeros = aloca_lista();

    void (*funcao[7])(lista *l);
    funcao[0] = inclui_no_inicio;
    funcao[1] = inclui_no_final;
    funcao[2] = mostra_lista;
    funcao[3] = mostra_primos;
    funcao[4] = mostra_pelo_final;
    funcao[5] = remove_elemento;
    funcao[6] = remove_primos;

    do{
        opcao = escolhe_opcao();

        if(opcao){
            funcao[opcao - 1](numeros);
        }
         
    }while(opcao);

    return 0;
}

void remove_primos(lista *l)
{
    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux){
            if(verifica_primo(aux->valor)){
                if(aux->ant == NULL){
                    l->inicio = aux->prox;
                }else{
                    aux->ant->prox = aux->prox;
                }

                if(aux->prox == NULL){
                    l->fim = aux->ant;
                }else{
                    aux->prox->ant = aux->ant;
                }

                l->qtd--;
                elemento * removido;
                removido = aux;
                aux = aux->prox;
                free(removido);
            }else{
                aux = aux->prox;
            }
        }
    }else
        printf("\nLista Vazia\n");
}

void remove_elemento(lista *l)
{
    int num;
    printf("\nRemover numero: ");
    scanf("%d", &num);
    
    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux){
            if(aux->valor == num){
                if(aux->ant == NULL){
                    l->inicio = aux->prox;
                }else{
                    aux->ant->prox = aux->prox;
                }

                if(aux->prox == NULL){
                    l->fim = aux->ant;
                }else{
                    aux->prox->ant = aux->ant;
                }

                l->qtd--;
                free(aux);
                break;
            }else{
                aux = aux->prox;
            }
        }
    }else
        printf("\nNumero nao encontrado\n");
}

void mostra_pelo_final(lista *l)
{
    if(l->inicio){
        elemento * aux;

        aux = l->fim;

        printf("\nElementos:");
        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->ant;
        }
        printf("\n");
    }else
        printf("\nLista vazia\n");
}

int verifica_primo(int num)
{
    int aux = 0, i;

    for(i = 2; i <= num; i++){
        if(num % i == 0){
            aux++;
        }
    }
    if(aux == 1)
        return 1;
    else
        return 0;
}

void mostra_primos(lista *l)
{
    if(l->inicio){
        elemento * aux;
        int achou_primo = 0;

        aux = l->inicio;

        printf("\nNumeros Primos:");
        while(aux)
        {
            if(verifica_primo(aux->valor)){
                printf("\n> %d", aux->valor);
                achou_primo = 1;
            }
            aux = aux->prox;
        }
        if(!achou_primo)
            printf("\n\tNenhum numero primo");

        printf("\n");
    }else
        printf("\nLista vazia\n");
}

void mostra_lista(lista *l)
{
    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        printf("\nElementos:");
        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }else
        printf("\nLista vazia\n");
}

void inclui_no_inicio(lista *l)
{
    int num;
    elemento * novo;

    printf("\nIncluir numero: ");
    scanf("%d", &num);

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        l->inicio = novo;
        novo->prox = aux;
        aux->ant = novo;

    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void inclui_no_final(lista *l)
{
    int num;
    elemento * novo;

    printf("\nIncluir numero: ");
    scanf("%d", &num);

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;

        aux = l->fim;

        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;

    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;;
    novo->ant = NULL;

    return novo;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

int escolhe_opcao()
{
    int opcao;

    printf("\n1 - Incluir no Inicio");
    printf("\n2 - Incluir No Final");
    printf("\n\n3 - Mostra Lista");
    printf("\n4 - Mostra primos");
    printf("\n5 - Mostra ao Contrario");
    printf("\n\n6 - Remover Elemento");
    printf("\n7 - Remover todos os primos");
    printf("\n0 - Sair");
    printf("\nOpcao: "); 

    scanf("%d", &opcao);
    
    return opcao;
}