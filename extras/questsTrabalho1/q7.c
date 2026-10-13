int procurarStringDiagonalAbaixoEsquerda(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont >= 8 || jcont < 0) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont++;
        jcont--;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAbaixoDireita(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont >= 8 || jcont >= 10) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont++;
        jcont++;
        kcont++;
    }

    return achou;
}


int procurarStringDiagonalAcimaEsquerda(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont < 0 || jcont < 0) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont--;
        jcont--;
        kcont++;
    }

    return achou;
}

int procurarStringDiagonalAcimaDireita(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont < 0 || jcont >= 10) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont--;
        jcont++;
        kcont++;
    }

    return achou;
}

int procurarStringEsquerda(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((jcont < 0) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        jcont--;
        kcont++;
    }

    return achou;
}

int procurarStringDireita(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((jcont >= 10) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        jcont++;
        kcont++;
    }

    return achou;
}

int procurarStringAbaixo(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont >= 8) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont++;
        kcont++;
    }

    return achou;
}

int procurarStringAcima(char matriz[8][10], char palavra[], int icont, int jcont, int kcont){
    int achou = 1;
    
    while (palavra[kcont] != '\0'){
        if ((icont < 0) || (matriz[icont][jcont] != palavra[kcont])){
            achou = 0;
            break;
        }
        icont--;
        kcont++;
    }

    return achou;
}


int verificarSringEmMatriz(char matriz[8][10], char palavra[], int icont, int jcont){
    int existe = 0;

    existe = procurarStringAcima(matriz, palavra, icont-1, jcont, 1);
    if (!existe)
        existe = procurarStringAbaixo(matriz, palavra, icont+1, jcont, 1);
    else
        return existe;

    if (!existe)
        existe = procurarStringDireita(matriz, palavra, icont, jcont+1, 1);
    if (!existe)
        existe = procurarStringEsquerda(matriz, palavra, icont, jcont-1, 1);
    else
        return existe;
        
    if (!existe)
        existe = procurarStringDiagonalAcimaDireita(matriz, palavra, icont-1, jcont+1, 1);
    if (!existe)
        existe = procurarStringDiagonalAcimaEsquerda(matriz, palavra, icont-1, jcont-1, 1);
    else
        return existe;
    
    if (!existe)
        existe = procurarStringDiagonalAbaixoDireita(matriz, palavra, icont+1, jcont+1, 1);
    if (!existe)
        existe = procurarStringDiagonalAbaixoEsquerda(matriz, palavra, icont+1, jcont-1, 1);
    
    return existe;
}


 int q7(char matriz[8][10], char palavra[5])
 {
     int icont, jcont, achou = 0;

    for (icont = 0; icont < 8 && !achou; icont++){
        for (jcont = 0; jcont < 10 && !achou; jcont++){
            if (matriz[icont][jcont] == palavra[0]){
                achou = verificarSringEmMatriz(matriz, palavra, icont, jcont);
            }
        }
    }

     return achou;
 }
