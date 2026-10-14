// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
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


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
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
            int *intData, diasDoMesAnterior, ehBissexto = 0;
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

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
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

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
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

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int resultado = 0, digitoAtual;

    while (num > 0){
        digitoAtual = num % 10;
        num /= 10;
        resultado = (resultado * 10) + digitoAtual;
    }

    num = resultado;
    
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

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

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

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



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
