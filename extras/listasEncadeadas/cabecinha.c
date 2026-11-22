#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

enum {ERRO_DE_MEMORIA = -10, SUCESSO, VALOR_NAO_ENCONTRADO, LISTA_VAZIA, };

typedef struct lacos {
    int valor;
    struct lacos *prox;
} amarras;

void exibirMenu();
int inserirInicioLista(amarras *cabeca, int valor);
int inserirMeioLista(amarras *cabeca, int valor, int anteriorRef);
int inserirFimLista(amarras *cabeca, int valor);
int removerAsAmarrasInicioLista(amarras *cabeca);
int removerAsAmarrasMeioLista(amarras *cabeca, int anteriorRef);
int removerAsAmarrasFinalLista(amarras *cabeca);
void imprimirLista(amarras *cabeca);
void iWantToBreakFree(amarras **lista);

int main(){
    printf("aqui conterá listas encadeadas cabeçudissímas!\n");
    amarras *cabeca = malloc(sizeof(amarras));
    cabeca->prox = NULL;
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
                inserirInicioLista(cabeca, valor);
            break;

            case 2: 
                printf("Digite um valor para inserir na lista e um valor de referência: ");
                scanf("%d %d", &valor, &valorRef);
                inserirMeioLista(cabeca, valor, valorRef);
            break;

            case 3: 
                printf("Digite um valor para inserir na lista: ");
                scanf("%d", &valor);
                inserirFimLista(cabeca, valor);
            break;

            case 4: 
                removerAsAmarrasInicioLista(cabeca);
            break;

            case 5: 
                printf("Digite um valor para ser removido: ");
                scanf("%d", &valorRef);
                removerAsAmarrasMeioLista(cabeca, valorRef);
            break;

            case 6:
                removerAsAmarrasFinalLista(cabeca);
            break;
        
            default: printf("Opção inválida.\n");
        }

        printf("Olha como está a lista encabeçada:\n");
        imprimirLista(cabeca);
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
    printf("4. Remover do inicio\n");
    printf("5. Remover do  meio\n");
    printf("6. Remover do final\n");
    printf("---------------------------\n");
    printf("Digite sua escolha: ");
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
    if (novo == NULL){
        printf("Erro ao alocar memória.\n");
        return ERRO_DE_MEMORIA;
    }
    else {
        novo->valor = valor;
        novo->prox = NULL;
        while (cabeca->prox){
            cabeca = cabeca->prox;
        }
        cabeca->prox = novo;
        return SUCESSO;
    }
}

int removerAsAmarrasInicioLista(amarras *cabeca){
    amarras *aux;

    if (cabeca->prox == NULL)
        return LISTA_VAZIA;
    else {
        aux = cabeca->prox;
        cabeca->prox = aux->prox;
        free(aux); 
    }
    return SUCESSO;
}

int removerAsAmarrasMeioLista(amarras *cabeca, int anteriorRef){
    amarras *aux = cabeca->prox;
    
    if (cabeca->prox == NULL)
        return LISTA_VAZIA;
    else {
        while (aux != NULL && aux->valor != anteriorRef){
            aux = aux->prox;
            cabeca = cabeca->prox;
        }
        if (aux == NULL)
            return VALOR_NAO_ENCONTRADO;
        else {
            cabeca->prox = aux->prox;
            free(aux);
        }
    }
}

int removerAsAmarrasFinalLista(amarras *cabeca){
    amarras *aux;

    if (cabeca->prox == NULL)
        return LISTA_VAZIA;
    else {
        while ((cabeca->prox)->prox){
            cabeca = cabeca->prox;
        }
        aux = cabeca->prox;
        cabeca->prox = NULL;
        free(aux);
    }
    return SUCESSO;
}

void imprimirLista(amarras *cabeca){
    
    while (cabeca->prox){
        printf("%d\t", cabeca->prox->valor);
        cabeca = cabeca->prox;
    }
    printf("\n\n");
}

void iWantToBreakFree(amarras **lista){
    amarras *aux;
    while (*lista){
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
}