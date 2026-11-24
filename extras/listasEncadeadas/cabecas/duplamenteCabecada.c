#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct lacos {
    int valor;
    struct lacos *prox;
    struct lacos *anterior;
} amarras;

void exibirMenu();
void inserirNoInicio(amarras *cabeca, int valor);
void inserirNoMeio(amarras *cabeca, int valor, int anteriorRef);
void inserirNoFim(amarras *cabeca, int valor);
void imprimirAmarras(amarras *cabeca);
void iWantToBreakFree(amarras **lista);

int main(){
    amarras *cabeca = malloc(sizeof(amarras));
    if (cabeca == NULL)
        return 1;
    cabeca->prox = NULL;
    cabeca->anterior = NULL;

    int opcao, valor, valorRef, sair = FALSE;

    while (!sair){
        exibirMenu();
        scanf("%d", &opcao);
    
        switch (opcao){
            case 0: 
                sair = TRUE;
            break;
            
            case 1:
                printf("Digite um valor para inserir na lista: ");
                scanf("%d", &valor);
                inserirNoInicio(cabeca, valor);
            break;

            case 2:
                printf("Digite um valor para inserir na lista e um valor de referencia: ");
                scanf("%d %d", &valor, &valorRef);
                inserirNoMeio(cabeca, valor, valorRef);
            break;

            case 3:
                printf("Digite um valor para inserir na lista: ");
                scanf("%d", &valor);
                inserirNoFim(cabeca, valor);                
            break;

            default: printf("Valor invalido.\n");
        }

        imprimirAmarras(cabeca);
    }


    iWantToBreakFree(&cabeca);

    return 0;
}

void exibirMenu(){
        printf("---------------------------\n");
    printf("0. Sair\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no meio\n");
    printf("3. Inserir no final\n");
    printf("---------------------------\n");
    printf("Digite sua escolha: ");
}

void inserirNoInicio(amarras *cabeca, int valor){
    amarras *novo = malloc(sizeof(amarras));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->anterior = cabeca;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}

void inserirNoMeio(amarras *cabeca, int valor, int anteriorRef){
    amarras *novo = malloc(sizeof(amarras));
    if (novo == NULL)
        return;

    cabeca = cabeca->prox;
    while (cabeca && cabeca->valor != anteriorRef){
        cabeca = cabeca->prox;
    }
    if (cabeca){
        novo->valor = valor;
        novo->prox = cabeca->prox;
        novo->anterior = cabeca;
        cabeca->prox = novo;
    }
}

void inserirNoFim(amarras *cabeca, int valor){
    amarras *novo = malloc(sizeof(amarras));

    if (novo == NULL)
        return;

    novo->valor = valor;
    while (cabeca->prox){      // obs: poderia deixar essa func
        cabeca = cabeca->prox; // só com esse while e chamar inserirNoInicio
    }
    novo->prox = NULL;
    novo->anterior = cabeca;
    cabeca->prox = novo;
}

void removerNoInicio(amarras *cabeca){
    if (cabeca->prox == NULL)
        return;
    
    
}

void imprimirAmarras(amarras *cabeca){

    printf("\nA Lista: ");
    cabeca = cabeca->prox;
    while (cabeca){
        printf("%d\t", cabeca->valor);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void iWantToBreakFree(amarras **lista){
    amarras *aux;

    while (*lista){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}