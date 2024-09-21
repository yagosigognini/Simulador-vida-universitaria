#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais para armazenar as escolhas do jogador
int aulasAssistidas = 0;
int festasComparecidas = 0;
int horasEstudadas = 0;

void terAula();
void irParaFesta();
void estudar();
void eventoDeSaude();
void fazerProva();

// Função principal
int main() {
    srand(time(NULL));

    printf("Bem-vindo a vida universitaria!\n");
    printf("Voce acabou de iniciar seu primeiro semestre na universidade.\n");

    char escolha;
    while (1) {
        printf("\nEscolha o que fazer:\n");
        printf("1. Ir para aula\n");
        printf("2. Ir para uma festa\n");
        printf("3. Estudar para o exame\n");
        printf("4. Cuidar da saude\n");
        printf("5. Sair da universidade\n");
        printf("Escolha: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                terAula();
                break;
            case '2':
                irParaFesta();
                break;
            case '3':
                estudar();
                break;
            case '4':
                eventoDeSaude();
                break;
            case '5':
                printf("\nVocê decidiu sair da universidade. Ate a proxima!\n");
                return 0;
            default:
                printf("\nOpção invalida! Tente novamente.\n");
                break;
        }

        // Após um certo número de ações, fazer a prova final
        if (aulasAssistidas + festasComparecidas + horasEstudadas >= 10) {
            fazerProva();
            return 0;
        }
    }

    return 0;
}

// Função para simular uma aula
void terAula() {
    aulasAssistidas++;
    int chance = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    if (chance <= 70) {
        printf("\nVoce teve uma aula entediante...\n");
    } else {
        printf("\nVoce teve uma aula interessante e aprendeu bastante!\n");
        horasEstudadas += 2; // Aumenta o número de horas estudadas
    }
}

// Função para simular uma festa
void irParaFesta() {
    festasComparecidas++;
    int chance = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    if (chance <= 30) {
        printf("\nA festa foi incrível e você se divertiu muito!\n");
    } else if (chance <= 60) {
        printf("\nA festa estava razoavel, mas você acabou se entediando...\n");
    } else {
        printf("\nA festa foi um desastre e você se arrependeu de ter ido...\n");
    }
}

// Função para simular estudar para um exame
void estudar() {
    horasEstudadas += 3; // Aumenta o número de horas estudadas
    printf("\nVoce passou a noite estudando para o exame e se sente preparado!\n");
}

// Função para simular um evento de saúde
void eventoDeSaude() {
    int chance = rand() % 100 + 1; // Gera um número aleatório entre 1 e 100
    if (chance <= 20) {
        printf("\nVoce ficou doente e teve que faltar às aulas por alguns dias...\n");
    } else {
        printf("\nSua saude esta boa e voce pode continuar suas atividades normalmente.\n");
    }
}

// Função para realizar a prova final
void fazerProva() {
    int nota = 0;

    // Calcula a nota com base nas escolhas do jogador
    nota += aulasAssistidas * 10;
    nota += horasEstudadas * 5;
    nota -= festasComparecidas * 5;

    // Exibe a nota do jogador
    printf("\nVoce fez a prova final e sua nota foi: %d\n", nota);

    // Determina a mensagem final com base na nota
    if (nota >= 60) {
        printf("Parabens! Voce passou na prova e est aprovado na disciplina!\n");
    } else {
        printf("Infelizmente, sua nota não foi suficiente para passar na prova. Você está de DP.\n");
    }
}
