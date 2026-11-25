#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct amarras {
    int info;
    int tam;
    struct amarras *prox;
} amarras;

typedef struct estMain {
    int info;
    int tam;
    int *estruturaAux;
} estMain;

void inserirNoFim(amarras *cabeca, int info);
void pegarValores(amarras *cabeca, estMain main[]);
void imprimirEstrutura(estMain main[]);
void imprimirAmarras(amarras *cabeca);
void liberar(amarras **lista, estMain main[]);

int main() {
    amarras *cabeca = malloc(sizeof(amarras));
    if (cabeca == NULL)
        return 1;
    cabeca->prox = NULL;
    estMain main[TAM];
    int valor, opcao, sair = 0;
     
    while (!sair){
        printf("Digite opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao){
            case 0: sair = 1;
            break;
            
            case 1: 
                printf("digite valor: ");
                scanf("%d", &valor);
                inserirNoFim(cabeca, valor);
                printf("\n");
            break;
        }
    }
    imprimirAmarras(cabeca);
    
    pegarValores(cabeca, main);
    imprimirEstrutura(main);
    liberar(&cabeca, main);
    
    return 0;
}

void inserirNoFim(amarras *cabeca, int info){
    amarras *novo = malloc(sizeof(amarras));
    if (novo == NULL)
        return;
    
    novo->info = info;
    novo->tam = 6;
    while (cabeca->prox){
        cabeca = cabeca->prox;
    }
    novo->prox = NULL;
    cabeca->prox = novo;
    
}

void pegarValores(amarras *cabeca, estMain main[]){
    int i, j;
    
    cabeca = cabeca->prox;
    for (i = 0; i < TAM; i++){
        main[i].info = cabeca->info;
        main[i].tam = cabeca->tam;
        cabeca = cabeca->prox;
        main[i].estruturaAux = malloc(main[i].tam*sizeof(estMain));
        if (main[i].estruturaAux == NULL)
            return;
        
        for (j = 0; j < main[i].info; j++, cabeca = cabeca->prox){
            main[i].estruturaAux[j] = cabeca->info;
        }
    }
}

void imprimirAmarras(amarras *cabeca){

    printf("\nA Lista: ");
    cabeca = cabeca->prox;
    while (cabeca){
        printf("%d\t", cabeca->info);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void imprimirEstrutura(estMain main[]){
    int i, j;

    printf("\n");    
    for (i = 0; i < TAM; i++){
        printf("%d: ", main[i].info);
        for (j = 0; j < main[i].info; j++){
            printf("%d ", main[i].estruturaAux[j]);
        }
        printf("\n");
    }
}

void liberar(amarras **lista, estMain main[]){
    int i;
    amarras *aux;
    
    for (i = 0; i < TAM; i++)
        free(main[i].estruturaAux);
    
    while (*lista){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}