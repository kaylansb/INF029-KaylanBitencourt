#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define TAM 5

typedef struct no {
    int valor;
    struct no *prox;
    struct no *anterior;
} No;

typedef struct estruturaPrin {
    int tamAux;
    int posOcupadas;
    int *estruturaAux;
} EstruturaPrin;

void exibirMenu();
void prepararEstrutura(EstruturaPrin vetPrin[]);
void criarEstruturas(EstruturaPrin vetPrin[]);

int obterMaxTamEstruturas(EstruturaPrin vetPrin[]);
void insereLista(No *cabeca, int vetAux[], int tam);
int pegarDadosEVetTam(EstruturaPrin vetPrin[], int vetAux[]);
int definirMedia(EstruturaPrin vetPrin[], int posicao);

void imprimirEstrutura(EstruturaPrin main[]);
void imprimirAmarras(No *cabeca);
void iWantToBreakFree(No **lista, EstruturaPrin main[]);

int main() {
    int i, valor, opcao, sair = 0;

    No *cabeca = malloc(sizeof(No));
    if (cabeca == NULL)
        return 1;
    cabeca->prox = NULL;
    cabeca->anterior = NULL;

    EstruturaPrin vetPrin[TAM] = {0};
    
    prepararEstrutura(vetPrin);
    imprimirEstrutura(vetPrin);

    int maxTam = obterMaxTamEstruturas(vetPrin);
    int vetAux[maxTam];    
    printf("max tam do vetAux: %d\n", maxTam);
    
    int tamAtual = pegarDadosEVetTam(vetPrin, vetAux);
    if (tamAtual == 0)
        printf("Nao foi possivel obter nenhum dado");
    else {
        printf("\nValores do vetAux: ");
        for (i = 0; i < tamAtual; i++)
            printf("%d ", vetAux[i]);
        printf("\n");

        insereLista(cabeca, vetAux, tamAtual);
        imprimirAmarras(cabeca);
    }

    iWantToBreakFree(&cabeca, vetPrin);

    return 0;
}

void exibirMenu(){
    printf("---------------------------\n");
    printf("0. Sair\n");
    printf("1. Inserir/criar\n");
    printf("---------------------------\n");
    printf("Digite sua escolha: ");
}

void prepararEstrutura(EstruturaPrin vetPrin[]){
    int opcao, valor, posicao, sair = FALSE;

    criarEstruturas(vetPrin);

    while (!sair){
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
            case 0: sair = TRUE;
            break;

            case 1:  
                printf("Digite a posicao da estrutura principal a ser inserida: ");
                scanf("%d", &posicao);
                printf("Digite o valor: ");
                scanf("%d", &valor);
                vetPrin[posicao - 1].estruturaAux[vetPrin[posicao - 1].posOcupadas] = valor;
                vetPrin[posicao - 1].posOcupadas++;
            break;

            default: printf("invalido\n");
        }
    }
}

void criarEstruturas(EstruturaPrin vetPrin[]){
    int opcao, tam, posicao, sair = FALSE;

    while (!sair){
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao){
            case 0: sair = TRUE;
            break;

            case 1:
                printf("Digite a posicao da estrutura principal a ser criada: ");
                scanf("%d", &posicao);
                printf("Digite qtd elementos: ");
                scanf("%d", &tam);
                vetPrin[posicao - 1].estruturaAux = malloc(tam*sizeof(int));
                if (vetPrin[posicao - 1].estruturaAux == NULL)
                    return;
                vetPrin[posicao - 1].tamAux = tam;
            break;

            default: printf("invalido\n");
        }
    }
}

int obterMaxTamEstruturas(EstruturaPrin vetPrin[]){
    int i, maxTam = 0;

    for (i = 0; i < TAM; i++)
        maxTam += vetPrin[i].tamAux;

    return maxTam;
}

void insereLista(No *cabeca, int vetAux[], int tam){
    int i;

    for (i = 0; i < tam; i++){
        No *novo = malloc(sizeof(No));
        if (novo == NULL)
            return;

        novo->valor = vetAux[i];
        if (cabeca->prox == NULL)
            novo->prox = NULL;
        else {
            cabeca->prox->anterior = novo;
            novo->prox = cabeca->prox;
        }
        novo->anterior = cabeca;
        cabeca->prox = novo;
    }
}

int pegarDadosEVetTam(EstruturaPrin vetPrin[], int vetAux[]){
    int i, j, k, media;

    for (k = 0, i = 0; i < TAM; i++){
        media = definirMedia(vetPrin, i);
        printf("Estrutura %d, media: %d\n", i+1, media);
        for (j = 0; j < vetPrin[i].posOcupadas; j++){
            if (vetPrin[i].estruturaAux[j] > media){
                vetAux[k] = vetPrin[i].estruturaAux[j];
                k++;
            }
        }
    }

    return k;
}

int definirMedia(EstruturaPrin vetPrin[], int posicao){
    int i, media = 0;

    for (i = 0; i < vetPrin[posicao].posOcupadas; i++)
        media += vetPrin[posicao].estruturaAux[i];

    if (media != 0 || vetPrin[posicao].posOcupadas != 0)
        media /= vetPrin[posicao].posOcupadas;
    
    return media;
}

void imprimirAmarras(No *cabeca){

    printf("\nA Lista: ");
    cabeca = cabeca->prox;
    while (cabeca){
        printf("%d ", cabeca->valor);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void imprimirEstrutura(EstruturaPrin vetPrin[]){
    int i, j;

    printf("\n");    
    for (i = 0; i < TAM; i++){
        printf("%d: ", i+1);
        for (j = 0; j < vetPrin[i].posOcupadas; j++){
            printf("%d ", vetPrin[i].estruturaAux[j]);
        }
        printf("\n");
    }
}

void iWantToBreakFree(No **lista, EstruturaPrin vetPrin[]){
    int i;
    No *aux;
    
    for (i = 0; i < TAM; i++)
        free(vetPrin[i].estruturaAux);
    
    while (*lista){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}