#include <stdio.h>
#define maxCarac 100
#define maxNomes 5
#define maxCaracPorNome (maxCarac / maxNomes)
#define maxNomeSexTam 9+1+1 // o nome "masculino" + \n + \0
#define TRUE 1
#define FALSE 0

typedef struct {
    int matricula;
    char nome[maxCarac];
    char sexo[maxNomeSexTam];
    int dataNasc;
    int cpf;
}
infoAlunosProfs;

// LEMBRAR DE COLOCAR ESSAS 3 VARIAVEIS ABAIXO NO MAIN
// E PASSAR ELAS POR PARAMETROS (de galho em galho)

// questionar se qtdAlunosCadastrados nao pode realmente ser 
// uma variavel global, pq passar ela toda hora por parametros
// e ter q ficar retornando o valor dela para ela msm
// e ainda ajeitar as condicoes da variavel saida para 
// conversar certinho com os retornos de qtdAlunosCadastrados (gambiarra)

int qtdAlunosCadastrados = 0;
infoAlunosProfs aluno[maxNomes];
infoAlunosProfs professor[maxNomes];

void painelOpcoes(){
    printf("Escolha uma das opções para interagir:\n");
    printf("0 - Sair/Apagar tudo\n");
    printf("1 - Página Alunos\n");
    printf("2 - Página Professores\n");
    printf("3 - Página Disciplinas\n");
    printf("4 - Busque um Nome Cadastrado\n");
    printf("5 - Aniversariantes do Mes\n");
}

void painelInformacoes(){
    printf("Escolha uma das opcoes para realizar:\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastros\n");
    printf("2 - Listar Matriculados\n");
    printf("3 - Listar os Nomes Por Ordem\n");
    printf("4 - Listar Por Sexo\n");
    printf("5 - Listar as Datas de Nascimento Por Ordem\n");
}

void painelCadastro(){
    printf("Escolha uma das opcoes para realizar:\n");
    printf("0 - Voltar\n");
    printf("1 - Novo Cadastro\n");
    printf("2 - Atualizar Cadastro\n");
    printf("3 - Deletar Cadastro\n");
}

int validarNascimento(int idxAluno){
    int ehValido;
    int dia, mes, ano;
    
    dia = aluno[idxAluno].dataNasc / 1000000; 
    mes = (aluno[idxAluno].dataNasc % 1000000) / 10000;
    ano = aluno[idxAluno].dataNasc % 10000;
    
    if (ano > 2026 || ano < 1900) // poderia botar tudo em uma linha só
        ehValido = FALSE;       // mas acho q assim fica mais organizado/legível.
    else if (mes > 12 || mes < 1)
        ehValido = FALSE;
    else if (dia > 31 || dia < 1)
        ehValido = FALSE;
    else
        ehValido = TRUE;
        
    return ehValido;
}

void cadastrarAluno(int idxAluno){
    int cadastroValido = FALSE;
    
    printf("Digite o Número de Matrícula: ");
    scanf("%d", &aluno[idxAluno].matricula);
    getchar();
    
    printf("Digite o Nome: "); //**
    fgets(aluno[idxAluno].nome, maxCaracPorNome, stdin);
    
    //obs: problema se ultrapassar maxtam
    
    printf("Digite o Sexo: "); //**?
    fgets (aluno[idxAluno].sexo, maxNomeSexTam, stdin);
        
    while (cadastroValido == FALSE){
        printf("Digite a Data de Nascimento: ");
        scanf("%d", &aluno[idxAluno].dataNasc);
        getchar();
        cadastroValido = validarNascimento(idxAluno);
        if (cadastroValido == FALSE)
            printf("Dados inválidos! Tente novamente.\n");
    }
    cadastroValido = FALSE;
    
    printf("Digite o CPF: ");
    scanf("%d", &aluno[idxAluno].cpf);
    getchar();
    
    printf("Cadastro realizado com sucesso!\n");
    
}

