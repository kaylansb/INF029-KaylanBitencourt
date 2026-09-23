void painelInformacoesDisplinas();

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