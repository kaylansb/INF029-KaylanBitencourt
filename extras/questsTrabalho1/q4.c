int tamString(char *str){
    int icont, tam = 0;

    for (icont = 0; str[icont]; icont++){
        if (str[icont] != -61)
            tam++;
    }

    return tam;
}

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int icont, jcont, kcont, lcont;
    int tam, acentos = 0, achou = 0, qtdOcorrencias = 0;

    tam = tamString(strBusca);
    
    for (icont = 0, lcont = 0; strTexto[icont]; icont++){

        if (strTexto[icont] == strBusca[0]){
            achou = 1;
            jcont = 1;
            kcont = icont + 1;
            while (achou && strBusca[jcont] != '\0'){
                if (strTexto[kcont] != strBusca[jcont])
                    achou = 0;

                kcont++;
                jcont++;
            }
        }

        if (achou){
            qtdOcorrencias++;
            posicoes[lcont] = (kcont - jcont - acentos) + 1;
            posicoes[lcont + 1] = (icont + tam) - acentos;
            lcont += 2;
            achou = 0;
        }

        if (strTexto[icont] == -61)
            acentos++;

    }

    return qtdOcorrencias;
}
