typedef struct NodeChainedTwice {

    char name[100];
    int cpf;

    struct NodeChainedTwice *before, *after;

} TwiceList;

TwiceList *twiceList;

void initTwiceList() {
    twiceList = NULL;
}

int emptyTwiceList() {
    return twiceList == NULL;
}

void MoveMenor() {

    if (emptyTwiceList()) {
        exit(EXIT_FAILURE);
    }

    int menor = INT_MAX;

    TwiceList *aux = twiceList;

    while (aux->after != NULL) {

        if (aux->cpf < menor)
            menor = aux->cpf;

        aux = aux->after;
    }

    aux = twiceList;
    TwiceList *otherAux = NULL;

    while (aux->after != NULL) {

        if (aux->cpf == menor) {

            while (aux->before != NULL) {

                otherAux = aux->before;
                aux = aux->before;
                aux->before = aux;
                aux->after = otherAux;

            }

        }

        aux = aux->after;
    }

}

TwiceList *newTwiceList() {

    TwiceList *newList = (TwiceList *) malloc(sizeof(TwiceList));

    if (newList == NULL) {
        printf("\nMemory Error!\n");
        exit(EXIT_FAILURE);
    }

    return newList;
}

void insertInLeftTwiceList(TwiceList *newList) {

    if (twiceList == NULL) {

        newList->before = NULL;
        newList->after = NULL;
        twiceList = newList;

    } else {

        twiceList->before = newList;
        newList->after = twiceList;
        twiceList = newList;

    }

}

void insertInRightTwiceList(TwiceList *newList) {

    if (emptyTwiceList()) {

        insertInLeftTwiceList(newList);

    } else {

        TwiceList *aux = twiceList;

        while (aux->after != NULL)
            aux = aux->after;

        aux->after = newList;
        newList->before = aux;
        newList->after = NULL;

    }

}

void insertInMidTwiceList(int fromCpf, TwiceList *newList) {

    if (emptyTwiceList()) {

        insertInLeftTwiceList(newList);

    } else {

        TwiceList *aux = twiceList;

        if (aux->after == NULL) {
            insertInRightTwiceList(newList);
            return;
        }

        while (aux->after != NULL) {

            if (aux->cpf == fromCpf) {
                newList->after = aux->after;
                newList->before = aux;
                aux->after = newList;
                return;
            }

            aux = aux->after;

        }

        insertInRightTwiceList(newList);

    }

}

void removeInLeftTwiceList() {

    if (emptyTwiceList()) {
        printf("\nLista vazia!");
        exit(EXIT_FAILURE);
    }

    TwiceList *aux = twiceList;
    twiceList = aux->after;

    free(aux);
    aux = NULL;

}

void removeInRightTwiceList() {

    if (emptyTwiceList()) {
        printf("\nLista vazia!");
        exit(EXIT_FAILURE);
    }

    TwiceList *aux = twiceList;

    if (aux->after == NULL) {

        free(aux);
        aux = NULL;

    } else {

        while (aux->after != NULL)
            aux = aux->after;

        aux->before->after = NULL;
        aux->before = NULL;

        free(aux);
        aux = NULL;

    }

}

void removeInMidTwiceList(int cpf) {

    if (emptyTwiceList()) {
        printf("\nLista vazia!");
        exit(EXIT_FAILURE);
    }

    TwiceList *aux = twiceList;

    if (aux->cpf == cpf) {

        removeInLeftTwiceList();

    } else {

        while (aux->after != NULL) {

            aux = aux->after;

            if (aux->cpf == cpf)
                break;

        }

        aux->before = aux->before->after = aux->after;

        free(aux);
        aux = NULL;

    }

}

TwiceList *findUserByName(char nome[100]) {

    if (emptyTwiceList()) {
        printf("\nLista Vazia!\n");
        exit(EXIT_FAILURE);
    }

    TwiceList *aux = twiceList;

    while (aux->after != NULL) {

        if (strcmp(aux->name, nome) == 0) {
            return aux;
        }

        aux = aux->after;

    }

    return aux;
}

void viewTwiceList() {

    if (emptyTwiceList()) {
        printf("\nLista Vazia!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista Atual\n");

    TwiceList *aux = twiceList;

    while (aux != NULL) {
        printf("\nNome: %s - CPF[%d]", aux->name, aux->cpf);
        aux = aux->after;
    }

}

void callTwiceList() {

    initTwiceList();

    int code = 0;

    do {

        printf("\nEscolha uma das funcoes:");
        printf("\n1 - Inserir usuario.");
        printf("\n2 - Remover usuario");
        printf("\n3 - Procurar usuario");
        printf("\n0 - Sair da aplicacao.");

        scanf("%d", &code);

        if (code == 1) {

            TwiceList *element = newTwiceList();

            getchar();
            printf("Digite o nome do usuario:");
            scanf("%[0-9a-zA-Z,. ]", element->name);
            printf("\nDigite o CPF do usuario: ");
            scanf("%d", &element->cpf);

            printf("Opcoes:");
            printf("\n1 - Adicionar no inicio.");
            printf("\n2 - Adicionar no meio.");
            printf("\n3 - Adicionar no fim.");

            int function = 0;
            scanf("%d", &function);

            if (function == 1) {
                insertInLeftTwiceList(element);
            } else if (function == 2) {

                viewTwiceList();

                printf("Escolha a partir de onde voce deseja inserir o usuario:");
                int cpf = 0;
                scanf("%d", &cpf);

                insertInMidTwiceList(cpf, element);

            } else if (function == 3) {
                insertInRightTwiceList(element);
            }

        } else if (code == 2) {

            printf("Opcoes:");
            printf("\n1 - Remover do inicio.");
            printf("\n2 - Remover do meio.");
            printf("\n3 - Remover do fim.");
            getchar();

            int function = 0;
            scanf("%d", &function);

            if (function == 1) {
                removeInLeftTwiceList();
            } else if (function == 2) {

                int cpf = 0;

                printf("Digite o CPF do usuario para remover:");
                scanf("%d", &cpf);

                removeInMidTwiceList(cpf);

            } else if (function == 3) {
                removeInRightTwiceList();
            }

        } else if (code == 3) {

            char name[100];
            getchar();
            printf("\nDigite o nome do usuario que deseja encontrar:");
            scanf("%[0-9a-zA-Z,. ]", name);

            TwiceList *user = findUserByName(name);
            printf("\nNome: %s", user->name);
            printf("\nCpf: %d", user->cpf);

        } else if (code > 0) {


            MoveMenor();
            viewTwiceList();

            printf("\nOpcao invalida");
        }

    } while (code != 0);

}