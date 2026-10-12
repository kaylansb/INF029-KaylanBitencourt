int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int digitoNumBusca, digitoNumBase, achou = 0;
    int numBuscaTemp, digitoBuscaTemp, numBaseTemp, digitoBaseTemp;

    if (numerobusca < 10)
        digitoNumBusca = numerobusca;
    else
        digitoNumBusca = numerobusca % 10;
        
    numerobusca /= 10;
    
    while (numerobase > 0){
        digitoNumBase = numerobase % 10;
        numerobase /= 10;
        if (digitoNumBase == digitoNumBusca){
            numBuscaTemp = numerobusca;
            numBaseTemp = numerobase;
            achou = 1;
            while (achou && numBuscaTemp > 0){
                digitoBaseTemp = numBaseTemp % 10;
                numBaseTemp /= 10;
                digitoBuscaTemp = numBuscaTemp % 10;
                numBuscaTemp /= 10;
                if (digitoBaseTemp != digitoBuscaTemp)
                    achou = 0;
            }

            if (achou){
                qtdOcorrencias++;
                achou = 0;
                numerobase = numBaseTemp;
            }
        }
    }

    return qtdOcorrencias;
}
