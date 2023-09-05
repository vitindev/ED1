typedef struct NodeList {

    char nome[100];
    int matricula;

    struct NodeList *node;

} List;

List *headList;

void initList() {
    headList = NULL;
}

int emptyList() {
    return headList == NULL;
}

List *newElementList() {

    List *newList = (List *) malloc(sizeof(List));

    if (newList == NULL) {
        printf("\nMemory Error!\n");
        exit(EXIT_FAILURE);
    }

    return newList;
}

void insertInLeft(List *newList) {

    List *aux = headList;
    newList->node = aux;
    headList = newList;

}

void insertInRight(List *newList) {

    if (emptyList()) {

        insertInLeft(newList);

    } else {

        newList->node = NULL;

        List *next = headList;

        while (next->node != NULL)
            next = next->node;

        next->node = newList;
    }

}

void removeInLeft() {

    if (emptyList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    List *aux = headList;

    headList = aux->node;

    free(aux);
    aux = NULL;
}

void removeInRight() {

    if (emptyList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    if (headList->node == NULL) {

        free(headList);
        headList = NULL;

    } else {

        List *aux = headList;

        while (aux->node->node != NULL)
            aux = aux->node;

        List *remove = aux->node;

        free(remove);
        remove = NULL;

        aux->node = NULL;
    }

}

void viewList() {

    if (emptyList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista Atual\n");

    List *aux = headList;

    while (aux != NULL) {
        printf("(%s) - [%d]\n", aux->nome, aux->matricula);
        aux = aux->node;
    }

}

List *getAluno() {

    List *newList = newElementList();

    system("cls");
    getchar();

    printf("\nDigite o nome do aluno: ");
    scanf("%[0-9a-zA-Z,. ]", newList->nome);

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &newList->matricula);

    return newList;
}

void executeFunction(int code) {

    if (code == 1) {

        insertInRight(getAluno());

    } else if (code == 2) {

        insertInLeft(getAluno());

    } else if (code == 3) {

        removeInRight();

    } else if (code == 4) {

        removeInLeft();

    } else if (code < 1 || code > 5) {
        return;
    }

    viewList();

}

void callList() {

    initList();

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
        executeFunction(code);

    } while (code > 0);

}