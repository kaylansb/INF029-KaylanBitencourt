int verificarQtdDiasEmMes(int mes, int ano){
    int qtdDias;
    
    switch (mes){
        case 2: {
            if (ehAnoBissexto(ano))
                qtdDias = 29;
            else
                qtdDias = 28;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11:
            qtdDias = 30;
            break;
        
        default: {
            qtdDias = 31;
        }
    }
    
    return qtdDias;
}

int verificarMaiorData(char data1[], char data2[]){
    int *intData, intDia1, intMes1, intAno1;
    int intDia2, intMes2, intAno2;
    char sDia[3], sMes[3], sAno[5];

    dividirDataEmStrings(data1, sDia, sMes, sAno);

    intData = converterDataParaInt(sDia, sMes, sAno);
    intDia1 = intData[0];
    intMes1 = intData[1];
    intAno1 = intData[2];

    dividirDataEmStrings(data2, sDia, sMes, sAno);

    intData = converterDataParaInt(sDia, sMes, sAno);
    intDia2 = intData[0];
    intMes2 = intData[1];
    intAno2 = intData[2];

    if (intAno1 > intAno2)
        return 1;
    else if ((intMes1 > intMes2) && (intAno1 == intAno2))
        return 1;
    else if ((intDia1 > intDia2) && (intMes1 == intMes2) && (intAno1 == intAno2))
        return 1;
    else
        return 0;
}

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
        if (verificarMaiorData(datainicial, datafinal)){
            dma.retorno = 4;
            return dma;
        }
        else {
            //calcule a distancia entre as datas
            int diaInicial, mesInicial, anoInicial;
            int diaFinal, mesFinal, anoFinal;
            int *intData, diasDoMesAnterior;
            char sDia[3], sMes[3], sAno[5];

            dividirDataEmStrings(datainicial, sDia, sMes, sAno);

            intData = converterDataParaInt(sDia, sMes, sAno);
            diaInicial = intData[0];
            mesInicial = intData[1];
            anoInicial = intData[2];

            dividirDataEmStrings(datafinal, sDia, sMes, sAno);

            intData = converterDataParaInt(sDia, sMes, sAno);
            diaFinal = intData[0];
            mesFinal = intData[1];
            anoFinal = intData[2];
    
            if ((mesInicial == 2 && diaInicial == 29) && ehAnoBissexto(anoInicial))
                diaInicial--;
            
            dma.qtdAnos = anoFinal - anoInicial;
            if (mesInicial > mesFinal){
                dma.qtdMeses = ((12 - mesInicial) + mesFinal); // 12 - (mesInicial - mesFinal)
                dma.qtdAnos--;
            }
            else
                dma.qtdMeses = mesFinal - mesInicial;
            
            
            if (diaInicial > diaFinal){
                if (mesFinal - 1 < 1)
                    diasDoMesAnterior = verificarQtdDiasEmMes(12, anoFinal);
                else
                    diasDoMesAnterior = verificarQtdDiasEmMes(mesFinal - 1, anoFinal);
                
                dma.qtdDias = ((diasDoMesAnterior - diaInicial) + diaFinal); // diasDoMesAnterior - (diaInicial - diaFinal)

                if (dma.qtdMeses > 0)
                    dma.qtdMeses--;
                else {
                    dma.qtdMeses = 11;
                    dma.qtdAnos--;
                }    
            }
            else
                dma.qtdDias = diaFinal - diaInicial;

            //se tudo der certo
            dma.retorno = 1;
            return dma;
        }
    }
}
