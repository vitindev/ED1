typedef struct NodeChainedList {

    char nome[100];
    int matricula;

    struct NodeChainedList *node;

} ChainedList;

ChainedList *headChainedList;

void initChainedList() {
    headChainedList = NULL;
}

int emptyChainedList() {
    return headChainedList == NULL;
}

ChainedList *newChainedElementList() {

    ChainedList *newList = (ChainedList *) malloc(sizeof(ChainedList));

    if (newList == NULL) {
        printf("\nMemory Error!\n");
        exit(EXIT_FAILURE);
    }

    return newList;
}

void insertInLeftChained(ChainedList *newList) {

    ChainedList *aux = headChainedList;
    newList->node = aux;
    headChainedList = newList;

}

void insertInRightChained(ChainedList *newList) {

    if (emptyChainedList()) {

        insertInLeftChained(newList);

    } else {

        newList->node = NULL;

        ChainedList *next = headChainedList;

        while (next->node != NULL)
            next = next->node;

        next->node = newList;
    }

}

void removeInLeftChained() {

    if (emptyChainedList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    ChainedList *aux = headChainedList;
    headChainedList = aux->node;

    free(aux);
    aux = NULL;
}

void removeInRightChained() {

    if (emptyChainedList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    if (headChainedList->node == NULL) {

        free(headChainedList);
        headChainedList = NULL;

    } else {

        ChainedList *aux = headChainedList;

        while (aux->node->node != NULL)
            aux = aux->node;

        ChainedList *remove = aux->node;

        free(remove);
        remove = NULL;

        aux->node = NULL;
    }

}

void viewChainedList() {

    if (emptyChainedList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista Atual\n");

    ChainedList *aux = headChainedList;

    while (aux != NULL) {
        printf("(%s) - [%d]\n", aux->nome, aux->matricula);
        aux = aux->node;
    }

}

ChainedList *getChainedAluno() {

    ChainedList *newList = newChainedElementList();

    system("cls");
    getchar();

    printf("\nDigite o nome do aluno: ");
    scanf("%[0-9a-zA-Z,. ]", newList->nome);

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &newList->matricula);

    return newList;
}

void chainedFunction(int code) {

    if (code == 1) {

        insertInRightChained(getChainedAluno());

    } else if (code == 2) {

        insertInLeftChained(getChainedAluno());

    } else if (code == 3) {

        removeInRightChained();

    } else if (code == 4) {

        removeInLeftChained();

    } else if (code < 1 || code > 5) {
        return;
    }

    viewChainedList();

}

void callChainedList() {

    initChainedList();

    printf("Selecao de alunos: ");

    int code = 0;

    do {

        printf("\nDigite alguma das opcoes abaixo:\n");
        printf("\n1 - Inserir aluno no fim da lista.");
        printf("\n2 - Inserir aluno no comeco da lista.");
        printf("\n3 - Remover aluno do fim da lista.");
        printf("\n4 - Remover aluno do comeco da lista.");
        printf("\n5 - Exibir a lista de alunos.");
        printf("\n0 - Sair da aplicacao.");

        scanf("%d", &code);
        chainedFunction(code);

    } while (code > 0);

}