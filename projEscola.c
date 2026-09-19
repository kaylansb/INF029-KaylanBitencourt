#include <stdio.h>
#define maxCarac 100
#define maxNomes 5
#define maxCaracPorNome (maxCarac / maxNomes)
#define maxNomeSexTam 9+1+1 // o nome "masculino" + \n + \0
#define cpfTam 11
#define TRUE 1
#define FALSE 0
#define minLetrasBusca 3

typedef struct {
    int matricula;
    char nome[maxCarac];
    char sexo[maxNomeSexTam];
    int dataNasc;
    int cpf[cpfTam];
}
infoAlunosProfs;

void painelOpcoes();
void painelInformacoes();
void painelCadastro();


// int informacaoAlunos(int opcao);
// int infoCadastroAlunos(int opcao);
void cadastrarAluno(infoAlunosProfs aluno[], int idxAluno);
int cadastrarCPF(infoAlunosProfs aluno[], int idxAluno);
int validarCPF(infoAlunosProfs aluno[], int idxAluno, int penultmDigito, int ultmDigito);
int validarNascimento(infoAlunosProfs aluno[], int idxAluno);
void atualizarCadastroAlunos(infoAlunosProfs aluno[], int qtdAlunosCadastrados);
void listarAlunos(infoAlunosProfs aluno[], int qtdAlunosCadastrados);
void listarNomesOrdem(infoAlunosProfs aluno[], int qtdAlunosCadastrados);
void listarSexo(infoAlunosProfs aluno[], int qtdAlunosCadastrados);
void listarNascimento(infoAlunosProfs aluno[], int qtdAlunosCadastrados);


int trocaValores(int ordem[], int cont);


void buscarCadastrado(infoAlunosProfs aluno[], char nomeBusca[], int qtdAlunosCadastrados);
void listarAniversariantes(infoAlunosProfs aluno[], int mesAtual, int qtdAlunosCadastrados);



int main(){
    infoAlunosProfs aluno[maxNomes];
    // infoAlunosProfs professor[maxNomes];
    int qtdAlunosCadastrados = 0;
    
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
                
                    switch (opcao){
                        case 0: {
                            saida = TRUE;
                            break;
                        }
                        case 1: {
                            while (saida == FALSE){
                                painelCadastro();
                                scanf("%d", &opcao);
                                getchar();
                        
                                switch (opcao){
                                    case 0: {
                                        saida = TRUE;
                                        break;
                                    }
                                    case 1: {
                                        cadastrarAluno(aluno, qtdAlunosCadastrados);
                                        qtdAlunosCadastrados++;
                                        break;
                                    }
                                    case 2: {
                                        atualizarCadastroAlunos(aluno, qtdAlunosCadastrados);
                                        break;
                                    }
                                    case 3: {
                                        qtdAlunosCadastrados--;
                                        printf("Cadastro Deletado!\n");
                                        break;
                                    }
                                }
                        
                            } // do while
                            saida = FALSE;
                            break;
                        }
                        case 2: {
                            listarAlunos(aluno, qtdAlunosCadastrados);
                            break;
                        }
                        case 3: {
                            listarNomesOrdem(aluno, qtdAlunosCadastrados);
                            break;
                        }
                        case 4: {
                            listarSexo(aluno, qtdAlunosCadastrados);
                            break;
                        }
                        case 5: {
                            listarNascimento(aluno, qtdAlunosCadastrados);
                            break;
                        }
                    }
                
                } // do while
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
                buscarCadastrado(aluno, nomeBusca, qtdAlunosCadastrados);
                break;
            }
            case 5: {
                printf("Digite o mes atual:\n");
                scanf("%d", &mesAtual);
                listarAniversariantes(aluno, mesAtual, qtdAlunosCadastrados);
                break;
            }
        }
    }

    return 0;
}

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

// int informacaoAlunos(int opcao){
//     int saida = FALSE;
//     switch (opcao){
//         case 0: {
//             return TRUE;
//         }
//         case 1: {
//             while (saida == FALSE){
//                 painelCadastro();
//                 scanf("%d", &opcao);
//                 getchar();
//                 saida = infoCadastroAlunos(opcao);
//             }
//             saida = FALSE;
//             break;
//         }
//         case 2: {
//             listarAlunos();
//             break;
//         }
//         case 3: {
//             listarNomesOrdem();
//             break;
//         }
//         case 4: {
//             listarSexo();
//             break;
//         }
//         case 5: {
//             listarNascimento();
//             break;
//         }
//     }
//     return FALSE;
// }

// int infoCadastroAlunos(int opcao){
//     switch (opcao){
//         case 0: {
//             return TRUE;
//         }
//         case 1: {
//             cadastrarAluno(qtdAlunosCadastrados);
//             qtdAlunosCadastrados++;
//             break;
//         }
//         case 2: {
//             atualizarCadastroAlunos();
//             break;
//         }
//         case 3: {
//             // pode melhorar ao pedir para o usuario solicitar
//             // um cadastro especifico para ser deletado
//             qtdAlunosCadastrados--;
//             printf("Cadastro Deletado!\n");
//             break;
//         }
//     }
    
//     return FALSE;
// }

