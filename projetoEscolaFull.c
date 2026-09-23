#include <stdio.h>
#define maxCarac 100
#define maxNomes 5
#define maxCaracPorNome (maxCarac / maxNomes)
#define maxNomeSexTam 9+1+1 // o nome "masculino" + \n + \0
#define cpfTam 11
#define maxAlunosPorDisciplina 5
#define TRUE 1
#define FALSE 0
#define minLetrasBusca 3

typedef struct {
    char nome[maxCaracPorNome];
    char sexo[maxNomeSexTam];
    int matricula;
    int dataNasc;
    int cpf[cpfTam];
}
infoAlunosProfs;

typedef struct {
    char nome[maxCaracPorNome];
    float semestre;
    int codigo;
    int professor;
    int aluno[maxAlunosPorDisciplina];
    int totalAlunos;
}
infoDisciplinas;


void painelOpcoes();
void painelInformacoesAlunosProfs();
void painelInformacoesDisplinas();
void painelCadastro();

void cadastrarPessoa(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastrados);
void cadastrarCPF(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastrados);
int validarMatricula(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastradas);
int validarCPF(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastrados, int penultmDigito, int ultmDigito);
int validarNascimento(infoAlunosProfs pessoa[], int idxPessoa);
void atualizarCadastroPessoa(infoAlunosProfs pessoa[], int qtdPessoasCadastrados);
void listarPessoas(infoAlunosProfs pessoa[], int qtdPessoasCadastrados);
void listarNomesOrdem(infoAlunosProfs pessoa[], int qtdPessoasCadastrados);
void listarSexo(infoAlunosProfs pessoa[], int qtdPessoasCadastrados);
void listarNascimento(infoAlunosProfs pessoa[], int qtdPessoasCadastrados);

int trocaValores(int ordem[], int cont);


void cadastrarDisciplina(infoDisciplinas disciplina[], int idxDisciplina, infoAlunosProfs professor[], int qtdProfsCadastrados, int qtdDisciplinasCadastradas);
int validarCodigoDisciplina(infoDisciplinas disciplina[], int idxDisciplina, int qtdDisciplinasCadastradas);
void atualizarCadastroDisciplina(infoDisciplinas disciplina[], int qtdDisplinasCadastradas, infoAlunosProfs professor[], int qtdProfsCadastrados);
int deletarCadastro(int qtdCadastros);
void inserirAlunoDisciplina(infoAlunosProfs aluno[], int qtdAlunosCadastrados, infoDisciplinas disciplina[], int qtdDisciplinasCadastradas);
void excluirAlunoDisciplina(infoDisciplinas disciplina[], int qtdDisciplinasCadastradas);
void listarDisciplinas(infoDisciplinas disciplina[], int qtdDisciplinasCadastradas, infoAlunosProfs professor[]);
void listarUmaDisciplina(infoDisciplinas disciplina[], infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdDisciplinasCadastradas);
void alunosMenosDeTresDisciplinas(infoDisciplinas disciplina[], infoAlunosProfs aluno[], int qtdDisciplinasCadastradas, int qtdAlunosCadastrados);
void disciplinasComMais40vagas(infoDisciplinas disciplina[], infoAlunosProfs professor[], int qtdDisciplinasCadastradas);


void buscarCadastrado(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, char nomeBusca[]);
void listarAniversariantes(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, int mesAtual);



