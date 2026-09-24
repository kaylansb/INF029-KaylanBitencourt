void painelOpcoes();
void painelInformacoesAlunosProfs();
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

void buscarCadastrado(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, char nomeBusca[]);
void listarAniversariantes(infoAlunosProfs aluno[], infoAlunosProfs professor[], int qtdAlunosCadastrados, int qtdProfsCadastrados, int mesAtual);



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