int validarNascimento(infoAlunosProfs aluno[], int idxAluno){
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

int validarCPF(infoAlunosProfs aluno[], int idxAluno, int penultmDigito, int ultmDigito){
    int icont, jcont;
    int digito1 = 0, digito2 = 0;
    
    for (icont = 0, jcont = cpfTam; icont < cpfTam - 2; icont++, jcont--){
        digito1 += (aluno[idxAluno].cpf[icont] * (jcont - 1));
        digito2 += (aluno[idxAluno].cpf[icont] * jcont);
    }
    
    digito1 %= cpfTam;
    digito1 = (cpfTam - digito1);
    if (digito1 == cpfTam - 1 || digito1 == cpfTam)
        digito1 = 0;
    
    digito2 += (digito1 * 2);
    digito2 %= cpfTam;
    digito2 = (cpfTam - digito2);
    if (digito2 == cpfTam - 1 || digito2 == cpfTam)
        digito2 = 0;
    
    if (penultmDigito == digito1 && ultmDigito == digito2)
        return TRUE;
    else
        return FALSE;
}

int cadastrarCPF(infoAlunosProfs aluno[], int idxAluno, int qtdAlunosCadastrados){
    char cpfTemp[cpfTam + 3 + 2]; // para aceitar separacoes padrao do cpf ('.' e '-'), \n e \0
    int penultmDigito, ultmDigito, validadeParcial = TRUE, cpfEhValido = FALSE;
    int icont, jcont;
    
    icont = 0;
    while (icont < qtdAlunosCadastrados){
        jcont = 0;
        while (aluno[idxAluno].cpf[jcont] == aluno[icont].cpf[jcont] && jcont < cpfTam && icont != idxAluno){
            jcont++;
        }
        if (jcont == cpfTam){
            validadeParcial = FALSE;
            break;
        }
        icont++;
    }
    
    if (validadeParcial == FALSE)
        return cpfEhValido;
    else {
    while (!cpfEhValido){
        printf("Digite seu CPF:\n");
        fgets (cpfTemp, cpfTam + 3 + 2, stdin);
        
        for (icont = 0, jcont = 0; icont < cpfTam && cpfTemp[icont] != '\n'; icont++){
            if (cpfTemp[icont] >= '0' && cpfTemp[icont] <= '9'){
                aluno[idxAluno].cpf[jcont] = cpfTemp[icont] - '0';
                jcont++;
            }
        }
        if (jcont != cpfTam)
            printf("Erro! CPF com quantidade de dígitos incorreta!\n");
        else {
            penultmDigito = aluno[idxAluno].cpf[cpfTam - 2];
            ultmDigito = aluno[idxAluno].cpf[cpfTam - 1];
            cpfEhValido = validarCPF(aluno, idxAluno, penultmDigito, ultmDigito);
            if (!cpfEhValido)
                printf("Erro! CPF Inválido!\n");
        }
    }
    
    return cpfEhValido;
    }
}

void cadastrarAluno(infoAlunosProfs aluno[], int idxAluno){
    int cadastroValido = FALSE;
    
//     printf("Digite o Número de Matrícula: ");
//     scanf("%d", &aluno[idxAluno].matricula);
//     getchar();
    
    printf("Digite o Nome: "); //**
    fgets(aluno[idxAluno].nome, maxCaracPorNome, stdin);
    
    //obs: problema se ultrapassar maxtam
    
    printf("Digite o Sexo: "); //**?
    fgets (aluno[idxAluno].sexo, maxNomeSexTam, stdin);
        
    while (cadastroValido == FALSE){
        printf("Digite a Data de Nascimento: ");
        scanf("%d", &aluno[idxAluno].dataNasc);
        getchar();
        cadastroValido = validarNascimento(aluno, idxAluno);
        if (cadastroValido == FALSE)
            printf("Dados inválidos! Tente novamente.\n");
    }
    cadastroValido = FALSE;
    
    while (cadastroValido == FALSE){
        cadastroValido = cadastrarCPF(aluno, idxAluno);
    }
    
    printf("Cadastro realizado com sucesso!\n");
    
}

void atualizarCadastroAlunos(infoAlunosProfs aluno[], int qtdAlunosCadastrados){
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
        cadastrarAluno(aluno, idxAtualizar);
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

void listarAlunos(infoAlunosProfs aluno[], int qtdAlunosCadastrados){
    int icont;
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%s", aluno[icont].nome);
}

void listarNomesOrdem(infoAlunosProfs aluno[], int qtdAlunosCadastrados){
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

void listarSexo(infoAlunosProfs aluno[], int qtdAlunosCadastrados){
    int icont;
    for (icont = 0; icont < qtdAlunosCadastrados; icont++)
        printf("%s%s\n", aluno[icont].nome, aluno[icont].sexo);
}

void listarNascimento(infoAlunosProfs aluno[], int qtdAlunosCadastrados){
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

void buscarCadastrado(infoAlunosProfs aluno[], char nomeBusca[], int qtdAlunosCadastrados){
// busca por letras no nome, ou seja, se algum nome tiver 
// todas as letras que foram digitadas na busca, esse nome é exibido.
    int icont, jcont, kcont, tam;
    int achou = FALSE;
    for (icont = 0; nomeBusca[icont] != '\n'; icont++)
        printf("%c-%d\n", nomeBusca[icont], icont);
    tam = icont;
    if (tam < minLetrasBusca)
        printf("Letras insuficientes para busca!\n");
    else {
        printf("Com base na sua busca, esses são os resultados que mais se encaixam:\n");
        for (icont = 0; icont < qtdAlunosCadastrados; icont++){
            jcont = 0;
            kcont = 0;
            while (aluno[icont].nome[kcont] != '\n' && jcont < tam){
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

void listarAniversariantes(infoAlunosProfs aluno[], int mesAtual, int qtdAlunosCadastrados){
    int icont, mesPessoa;
    printf("Esses são os cadastrados que fazem aniversário no mes %d:\n", mesAtual);
    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        mesPessoa = (aluno[icont].dataNasc % 1000000) / 10000;
        if (mesPessoa == mesAtual)
            printf("- %s", aluno[icont].nome);
    }
    // outro for aq para os professores
}