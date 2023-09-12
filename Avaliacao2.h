/*
 * EXERCICIO 1
 * */

#define MAX_SIZE 5

typedef struct Pessoa {

    char nome[100];
    int idade, cpf;

} User;

int top;
User pilha[MAX_SIZE];

void functionEx1(int code) {

    system("cls");

    if (code == 1) {

        top++;

        getchar();
        printf("Digite o nome do usuario:");
        scanf("%[0-9a-zA-Z,. ]", pilha[top].nome);

        printf("\nDigite o CPF do usuario:");
        scanf("%d", &pilha[top].cpf);

        printf("\nDigite a idade do usuario:");
        scanf("%d", &pilha[top].idade);

        printf("\nUsuario inserido.");

    } else if (code == 2) {

        if (top == -1) {
            printf("\nPilha vazia!");
            exit(EXIT_FAILURE);
        }

        int cpf = 0;

        printf("Digite o CPF que sera removido:");
        scanf("%d", &cpf);

        User newFila[MAX_SIZE];
        int count = 0;

        while (top != -1) {

            top--;

            if (cpf == pilha[top].cpf) {
                break;
            } else {
                newFila[count++] = pilha[top];
            }

        }

        while (count >= 0)
            pilha[top++] = newFila[count--];

    } else if (code > 0) {

        printf("Opcao invalida!");

    }

}

void callEx1() {

    top = -1;

    int code = 0;

    do {

        if (top != -1)
            printf("Topo atual: %d", top);

        printf("Escolha umas das operacoes:");
        printf("\n1 - Adicionar um usuario.");
        printf("\n2 - Remover um usuario.");
        printf("\n0 - Sair da aplicacao.");

        scanf("%d", &code);
        functionEx1(code);

    } while (code != 0);

}

/*
 * EXERCICIO 2
 * */

typedef struct BodyProcess {

    int id, flag;
    struct BodyProcess *prox;

} Process;

Process *queueProcess;

void addProcess(int id, int flag) {

    Process *newProcess = (Process *) malloc(sizeof(Process));

    if (newProcess == NULL) {
        printf("Memory Error!\n");
        exit(EXIT_FAILURE);
    }

    newProcess->id = id;
    newProcess->flag = flag;
    newProcess->prox = NULL;

    if (queueProcess == NULL) {
        queueProcess = newProcess;
    } else {

        Process *aux = queueProcess;

        if (flag != 1) {

            while (aux->prox != NULL)
                aux = aux->prox;

            aux->prox = newProcess;

        } else {

            newProcess->prox = aux;
            queueProcess = newProcess;

        }

    }

}

void removeProcessMaxWait() {

    if (queueProcess == NULL) {
        printf("\nFila vazia");
        exit(EXIT_FAILURE);
    }

    Process *aux = queueProcess;
    queueProcess = aux->prox;

    free(aux);
}

void callEx2() {

    int code = 0;
    queueProcess = NULL;

    do {

        printf("Escolha umas das operacoes:");
        printf("\n1 - Adicionar um processo.");
        printf("\n2 - Remover um processo.");
        printf("\n3 - Exibir processos.");
        printf("\n0 - Sair da aplicacao.");

        scanf("%d", &code);

        system("cls");

        if (code == 1) {

            int id, flag;

            printf("Digite o ID do processo: ");
            scanf("%d", &id);

            printf("Digite a flag do processo:");
            scanf("%d", &flag);

            addProcess(id, flag);

            printf("\nadd process");

        } else if (code == 2) {

            removeProcessMaxWait();
            printf("\nflush in process");

        } else if (code == 3) {

            if (queueProcess == NULL) {

                printf("\nFila vazia!");

            } else {

                printf("\nProcess list:");

                Process *aux = queueProcess;

                while (aux != NULL) {
                    printf("\nId: %d - flag=%d", aux->id, aux->flag);
                    aux = aux->prox;
                }

            }

        } else if (code > 0) {
            printf("\nOpcao invalida.");
        }

    } while (code != 0);

}