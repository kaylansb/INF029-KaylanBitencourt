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