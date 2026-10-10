void dividirDataEmStrings(char data[], char sDia[], char sMes[], char sAno[]){
    int icont, jcont;
    
    for (icont = 0, jcont = 0; data[icont] != '/' && jcont < 3; icont++, jcont++){
        sDia[jcont] = data[icont];
    }
    sDia[jcont] = '\0';
    
    for (icont += 1, jcont = 0; data[icont] != '/' && jcont < 3; icont++, jcont++){
        sMes[jcont] = data[icont];
    }
    sMes[jcont] = '\0';
    
    for (icont += 1, jcont = 0; data[icont] != '\0' && jcont < 5; icont++, jcont++){
        sAno[jcont] = data[icont];
    }
    sAno[jcont] = '\0';
    
}

int* converterDataParaInt(char sDia[], char sMes[], char sAno[]){
    static int intData[3];
    
    intData[0] = (sDia[0] - '0');
    intData[1] = (sMes[0] - '0');
    intData[2] = (10 * (sAno[0] - '0'));
    intData[2] += (sAno[1] - '0');
    
    if (sDia[1] >= '0' && sDia[1] <= '9'){
        intData[0] *= 10;
        intData[0] += (sDia[1] - '0');
    }
    
    if (sMes[1] >= '0' && sMes[1] <= '9'){
        intData[1] *= 10;
        intData[1] += (sMes[1] - '0');
    }
    
    if (sAno[2] >= '0' && sAno[2] <= '9'){
        intData[2] *= 100;
        intData[2] += (10 * (sAno[2] - '0'));
        intData[2] += (sAno[3] - '0');
    }
    
    return intData;
}

int ehAnoBissexto(int intAno){
    int ehBissexto = 0;
    // [99, 27] = soma com 1900
    // [26, 0] = soma com 2000
    if (intAno <= 99 && intAno >= 27)
        intAno += 1900;
    else if (intAno <= 26 && intAno >= 0)
        intAno += 2000;

    if (intAno == 2000 || intAno == 1900){
        if (intAno % 400 == 0)
            ehBissexto = 1;
    }
    else if (intAno % 4 == 0)
        ehBissexto = 1;

    return ehBissexto;
}

int validarCombinacaoMesDia(int intDia, int intMes, int ehBissexto){
    int ehValido = 1;

    switch (intMes){
        case 2: {
            if (ehBissexto){
                if (intDia > 29)
                    ehValido = 0;
            }
            else if (intDia > 28)
                ehValido = 0;

            break;
        }
        case 4: {
            if (intDia > 30)
                ehValido = 0;
            break;
        }
        case 6: {
            if (intDia > 30)
                ehValido = 0;
            break;
        }
        case 9: {
            if (intDia > 30)
                ehValido = 0;
            break;
        }
        case 11: {
            if (intDia > 30)
                ehValido = 0;
            break;
        }
    }

    return ehValido;
}

int q1(char data[]){
    int datavalida = 1;
    int *intData, intDia, intMes, intAno, ehBissexto, icont;
    char sDia[3], sMes[3], sAno[5];
    
    dividirDataEmStrings(data, sDia, sMes, sAno);

    intData = converterDataParaInt(sDia, sMes, sAno);
    intDia = intData[0];
    intMes = intData[1];
    intAno = intData[2];

    if (intDia >= 28 && intDia <= 31){
        ehBissexto = ehAnoBissexto(intAno);
        datavalida = validarCombinacaoMesDia(intDia, intMes, ehBissexto);
    }

    if (intDia < 1 || intDia > 31)
        datavalida = 0;
    else if (intMes < 1 || intMes > 12)
        datavalida = 0;
    else if ((intAno < 1900 && intAno > 99) || (intAno > 2026 || intAno < 0))
        datavalida = 0;
    
    printf("%d/%d/%d\n", intDia, intMes, intAno);
    if (datavalida)
        return 1;
    else
        return 0;
}
