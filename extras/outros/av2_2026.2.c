#define TAM 10

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

int definirMedia(EstruturaPrin vetPrin[], int posicao){
    int i, media = 0;

    for (i = 0; i < vetPrin[posicao].posOcupadas; i++)
        media += vetPrin[posicao].estruturaAux[i];

    media /= vetPrin[posicao].posOcupadas;
    return media;
}

void pegarDados(EstruturaPrin vetPrin[], int vetAux[]){
    int i, j, k, media;

    for (k = 0, i = 0; i < TAM; i++){
        media = definirMedia(vetPrin, i);
        for (j = 0; j < vetPrin[i].posOcupadas; j++){
            if (vetPrin[i].estruturaAux[j] > media){
                vetAux[k] = vetPrin[i].estruturaAux[j];
                k++;
            }
        }
    }
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

int obterMaxTamEstruturas(EstruturaPrin vetPrin[]){
    int i, maxTam = 0;

    for (i = 0; i < TAM; i++)        // era para ser posOcupadas aq e chamar essa funcao dentro da insereLista
        maxTam += vetPrin[i].tamAux; // e ter outra funcao para pegar o maximo so para declarar o vetAux :/

    return maxTam;
}

int main() {
    No *cabeca = malloc(sizeof(No));
    if (cabeca == NULL)
        return 1;
    cabeca->prox = NULL;
    cabeca->anterior = NULL;
    
    EstruturaPrin vetPrin[TAM];
    
    int tam = obterMaxTamEstruturas(vetPrin);
    int vetAux[tam];

    pegarDados(vetPrin, vetAux);
    insereLista(cabeca, vetAux, tam);

    return 0;
}