void atualizarCadastroAlunos(){
    int numMatricula;
    int icont, idxAtualizar = -1;
    printf("Digite o número de matrícula da pessoa que deseja atualizar o cadastro:\n");
    scanf("%d", &numMatricula);
    getchar();
    
    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        if (numMatricula == aluno[icont].matricula)
            idxAtualizar = icont;
    }
    if (idxAtualizar >= 0){
        printf("Digite os novos dados do cadastro:\n");
        cadastrarAluno(idxAtualizar);
    }
    else
        printf("Número de matrícula não encontrado!\n");
}

// quando for fazer a parte dos profs, lembrar dessa funcao q pode ser reutilizada,
// seja criando uma variavel qtdCadastrosTotais e colocando dentro dos colchetes aq 
// ou qualquer outra ideia q venha na sua cabecinha do futuro ai
int trocaValores(int ordem[], int cont){
    int ligacao;
    ligacao = ordem[cont];
    ordem[cont] = ordem[cont + 1];
    ordem[cont + 1] = ligacao;
    
    return TRUE;
}

void listarAlunos(){
    int icont;
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%s", aluno[icont].nome);
}

void listarNomesOrdem(){
    int icont, jcont, kcont, lcont;
    int trocou = TRUE;
    int ordem[qtdAlunosCadastrados];
    
    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        if (aluno[icont].nome[0] >= 'A' && aluno[icont].nome[0] <= 'Z')
            aluno[icont].nome[0] += 32;
        ordem[icont] = icont;
    }
    
    for (icont = 0, jcont = 0; icont < qtdAlunosCadastrados - 1 && trocou; icont++){
        trocou = FALSE;
        for (kcont = 0, lcont = 0; kcont < qtdAlunosCadastrados - 1 - icont; kcont++){
            while (aluno[ordem[kcont]].nome[jcont] == aluno[ordem[kcont + 1]].nome[lcont] && aluno[ordem[kcont]].nome[jcont]){
                jcont++;
                lcont++;
                if (aluno[ordem[kcont]].nome[jcont] == ' ' || aluno[ordem[kcont]].nome[jcont] == '\n')
                    jcont++;
                
                if (aluno[ordem[kcont + 1]].nome[lcont] == ' ' || aluno[ordem[kcont + 1]].nome[lcont] == '\n')
                    lcont++;
                
                if (aluno[ordem[kcont]].nome[jcont] >= 'A' && aluno[ordem[kcont]].nome[jcont] <= 'Z')
                    aluno[ordem[kcont]].nome[jcont] += 32;
                    
                if (aluno[ordem[kcont + 1]].nome[lcont] >= 'A' && aluno[ordem[kcont + 1]].nome[lcont] <= 'Z')
                    aluno[ordem[kcont + 1]].nome[lcont] += 32;
            }
            
            if ((aluno[ordem[kcont]].nome[jcont] > aluno[ordem[kcont + 1]].nome[lcont]) && (aluno[ordem[kcont]].nome[jcont] != '\0' && aluno[ordem[kcont + 1]].nome[lcont] != '\0'))
                trocou = trocaValores(ordem, kcont);
            
            jcont = 0;
            lcont = 0;
        }
    }
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%d- %s", icont + 1, aluno[ordem[icont]].nome);
}

void listarSexo(){
    int icont;
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%s%s\n", aluno[icont].nome, aluno[icont].sexo);
}

void listarNascimento(){
    int icont, jcont;
    int trocou = TRUE, ordem[qtdAlunosCadastrados];
    int dia[qtdAlunosCadastrados], mes[qtdAlunosCadastrados], ano[qtdAlunosCadastrados];
    
    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        dia[icont] = aluno[icont].dataNasc / 1000000; 
        mes[icont] = (aluno[icont].dataNasc % 1000000) / 10000;
        ano[icont] = aluno[icont].dataNasc % 10000;
        
        ordem[icont] = icont;
    }
    
    for (icont = 0; icont < qtdAlunosCadastrados - 1 && trocou; icont++){
        trocou = FALSE;
        for (jcont = 0; jcont < qtdAlunosCadastrados - 1 - icont; jcont++){
            if (ano[ordem[jcont]] > ano[ordem[jcont + 1]])
                trocou = trocaValores(ordem, jcont);
            
            else if (ano[ordem[jcont]] == ano[ordem[jcont + 1]]){
                if (mes[ordem[jcont]] > mes[ordem[jcont + 1]])
                    trocou = trocaValores(ordem, jcont);
                
                else if (mes[ordem[jcont]] == mes[ordem[jcont + 1]]){
                    if (dia[ordem[jcont]] > dia[ordem[jcont + 1]])
                        trocou = trocaValores(ordem, jcont);
                }
            }
        }
    }
    
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%s%d/%d/%d\n\n", aluno[ordem[icont]].nome, dia[ordem[icont]], mes[ordem[icont]], ano[ordem[icont]]);
}

