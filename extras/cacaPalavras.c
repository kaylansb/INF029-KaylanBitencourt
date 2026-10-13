#include <stdio.h>
#define lin 5
#define col 5


void exibirCacaPalavras(char matriz[][col]);

int verificarSringEmMatriz(char matriz[lin][col], char str[], int icont, int jcont);

int procurarStringAcima(char matriz[lin][col], char str[], int icont, int jcont, int kcont);
int procurarStringAbaixo(char matriz[lin][col], char str[], int icont, int jcont, int kcont);

int procurarStringDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont);
int procurarStringEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont);

int procurarStringDiagonalAcimaDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont);
int procurarStringDiagonalAcimaEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont);

int procurarStringDiagonalAbaixoDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont);
int procurarStringDiagonalAbaixoEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont);

int main(){
    int icont, jcont, achou = 0;  
    char str[] = "efkr";
    char matriz[lin][col] = {
    {'e', 'a', 'b', 'c', 'd'},
    {'l', 'f', 'g', 'h', 'i'},
    {'t', 'j', 'k', 'm', 'n'},
    {'o', 'p', 'q', 'r', 's'},
    {'n', 'u', 'v', 'w', 'x'}, };
    
    while (achou < 2){
        exibirCacaPalavras(matriz);
        printf("Digite uma palavra do Caca Palavras:\n");
        for (icont = 0; icont < lin && !achou; icont++){
            for (jcont = 0; jcont < col && !achou; jcont++){
                if (matriz[icont][jcont] == str[0]){
                    achou += verificarSringEmMatriz(matriz, str, icont, jcont);
                }
            }
        }
    }
    //printf("achou? %s", achou? "SIM" : "NÃO");

    return 0;
}

void exibirCacaPalavras(char matriz[][col]){
    int icont, jcont;

    for (icont = 0; icont < lin; icont++){
        for (jcont = 0; jcont < col; jcont++){
            printf("%c\t");
        }
        printf("\n");
    }
    printf("\n");
}

int verificarSringEmMatriz(char matriz[lin][col], char str[], int icont, int jcont){
    int existe = 0;

    existe = procurarStringAcima(matriz, str, icont-1, jcont, 1);
    if (!existe)
        existe = procurarStringAbaixo(matriz, str, icont+1, jcont, 1);
    else
        return existe;

    if (!existe)
        existe = procurarStringDireita(matriz, str, icont, jcont+1, 1);
    if (!existe)
        existe = procurarStringEsquerda(matriz, str, icont, jcont-1, 1);
    else
        return existe;
        
    if (!existe)
        existe = procurarStringDiagonalAcimaDireita(matriz, str, icont-1, jcont+1, 1);
    if (!existe)
        existe = procurarStringDiagonalAcimaEsquerda(matriz, str, icont-1, jcont-1, 1);
    else
        return existe;
    
    if (!existe)
        existe = procurarStringDiagonalAbaixoDireita(matriz, str, icont+1, jcont+1, 1);
    if (!existe)
        existe = procurarStringDiagonalAbaixoEsquerda(matriz, str, icont+1, jcont-1, 1);
    
    return existe;
}

int procurarStringAcima(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont < 0) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont--;
        kcont++;
    }

    return achou;
}

int procurarStringAbaixo(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont >= lin) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont++;
        kcont++;
    }

    return achou;
}

int procurarStringDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((jcont >= col) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        jcont++;
        kcont++;
    }

    return achou;
}

int procurarStringEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((jcont < 0) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        jcont--;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAcimaDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont < 0 || jcont >= col) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont--;
        jcont++;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAcimaEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont < 0 || jcont < 0) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont--;
        jcont--;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAbaixoDireita(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont >= lin || jcont >= col) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont++;
        jcont++;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAbaixoEsquerda(char matriz[lin][col], char str[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (str[kcont] != '\0'){
        if ((icont >= lin || jcont < 0) || (matriz[icont][jcont] != str[kcont])){
            achou = 0;
            break;
        }
        icont++;
        jcont--;
        kcont++;
    }

    return achou;
}
