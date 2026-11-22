#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

typedef struct {
    int *estruturaAux;
    int tamEstruturaAux;
    int posOcupadas;
}
estruturaPrincipal;


estruturaPrincipal vetorPrincipal[TAM] = {0};

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;

    // se posição é um valor válido {entre 1 e 10}
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;

    // o tamanho nao pode ser menor que 1
    else if (tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    // a posicao pode já existir estrutura auxiliar
    else if (vetorPrincipal[posicao - 1].estruturaAux != NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    
    else {
        vetorPrincipal[posicao - 1].estruturaAux = malloc(tamanho*sizeof(int));
        // o tamanho ser muito grande
        if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;

        // deu tudo certo, crie
        else {
            vetorPrincipal[posicao - 1].tamEstruturaAux = tamanho;
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1].estruturaAux == NULL){
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        else {
            if (vetorPrincipal[posicao - 1].posOcupadas >= vetorPrincipal[posicao - 1].tamEstruturaAux){
                retorno = SEM_ESPACO;
            }

            else {
                //insere
                retorno = SUCESSO;
                vetorPrincipal[posicao - 1].estruturaAux[vetorPrincipal[posicao - 1].posOcupadas] = valor;
                vetorPrincipal[posicao - 1].posOcupadas++;
            }
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if (vetorPrincipal[posicao - 1].posOcupadas == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        vetorPrincipal[posicao - 1].posOcupadas--;
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
// pensar em um nome melhor dps (sobrescreverUmValorEmVetor?)
void deletar(int estruturaAux[], int tamEstruturaAux, int posicaoDeletada){
    int i;
    for (i = posicaoDeletada + 1; i < tamEstruturaAux; i++)
        estruturaAux[i - 1] = estruturaAux[i];
}
// 3 2 4 6
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    int i;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if (vetorPrincipal[posicao - 1].posOcupadas == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else {
        for (i = 0; i < vetorPrincipal[posicao - 1].tamEstruturaAux; i++){
            if (valor == vetorPrincipal[posicao - 1].estruturaAux[i])
                break;
        }
        if (i == vetorPrincipal[posicao - 1].tamEstruturaAux)
            retorno = NUMERO_INEXISTENTE;
        else {
            deletar(vetorPrincipal[posicao - 1].estruturaAux, vetorPrincipal[posicao - 1].tamEstruturaAux, i);
            vetorPrincipal[posicao - 1].posOcupadas--;
        }
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int i;

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else {
        for (i = 0; i < vetorPrincipal[posicao - 1].posOcupadas; i++)
            vetorAux[i] = vetorPrincipal[posicao - 1].estruturaAux[i];
        
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
// OBS: eu pensei em fazer isso pegando os dados da estrutura, ordenando eles e dps jogar no vetorAux
// mas o objetivo quer q pegue os dados, jogue no vetor primeiro e dps ordene dentro do vetor
void insertionSort(int vetor[], int vetTam){
    int i, j, key;

    for (i = 1; i < vetTam; i++){
        key = vetor[i];
        j = i - 1;

        while (j >= 0 && key < vetor[j]){
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = key;
    }
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;

    retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (retorno == SUCESSO)
        insertionSort(vetorAux, vetorPrincipal[posicao - 1].posOcupadas);
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    int i, j, k;

    for (i = 0, k = 0; i < TAM; i++){
        for (j = 0; j < vetorPrincipal[i].posOcupadas; j++, k++){
            retorno = SUCESSO;
            vetorAux[k] = vetorPrincipal[i].estruturaAux[j];
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    int i, j, k;

    for (i = 0, k = 0; i < TAM; i++){
        for (j = 0; j < vetorPrincipal[i].posOcupadas; j++, k++){
            retorno = SUCESSO;
            vetorAux[k] = vetorPrincipal[i].estruturaAux[j];
        }
    }

    if (retorno == SUCESSO)
        insertionSort(vetorAux, k);

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
// verificar novo tamanho
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    novoTamanho = (vetorPrincipal[posicao - 1].tamEstruturaAux + novoTamanho);

    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if (novoTamanho < 1)
        retorno = NOVO_TAMANHO_INVALIDO;
    else {
        int *temp = realloc(vetorPrincipal[posicao - 1].estruturaAux, novoTamanho*sizeof(int));
        if (temp == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else {
            if (vetorPrincipal[posicao - 1].posOcupadas > novoTamanho)
                vetorPrincipal[posicao - 1].posOcupadas = novoTamanho;

            vetorPrincipal[posicao - 1].tamEstruturaAux = novoTamanho;
            vetorPrincipal[posicao - 1].estruturaAux = temp;
            retorno = SUCESSO;
        }
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    int retorno = 0;
    
    if (posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetorPrincipal[posicao - 1].estruturaAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if (vetorPrincipal[posicao - 1].posOcupadas == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        retorno = vetorPrincipal[posicao - 1].posOcupadas;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

int getQuantidadeTodosElementosEstruturasAuxiliares(){
    int i, qtdPorChamada, totalElementos = 0;

    for (i = 0; i < TAM; i++){
        qtdPorChamada = getQuantidadeElementosEstruturaAuxiliar(i+1);
        if (qtdPorChamada > 0)
            totalElementos += qtdPorChamada;
    }

    return totalElementos;
}

int inserirNoFimDaLista(No *cabeca, int valor){
    No *novo = malloc(sizeof(No));
    
    if (novo == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    else {
        novo->conteudo = valor;
        novo->prox = NULL;
        
        while (cabeca->prox){
            cabeca = cabeca->prox;
        }
        cabeca->prox = novo;
    }

    return 0;
}

No *montarListaEncadeadaComCabecote()
{
    No *retorno;
    int i, erroAlocacao = 0, qtdElementos = getQuantidadeTodosElementosEstruturasAuxiliares();
    
    if (qtdElementos == 0)
        retorno = NULL;
    else {
        int valoresEstruturas[qtdElementos];
        No *cabeca = malloc(sizeof(No));
        cabeca->prox = NULL;

        getDadosDeTodasEstruturasAuxiliares(valoresEstruturas);
        for (i = 0; i < qtdElementos && !erroAlocacao; i++)
            erroAlocacao = inserirNoFimDaLista(cabeca, valoresEstruturas[i]);
        
        retorno = cabeca;
    }

    return retorno;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;
    inicio = inicio->prox;
    while (inicio){
        vetorAux[i] = inicio->conteudo;
        inicio = inicio->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *aux;
    while (*inicio){
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
    }
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
// ??
void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    int i;
    for (i = 0; i < TAM; i++)
        free(vetorPrincipal[i].estruturaAux);
}
