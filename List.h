typedef struct NodeList {

    int value;
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

void insertInLeft(int value) {

    List *newList = newElementList();

    List *aux = headList;
    newList->value = value;
    newList->node = aux;
    headList = newList;

}

void insertInRight(int value) {

    List *newList = newElementList();

    if (emptyList()) {

        free(newList);
        insertInLeft(value);

    } else {

        newList->value = value;
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

    // if (aux->node == NULL)
    //   printf("TESTER");

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
        printf("(%d)", aux->value);
        aux = aux->node;
    }

}

void callList() {

    insertInLeft(4);
    insertInLeft(6);
    insertInRight(9);

    viewList();

    removeInLeft();

    viewList();

    removeInRight();

    viewList();

    removeInLeft();

    viewList();

}