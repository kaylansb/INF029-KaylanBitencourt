#include <stdio.h>
#include <stdlib.h>

enum {ERRO_DE_MEMORIA = -5, SUCESSO, VALOR_NAO_ENCONTRADO, };

typedef struct lacos {
    int valor;
    struct lacos *prox;
} amarras;

int inserirInicioLista(amarras *cabeca, int valor);
int inserirMeioLista(amarras *cabeca, int valor, int anteriorRef);
int inserirFimLista(amarras *cabeca, int valor);
void imprimirLista(amarras *cabeca);
void iWantToBreakFree(amarras **lista);

int main(){
    printf("aqui conterá listas encadeadas cabeçudissímas!\n");

    amarras *cabeca = malloc(sizeof(amarras));
    cabeca->prox = NULL;

    inserirInicioLista(cabeca, 10);
    inserirFimLista(cabeca, 20);
    inserirMeioLista(cabeca, 15, 10);

    imprimirLista(cabeca);
    
    iWantToBreakFree(&cabeca);

    return 0;
}

int inserirInicioLista(amarras *cabeca, int valor){
    amarras *novo = malloc(sizeof(amarras));
    if (novo == NULL){
        printf("Erro ao alocar memória.\n");
        return ERRO_DE_MEMORIA;
    }
    else {
        novo->valor = valor;
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
    }
    return SUCESSO;
}

int inserirMeioLista(amarras *cabeca, int valor, int anteriorRef){
    amarras *novo = malloc(sizeof(amarras));
    if (novo == NULL){
        printf("Erro ao alocar memória.\n");
        return ERRO_DE_MEMORIA;
    }
    else {
        while (cabeca && cabeca->valor != anteriorRef){
            cabeca = cabeca->prox;
        }
        if (cabeca){
            novo->valor = valor;
            novo->prox = cabeca->prox;
            cabeca->prox = novo;
            return SUCESSO;
        }
        else {
            printf("Valor de referência não encontrado.\n");
            free(novo);
            return VALOR_NAO_ENCONTRADO;
        }
    }
}

int inserirFimLista(amarras *cabeca, int valor){
    amarras *novo = malloc(sizeof(amarras));
    if (novo = NULL){
        printf("Erro ao alocar memória.\n");
        return ERRO_DE_MEMORIA;
    }
    else {
        novo->valor = valor; // trava aq
        novo->prox = NULL;
        while (cabeca->prox){
            cabeca = cabeca->prox;
        }
        cabeca->prox = novo;
        return SUCESSO;
    }
}

void imprimirLista(amarras *cabeca){
    
    while (cabeca->prox){
        printf("%d\n", cabeca->prox->valor);
        cabeca = cabeca->prox;
    }
}

void iWantToBreakFree(amarras **lista){
    amarras *aux;
    while (*lista){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}