int infoCadastroAlunos(int opcao){
    switch (opcao){
        case 0: {
            return TRUE;
        }
        case 1: {
            cadastrarAluno(qtdAlunosCadastrados);
            qtdAlunosCadastrados++;
            break;
        }
        case 2: {
            atualizarCadastroAlunos();
            break;
        }
        case 3: {
            // pode melhorar ao pedir para o usuario solicitar
            // um cadastro especifico para ser deletado
            qtdAlunosCadastrados--;
            printf("Cadastro Deletado!\n");
            break;
        }
    }
    
    return FALSE;
}

int informacaoAlunos(int opcao){
    int saida = FALSE;
    switch (opcao){
        case 0: {
            return TRUE;
        }
        case 1: {
            while (saida == FALSE){
                painelCadastro();
                scanf("%d", &opcao);
                getchar();
                saida = infoCadastroAlunos(opcao);
            }
            saida = FALSE;
            break;
        }
        case 2: {
            listarAlunos();
            break;
        }
        case 3: {
            listarNomesOrdem();
            break;
        }
        case 4: {
            listarSexo();
            break;
        }
        case 5: {
            listarNascimento();
            break;
        }
    }
    return FALSE;
}

void buscarCadastrado(char nomeBusca[]){
    int icont, jcont, kcont, tam;
    int achou;
    for (icont = 0; nomeBusca[icont] != '\n'; icont++);
    tam = icont - 1;
    
    if (tam < 3)
        printf("Letras insuficientes para busca!\n");
    else {
        printf("Com base na sua busca, esses são os resultados que mais se encaixam:\n");
        for (icont = 0; icont < qtdAlunosCadastrados; icont++){
            jcont = 0;
            kcont = 0;
            while (aluno[icont].nome[kcont] != '\n' && jcont <= tam){
                if (nomeBusca[jcont] != aluno[icont].nome[kcont]){
                    achou = FALSE;
                    kcont++;
                }
                else {
                    achou = TRUE;
                    jcont++;
                    kcont = 0;
                }
            }
            
            if (achou)
                printf("%s", aluno[icont].nome);
        }
    }
}

void listarAniversariantes(int mesAtual){
    int icont, mesPessoa;
    printf("Esses são os cadastrados que fazem aniversário no mes %d:\n", mesAtual);
    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        mesPessoa = (aluno[icont].dataNasc % 1000000) / 10000;
        if (mesPessoa == mesAtual)
            printf("- %s", aluno[icont].nome);
    }
    // outro for aq para os professores
}

int main(){
    int saida, opcao, mesAtual;
    char nomeBusca[maxCaracPorNome];
    saida = FALSE;
    
    while (saida == FALSE){
        painelOpcoes();
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao){
            case 0: {
                saida = TRUE;
                break;
            }
            case 1: {
                while (saida == FALSE){
                    painelInformacoes();
                    scanf("%d", &opcao);
                    getchar();
                    saida = informacaoAlunos(opcao);
                }
                saida = FALSE;
                break;
            }
            case 2: {
                printf("Voce esta na pagina professor\n");
                break;
            }
            case 3: {
                printf("Voce esta na pagina disciplina\n");
                break;
            }
            case 4: {
                printf("Digite o nome procurado:\n");
                fgets (nomeBusca, maxCaracPorNome, stdin);
                buscarCadastrado(nomeBusca);
                break;
            }
            case 5: {
                printf("Digite o mes atual:\n");
                scanf("%d", &mesAtual);
                listarAniversariantes(mesAtual);
                break;
            }
        }
    }
    
    return 0;
}