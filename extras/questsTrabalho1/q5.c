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
