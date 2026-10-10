#include <stdio.h>

int verificarQtdDiasEmMes(int mes, int ano);
int ehAnoBissexto(int ano);

int main() {
    int diaInicial = 29, mesInicial = 2, anoInicial = 2020;
    int diaFinal = 28, mesFinal = 2, anoFinal = 2021;
    int qtdDias, qtdMeses, qtdAnos;
    int diasDoMesAnterior, ehBissexto = 1;
    
    printf("Data Inicial: %d/%d/%d\n", diaInicial, mesInicial, anoInicial);
    printf("Data Final: %d/%d/%d\n\n", diaFinal, mesFinal, anoFinal);
    
    qtdDias = 0;
    qtdMeses = 0;
    qtdAnos = 0;
    
    if ((mesFinal == 2) && (diaFinal == 28))
        ehBissexto = ehAnoBissexto(anoFinal);
    
    qtdAnos = anoFinal - anoInicial;
    if (mesInicial > mesFinal){
        qtdMeses = (12 - (mesInicial - mesFinal));
        qtdAnos--;
    }
    else if ((mesInicial == mesFinal) && (diaInicial > diaFinal) && ehBissexto){
        qtdMeses = 12;
        qtdAnos--;
    }
    else {
        qtdMeses = mesFinal - mesInicial;
    }
    
    if (diaInicial > diaFinal && ehBissexto){
        if (mesFinal - 1 < 1)
            diasDoMesAnterior = verificarQtdDiasEmMes(12, anoFinal);
        else
            diasDoMesAnterior = verificarQtdDiasEmMes(mesFinal - 1, anoFinal);
        
        qtdDias = (diasDoMesAnterior - (diaInicial - diaFinal));
        qtdMeses--;
    }
    else if (diaInicial <= diaFinal) {
        qtdDias = diaFinal - diaInicial;
    }
    
    printf("%d dias, %d meses e %d anos\n", qtdDias, qtdMeses, qtdAnos);
    
    return 0;
}

int ehAnoBissexto(int ano){
    int ehBissexto = 0;
    
    if (ano <= 99 && ano >= 27)
        ano += 1900;
    else if (ano <= 26 && ano >= 0)
        ano += 2000;

    if (ano == 2000 || ano == 1900){
        if (ano % 400 == 0)
            ehBissexto = 1;
    }
    else if (ano % 4 == 0)
        ehBissexto = 1;

    return ehBissexto;
}

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