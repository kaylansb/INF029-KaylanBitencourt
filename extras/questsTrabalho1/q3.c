int q3(char *texto, char c, int isCaseSensitive)
{
    int icont, qtdOcorrencias = 0;
    
    if (!isCaseSensitive && (c >= 'A' && c <= 'Z'))
        c += 32;

    for (icont = 0; texto[icont]; icont++){
        if (texto[icont] == c)
            qtdOcorrencias++;

        else if (!isCaseSensitive && texto[icont] + 32 == c)
            qtdOcorrencias++;
    }

    
    return qtdOcorrencias;
}