int main(){
    infoAlunosProfs aluno[maxNomes];
    infoAlunosProfs professor[maxNomes];
    int qtdAlunosCadastrados = 0;
    int qtdProfsCadastrados = 0;

    infoDisciplinas disciplina[maxNomes];
    int qtdDisciplinasCadastradas = 0;

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
                    painelInformacoesAlunosProfs();
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
                                        cadastrarPessoa(aluno, qtdAlunosCadastrados, qtdAlunosCadastrados);
                                        qtdAlunosCadastrados++;
                                        break;
                                    }
                                    case 2: {
                                        if (qtdAlunosCadastrados == 0)
                                            printf("Erro! Cadastros Insuficientes!");
                                        else {
                                            atualizarCadastroPessoa(aluno, qtdAlunosCadastrados);
                                        }
                                        
                                        break;
                                    }
                                    case 3: {
                                        if (qtdAlunosCadastrados == 0)
                                            printf("Erro! Cadastros Insuficientes!");
                                        else {
                                            qtdAlunosCadastrados = deletarCadastro(qtdAlunosCadastrados);
                                            printf("Cadastro Deletado!\n");
                                        }
                                        break;
                                    }
                                }

                            }
                            saida = FALSE;
                            break;
                        }
                        case 2: {
                            listarPessoas(aluno, qtdAlunosCadastrados);
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

                }
                saida = FALSE;
                break;
            }
            case 2: {
                while (saida == FALSE){
                    painelInformacoesAlunosProfs();
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
                                        cadastrarPessoa(professor, qtdProfsCadastrados, qtdProfsCadastrados);
                                        qtdProfsCadastrados++;
                                        break;
                                    }
                                    case 2: {
                                        atualizarCadastroPessoa(professor, qtdProfsCadastrados);
                                        break;
                                    }
                                    case 3: {
                                        if (qtdProfsCadastrados == 0)
                                            printf("Erro! Cadastros Insuficientes!");
                                        else {
                                            qtdProfsCadastrados = deletarCadastro(qtdProfsCadastrados);
                                            printf("Cadastro Deletado!\n");
                                        }
                                        break;
                                    }
                                } 

                            }
                            saida = FALSE;
                            break;
                        }
                        case 2: {
                            listarPessoas(professor, qtdProfsCadastrados);
                            break;
                        }
                        case 3: {
                            listarNomesOrdem(professor, qtdProfsCadastrados);
                            break;
                        }
                        case 4: {
                            listarSexo(professor, qtdProfsCadastrados);
                            break;
                        }
                        case 5: {
                            listarNascimento(professor, qtdProfsCadastrados);
                            break;
                        }
                    }

                }
                saida = FALSE;
                break;
            }
            case 3: {
                while (saida == FALSE){
                    painelInformacoesDisplinas();
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
                                        if (qtdProfsCadastrados > 0){
                                            cadastrarDisciplina(disciplina, qtdDisciplinasCadastradas, professor, qtdProfsCadastrados, qtdDisciplinasCadastradas);
                                            qtdDisciplinasCadastradas++;
                                        }
                                        else
                                            printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                                        break;
                                    }
                                    case 2: {
                                        if (qtdDisciplinasCadastradas > 0)
                                            atualizarCadastroDisciplina(disciplina, qtdDisciplinasCadastradas, professor, qtdProfsCadastrados);
                                        else
                                            printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                                        break;
                                    }
                                    case 3: {
                                        if (qtdDisciplinasCadastradas == 0)
                                            printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                                        else {
                                            qtdDisciplinasCadastradas = deletarCadastro(qtdDisciplinasCadastradas);
                                            printf("Cadastro Deletado Com Sucesso!\n");
                                        }    
                                        break;
                                    }
                                }
                            }
                            saida = FALSE;
                            break;
                        }
                        case 2: {
                            if (qtdAlunosCadastrados > 0 && qtdDisciplinasCadastradas > 0)
                                inserirAlunoDisciplina(aluno, qtdAlunosCadastrados, disciplina, qtdDisciplinasCadastradas);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                        case 3: {
                            if (qtdAlunosCadastrados > 0 && qtdDisciplinasCadastradas > 0)
                                excluirAlunoDisciplina(disciplina, qtdDisciplinasCadastradas);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                        case 4: {
                            if (qtdDisciplinasCadastradas > 0)
                                listarDisciplinas(disciplina, qtdDisciplinasCadastradas, professor);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                        case 5: {
                            if (qtdAlunosCadastrados > 0 && qtdDisciplinasCadastradas > 0)
                                listarUmaDisciplina(disciplina, aluno, professor, qtdDisciplinasCadastradas);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                        case 6: {
                            if (qtdAlunosCadastrados > 0 && qtdDisciplinasCadastradas > 0)
                                alunosMenosDeTresDisciplinas(disciplina, aluno, qtdDisciplinasCadastradas, qtdAlunosCadastrados);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                        case 7: {
                            if (qtdAlunosCadastrados > 0 && qtdDisciplinasCadastradas > 0)
                                disciplinasComMais40vagas(disciplina, professor, qtdDisciplinasCadastradas);
                            else
                                printf("Erro! Cadastros Insuficientes Para Realizar Esta Função!\n");
                            break;
                        }
                    }
                }
                saida = FALSE;
                break;
            }
            case 4: {
                if (qtdAlunosCadastrados == 0 && qtdProfsCadastrados == 0)
                    printf("Erro! Cadastros Insuficientes!\n");
                else {
                    printf("Digite o nome procurado:\n");
                    fgets (nomeBusca, maxCaracPorNome, stdin);
                    buscarCadastrado(aluno, professor, qtdAlunosCadastrados, qtdProfsCadastrados, nomeBusca);
                }
                break;
            }
            case 5: {
                if (qtdAlunosCadastrados == 0 && qtdProfsCadastrados == 0)
                    printf("Erro! Cadastros Insuficientes!\n");
                else {
                    printf("Digite o mes atual:\n");
                    scanf("%d", &mesAtual);
                    listarAniversariantes(aluno, professor, qtdAlunosCadastrados, qtdProfsCadastrados, mesAtual);
                }
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

void painelInformacoesAlunosProfs(){
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

void painelInformacoesDisplinas(){
    printf("Escolha uma das opcoes para realizar:\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastros de Disciplinas\n");
    printf("2 - Inserir Alunos\n");
    printf("3 - Excluir Alunos\n");
    printf("4 - Listar As Disciplinas\n");
    printf("5 - Listar Uma Disciplinas\n");
    printf("6 - Listar Alunos Em Menos de 3 Disciplinas\n");
    printf("7 - Listar Disciplinas Com 40+ Vagas\n");
}

int validarNascimento(infoAlunosProfs pessoa[], int idxPessoa){
    int dataValida;
    int dia, mes, ano;

    dia = pessoa[idxPessoa].dataNasc / 1000000; 
    mes = (pessoa[idxPessoa].dataNasc % 1000000) / 10000;
    ano = pessoa[idxPessoa].dataNasc % 10000;

    if (ano > 2026 || ano < 1900) // poderia botar tudo em uma linha só
        dataValida = FALSE;       // mas acho q assim fica mais organizado/legível.
    else if (mes > 12 || mes < 1)
        dataValida = FALSE;
    else if (dia > 31 || dia < 1)
        dataValida = FALSE;
    else
        dataValida = TRUE;

    return dataValida;
}

int validarCPF(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastradas, int penultmDigito, int ultmDigito){
    int icont, jcont;
    int digito1 = 0, digito2 = 0;
    
    icont = 0;
    while (icont < qtdPessoasCadastradas){
        jcont = 0;
        while (pessoa[idxPessoa].cpf[jcont] == pessoa[icont].cpf[jcont] && jcont < cpfTam && icont != idxPessoa){
            jcont++;
        }
        if (jcont == cpfTam){
            return FALSE;
        }
        icont++;
    }

    for (icont = 0, jcont = cpfTam; icont < cpfTam - 2; icont++, jcont--){
        digito1 += (pessoa[idxPessoa].cpf[icont] * (jcont - 1));
        digito2 += (pessoa[idxPessoa].cpf[icont] * jcont);
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

void cadastrarCPF(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastradas){
    char cpfTemp[cpfTam + 3 + 2]; // para aceitar separacoes padrao do cpf ('.' e '-'), \n e \0
    int penultmDigito, ultmDigito, cpfEhValido = FALSE;
    int icont, jcont;

    while (!cpfEhValido){
        printf("Digite seu CPF: ");
        fgets (cpfTemp, cpfTam + 3 + 2, stdin);

        for (icont = 0, jcont = 0; jcont < cpfTam && cpfTemp[icont] != '\n'; icont++){
            if (cpfTemp[icont] >= '0' && cpfTemp[icont] <= '9'){
                pessoa[idxPessoa].cpf[jcont] = cpfTemp[icont] - '0';
                jcont++;
            }
        }

        if (jcont != cpfTam)
            printf("Erro! CPF com quantidade de dígitos incorreta!\n");
        else {
            penultmDigito = pessoa[idxPessoa].cpf[cpfTam - 2];
            ultmDigito = pessoa[idxPessoa].cpf[cpfTam - 1];
            cpfEhValido = validarCPF(pessoa, idxPessoa, qtdPessoasCadastradas, penultmDigito, ultmDigito);
            if (!cpfEhValido)
                printf("Erro! CPF Inválido!\n");
        }
    }
}

int validarMatricula(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastradas){
    int icont;
    int matriculaValida = TRUE;

    for (icont = 0; icont < qtdPessoasCadastradas; icont++){
        if (pessoa[idxPessoa].matricula == pessoa[icont].matricula && icont != idxPessoa){
            matriculaValida = FALSE;
            break;
        }
    }

    return matriculaValida;
}

void cadastrarPessoa(infoAlunosProfs pessoa[], int idxPessoa, int qtdPessoasCadastradas){
    int cadastroValido = FALSE;

    while (cadastroValido == FALSE){
        printf("Digite o Número de Matrícula: ");
        scanf("%d", &pessoa[idxPessoa].matricula);
        getchar();
        cadastroValido = validarMatricula(pessoa, idxPessoa, qtdPessoasCadastradas);
        if (!cadastroValido)
            printf("Essa matrícula já existe!\n");
    }
    cadastroValido = FALSE;

    printf("Digite o Nome: "); 
    fgets(pessoa[idxPessoa].nome, maxCaracPorNome, stdin);

    //obs: problema se ultrapassar maxtam

    printf("Digite o Sexo: ");
    fgets (pessoa[idxPessoa].sexo, maxNomeSexTam, stdin);

    while (cadastroValido == FALSE){
        printf("Digite a Data de Nascimento: ");
        scanf("%d", &pessoa[idxPessoa].dataNasc);
        getchar();
        cadastroValido = validarNascimento(pessoa, idxPessoa);
        if (cadastroValido == FALSE)
            printf("Dados inválidos! Tente novamente.\n");
    }
    cadastroValido = FALSE;

    cadastrarCPF(pessoa, idxPessoa, qtdPessoasCadastradas);

    printf("Cadastro realizado com sucesso!\n");

}

void atualizarCadastroPessoa(infoAlunosProfs pessoa[], int qtdPessoasCadastradas){
    int numMatricula;
    int icont, idxAtualizar = -1;
    printf("Digite o número de matrícula da pessoa que deseja atualizar o cadastro:\n");
    scanf("%d", &numMatricula);
    getchar();

    for (icont = 0; icont < qtdPessoasCadastradas; icont++){
        if (numMatricula == pessoa[icont].matricula)
            idxAtualizar = icont;
    }
    if (idxAtualizar >= 0){
        printf("Digite os novos dados do cadastro:\n");
        cadastrarPessoa(pessoa, idxAtualizar, qtdPessoasCadastradas);
    }
    else
        printf("Número de matrícula não encontrado!\n");
}

int deletarCadastro(int qtdCadastros){
    return qtdCadastros - 1;
}

int trocaValores(int ordem[], int cont){
    int ligacao;
    ligacao = ordem[cont];
    ordem[cont] = ordem[cont + 1];
    ordem[cont + 1] = ligacao;

    return TRUE;
}

void listarPessoas(infoAlunosProfs pessoa[], int qtdPessoasCadastradas){
    int icont;
    for (icont = 0; icont < qtdPessoasCadastradas; icont++)
        printf("%s", pessoa[icont].nome);
}

void listarNomesOrdem(infoAlunosProfs pessoa[], int qtdPessoasCadastradas){
    int icont, jcont, kcont, lcont;
    int trocou = TRUE;
    int ordem[qtdPessoasCadastradas];

    for (icont = 0; icont < qtdPessoasCadastradas; icont++){
        if (pessoa[icont].nome[0] >= 'A' && pessoa[icont].nome[0] <= 'Z')
            pessoa[icont].nome[0] += 32;
        ordem[icont] = icont;
    }

    for (icont = 0, jcont = 0; icont < qtdPessoasCadastradas - 1 && trocou; icont++){
        trocou = FALSE;
        for (kcont = 0, lcont = 0; kcont < qtdPessoasCadastradas - 1 - icont; kcont++){
            while (pessoa[ordem[kcont]].nome[jcont] == pessoa[ordem[kcont + 1]].nome[lcont] && pessoa[ordem[kcont]].nome[jcont]){
                jcont++;
                lcont++;
                if (pessoa[ordem[kcont]].nome[jcont] == ' ' || pessoa[ordem[kcont]].nome[jcont] == '\n')
                    jcont++;

                if (pessoa[ordem[kcont + 1]].nome[lcont] == ' ' || pessoa[ordem[kcont + 1]].nome[lcont] == '\n')
                    lcont++;

                if (pessoa[ordem[kcont]].nome[jcont] >= 'A' && pessoa[ordem[kcont]].nome[jcont] <= 'Z')
                    pessoa[ordem[kcont]].nome[jcont] += 32;

                if (pessoa[ordem[kcont + 1]].nome[lcont] >= 'A' && pessoa[ordem[kcont + 1]].nome[lcont] <= 'Z')
                    pessoa[ordem[kcont + 1]].nome[lcont] += 32;
            }

            if ((pessoa[ordem[kcont]].nome[jcont] > pessoa[ordem[kcont + 1]].nome[lcont]) && (pessoa[ordem[kcont]].nome[jcont] != '\0' && pessoa[ordem[kcont + 1]].nome[lcont] != '\0'))
                trocou = trocaValores(ordem, kcont);

            jcont = 0;
            lcont = 0;
        }
    }
    for (icont = 0; icont < qtdPessoasCadastradas; icont++)
        printf("%d- %s", icont + 1, pessoa[ordem[icont]].nome);
}

void listarSexo(infoAlunosProfs pessoa[], int qtdPessoasCadastradas){
    int icont;
    for (icont = 0; icont < qtdPessoasCadastradas; icont++)
        printf("%s%s\n", pessoa[icont].nome, pessoa[icont].sexo);
}

void listarNascimento(infoAlunosProfs pessoa[], int qtdPessoasCadastradas){
    int icont, jcont;
    int trocou = TRUE, ordem[qtdPessoasCadastradas];
    int dia[qtdPessoasCadastradas], mes[qtdPessoasCadastradas], ano[qtdPessoasCadastradas];

    for (icont = 0; icont < qtdPessoasCadastradas; icont++){
        dia[icont] = pessoa[icont].dataNasc / 1000000; 
        mes[icont] = (pessoa[icont].dataNasc % 1000000) / 10000;
        ano[icont] = pessoa[icont].dataNasc % 10000;

        ordem[icont] = icont;
    }

    for (icont = 0; icont < qtdPessoasCadastradas - 1 && trocou; icont++){
        trocou = FALSE;
        for (jcont = 0; jcont < qtdPessoasCadastradas - 1 - icont; jcont++){
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

    for (icont = 0; icont < qtdPessoasCadastradas; icont++)
        printf("%s%d/%d/%d\n\n", pessoa[ordem[icont]].nome, dia[ordem[icont]], mes[ordem[icont]], ano[ordem[icont]]);
}

int validarCodigoDisciplina(infoDisciplinas disciplina[], int idxDisciplina, int qtdDisciplinasCadastradas){
    int icont;
    int codigoValido = TRUE;

    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        if (disciplina[idxDisciplina].codigo == disciplina[icont].codigo && icont != idxDisciplina){
            codigoValido = FALSE;
            break;
        }
    }

    return codigoValido;
}

void cadastrarDisciplina(infoDisciplinas disciplina[], int idxDisciplina, infoAlunosProfs professor[], int qtdProfsCadastrados, int qtdDisciplinasCadastradas){
    int icont, numMatricula, cadastroValido = FALSE;
    disciplina[idxDisciplina].totalAlunos = 0;

    printf("Digite o nome da disciplina: ");
    fgets (disciplina[idxDisciplina].nome, maxCaracPorNome, stdin);

    while (cadastroValido == FALSE){
        printf("Digite o código da disciplina: ");
        scanf("%d", &disciplina[idxDisciplina].codigo);
        getchar();

        cadastroValido = validarCodigoDisciplina(disciplina, idxDisciplina, qtdDisciplinasCadastradas);
        if (cadastroValido == FALSE)
            printf("Erro! Código Já Existente!\n");
    }
    cadastroValido = FALSE;

    printf("Digite o semestre da disciplina: ");
    scanf("%f", &disciplina[idxDisciplina].semestre);
    getchar();

    while (cadastroValido == FALSE){
        printf("Digite o número de mmatrícula do professor para esta disciplina: ");
        scanf("%d", &numMatricula);
        getchar();

        for (icont = 0; icont < qtdProfsCadastrados; icont++){
            if (numMatricula == professor[icont].matricula){
                disciplina[idxDisciplina].professor = icont;
                cadastroValido = TRUE;
                break;
            }
        }
        if (cadastroValido == FALSE)
            printf("Erro! Professor Não Encontrado, Tente Novamente!\n");
    }

    printf("Cadastro Realizado Com Sucesso!\n");
}

void atualizarCadastroDisciplina(infoDisciplinas disciplina[], int qtdDisciplinasCadastradas, infoAlunosProfs professor[], int qtdProfsCadastrados){
    int icont, disciplinaAntiga;
    int idxAtualizar = -1;

    printf("Digite o Código da Disciplina Que Desesjas Atualizar: ");
    scanf("%d", &disciplinaAntiga);
    getchar();

    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        if (disciplinaAntiga == disciplina[icont].codigo)
            idxAtualizar = icont;
    }

    if (idxAtualizar >= 0){
        printf("Digite As Novas Informações da Disciplina:\n");
        cadastrarDisciplina(disciplina, idxAtualizar, professor, qtdProfsCadastrados, qtdDisciplinasCadastradas);
    }
    else
        printf("Código da Disciplina Não Encontrado!\n");

}

void inserirAlunoDisciplina(infoAlunosProfs aluno[], int qtdAlunosCadastrados, infoDisciplinas disciplina[], int qtdDisciplinasCadastradas){
    int icont, jcont;
    int numMatricula, codigoDisciplina;

    printf("Digite o número de matrícula do aluno: ");
    scanf("%d", &numMatricula);
    getchar();

    printf("Digite o código da disciplina que o aluno participará: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        if (numMatricula == aluno[icont].matricula)
            break;
    }

    if (icont == qtdAlunosCadastrados)
        printf("Número de Matrícula Não Encontrado!\n");
    else {
        for (jcont = 0; jcont < qtdDisciplinasCadastradas; jcont++){
            if (codigoDisciplina == disciplina[jcont].codigo){
                disciplina[jcont].aluno[disciplina[jcont].totalAlunos] = icont;
                disciplina[jcont].totalAlunos++;
                printf("Sucesso! O Aluno Já Está na Disciplina!\n");
                break;
            }
        }

        if (jcont == qtdDisciplinasCadastradas)
            printf("Código da Disciplina Não Encontrado!\n");
    }
}

void excluirAlunoDisciplina(infoDisciplinas disciplina[], int qtdDisciplinasCadastradas){
    int icont;
    int codigoDisciplina;

    printf("Digite o código da disciplina que um aluno será excluído: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        if (codigoDisciplina == disciplina[icont].codigo && disciplina[icont].totalAlunos > 0){
            disciplina[icont].totalAlunos--;
            printf("Aluno Deletado da Disciplina Com Sucesso!\n");
            break;
        }
    }

    if (icont == qtdDisciplinasCadastradas)
        printf("Código Não Encontrado!\n");
}

void listarDisciplinas(infoDisciplinas disciplina[], int qtdDisciplinasCadastradas, infoAlunosProfs professor[]){
    int icont;
    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        printf("Disciplina: %s", disciplina[icont].nome);
        printf("Código: %d\n", disciplina[icont].codigo);
        printf("Semestre: %.1f\n", disciplina[icont].semestre);
        printf("Professor: %s\n", professor[disciplina[icont].professor].nome);
    }
}

void listarUmaDisciplina(infoDisciplinas disciplina[], infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdDisciplinasCadastradas){
    int icont, codigoDisciplina, idxDisciplina = -1;

    printf("Digite o Código da Disciplina: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        if (disciplina[icont].codigo == codigoDisciplina){
            idxDisciplina = icont;
            break;
        }
    }

    if (idxDisciplina >= 0){
        printf("Disciplina: %s", disciplina[idxDisciplina].nome);
        printf("Código: %d\n", disciplina[idxDisciplina].codigo);
        printf("Semestre: %.1f\n", disciplina[idxDisciplina].semestre);
        printf("Professor: %s", professor[disciplina[idxDisciplina].professor].nome);

        printf("Alunos: %d\n", disciplina[idxDisciplina].totalAlunos);
        for (icont = 0; icont < disciplina[idxDisciplina].totalAlunos; icont++)
            printf("%s", aluno[disciplina[idxDisciplina].aluno[icont]].nome);
    }
    else
        printf("Código da Disciplina Não Encontrado!\n");
}

void alunosMenosDeTresDisciplinas(infoDisciplinas disciplina[], infoAlunosProfs aluno[], int qtdDisciplinasCadastradas, int qtdAlunosCadastrados){
    int icont, jcont;
    int contagem[maxNomes] = {0};

    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        for (jcont = 0; jcont < disciplina[icont].totalAlunos; jcont++){
            contagem[disciplina[icont].aluno[jcont]]++;
        }
    }

    for (icont = 0; icont < qtdAlunosCadastrados; icont++){
        if (contagem[icont] < 3)
            printf("%s", aluno[icont].nome);
    }
}

void disciplinasComMais40vagas(infoDisciplinas disciplina[], infoAlunosProfs professor[], int qtdDisciplinasCadastradas){
    int icont;
    for (icont = 0; icont < qtdDisciplinasCadastradas; icont++){
        if (disciplina[icont].totalAlunos > 2){
            printf("Disciplina: %s", disciplina[icont].nome);
            printf("Professor: %s\n", professor[disciplina[icont].professor].nome);
        }
    }
}

void buscarCadastrado(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, char nomeBusca[]){
// busca por letras no nome, ou seja, se algum nome tiver 
// todas as letras que foram digitadas na busca, esse nome é exibido.

    int icont, jcont, kcont, tam;
    int achou = FALSE;
    for (icont = 0; nomeBusca[icont] != '\n'; icont++);
    tam = icont;
    if (tam < minLetrasBusca)
        printf("Letras insuficientes para busca!\n");
    else {
        printf("Com base na sua busca, esses são os resultados que mais se encaixam:\n");
        for (icont = 0; icont < qtdProfsCadastrados || icont < qtdAlunosCadastrados; icont++){
            jcont = 0;
            kcont = 0;
            while (aluno[icont].nome[kcont] != '\n' && jcont < tam && icont < qtdAlunosCadastrados){
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

            achou = FALSE;
            jcont = 0;
            kcont = 0;
            while (professor[icont].nome[kcont] != '\n' && jcont < tam && icont < qtdProfsCadastrados){
                if (nomeBusca[jcont] != professor[icont].nome[kcont]){
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
                printf("%s", professor[icont].nome);
        }
    }
}

void listarAniversariantes(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, int mesAtual){
    int icont, mesAluno, mesProf;
    printf("Esses são os cadastrados que fazem aniversário no mes %d:\n", mesAtual);
    for (icont = 0; icont < qtdAlunosCadastrados || icont < qtdProfsCadastrados; icont++){
        mesAluno = (aluno[icont].dataNasc % 1000000) / 10000;
        mesProf = (professor[icont].dataNasc % 1000000) / 10000;
        if (mesAluno == mesAtual && icont < qtdAlunosCadastrados)
            printf("- %s", aluno[icont].nome);
        if (mesProf == mesAtual && icont < qtdProfsCadastrados)
            printf("- %s", professor[icont].nome);
    }
}
