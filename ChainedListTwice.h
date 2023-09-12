typedef struct NodeChainedTwice {

    int number;
    struct NodeChainedTwice *before, *after;

} TwiceList;

TwiceList *twiceList;

void initTwiceList() {
    twiceList = NULL;
}

int emptyTwiceList() {
    return twiceList == NULL;
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
    newList->before = NULL;
    newList->after = twiceList;
    twiceList = newList;
}

void insertInRightTwiceList(TwiceList *newList) {

    if (emptyTwiceList()) {

        insertInLeftTwiceList(newList);

    } else {

        newList->after = NULL;

        TwiceList *next = twiceList;

        while (next->after != NULL)
            next = next->after;

        newList->before = next;
        next->after = newList;
    }

}

void viewTwiceList() {

    if (emptyTwiceList()) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista Atual\n");

    TwiceList *aux = twiceList;

    while (aux != NULL) {
        printf("[%d]\n", aux->number);
        aux = aux->after;
    }

}

TwiceList *addElement(int number) {

    TwiceList *element = newTwiceList();
    element->number = number;

    return element;
}

void callTwiceList() {

    initTwiceList();

    for (int i = 0; i < 5; i++)
        insertInLeftTwiceList(addElement(i));

    for (int i = 5; i < 10; i++)
        insertInRightTwiceList(addElement(i));

    viewTwiceList();

}