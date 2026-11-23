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
int inserirOrdenado(amarras *cabeca, int valor);
int removerAsAmarrasInicioLista(amarras *cabeca);
int removerAsAmarrasMeioLista(amarras *cabeca, int anteriorRef);
int removerAsAmarrasFinalLista(amarras *cabeca);
int removerAsAmarrasOrdenado(amarras *cabeca);
void selectionSortDasAmarras(amarras *cabeca);
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
                printf("Digite um valor para inserir na lista: ");
                scanf("%d", &valor);
                inserirOrdenado(cabeca, valor);
            break;

            case 5: 
                removerAsAmarrasInicioLista(cabeca);
            break;

            case 6: 
                printf("Digite um valor para ser removido: ");
                scanf("%d", &valorRef);
                removerAsAmarrasMeioLista(cabeca, valorRef);
            break;

            case 7:
                removerAsAmarrasFinalLista(cabeca);
            break;

            case 8:
                removerAsAmarrasOrdenado(cabeca);
            break;

            case 9:
                selectionSortDasAmarras(cabeca);
            break;
        
            default: printf("Opção inválida.\n");
        }

        printf("Olha como ficou a lista encabeçada:\n");
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
    printf("4. Inserir ordenado\n");
    printf("5. Remover do inicio\n");
    printf("6. Remover do  meio\n");
    printf("7. Remover do final\n");
    printf("8. Remover ordenado\n");
    printf("9. Ordenar as amarras\n");
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

int inserirOrdenado(amarras *cabeca, int valor){
    amarras *novo = malloc(sizeof(amarras));

    if (novo == NULL)
        return ERRO_DE_MEMORIA;
    else {
        novo->valor = valor;
        while (cabeca->prox != NULL && cabeca->prox->valor < valor){
            cabeca = cabeca->prox;
        }
        novo->prox = cabeca->prox;
        cabeca->prox = novo;
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

int removerAsAmarrasOrdenado(amarras *cabeca){
    amarras *aux, *menor;
    
    if (cabeca->prox == NULL)
        return LISTA_VAZIA;
    else {
        aux = cabeca->prox;
        menor = aux;
        menor->valor = aux->valor;
        while (aux->prox){
            if (aux->prox->valor < menor->valor){
                menor = aux->prox;
                menor->valor = aux->prox->valor;
                cabeca = aux;
            }
            aux = aux->prox;
        }
        cabeca->prox = menor->prox;
        free(menor);
        return SUCESSO;
    }
}

void selectionSortDasAmarras(amarras *cabeca){
    amarras *aux, *menor;
    int temp;
    
    while (cabeca->prox != NULL){
        menor = cabeca->prox;
        aux = menor->prox;
        while (aux != NULL){
            if (aux->valor < menor->valor){
                menor = aux;
            }
            aux = aux->prox;
        }

        temp = cabeca->prox->valor;
        cabeca->prox->valor = menor->valor;
        menor->valor = temp;

        cabeca = cabeca->prox;
    }
    
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