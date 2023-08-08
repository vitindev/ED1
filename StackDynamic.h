typedef struct Node {

    int value;
    struct Node *node;

} StackDynamic;

StackDynamic *topStackDynamic;

void initStackDynamic() {
    topStackDynamic = NULL;
}

int emptyStackDynamic() {
    return topStackDynamic == NULL;
}

StackDynamic pushStackDynamic(int value) {

    StackDynamic *newStack = (StackDynamic *) malloc(sizeof(StackDynamic));

    if (newStack == NULL) {
        printf("Memory Error!\n");
        exit(EXIT_FAILURE);
    }

    newStack->value = value;
    newStack->node = topStackDynamic;
    topStackDynamic = newStack;

    return *newStack;
}

void popStackDynamic() {

    if (emptyStackDynamic()) {
        printf("Memory Error!\n");
        exit(EXIT_FAILURE);
    }

    StackDynamic *aux = topStackDynamic;
    topStackDynamic = aux->node;

    free(aux);
}

void callStackDynamic() {

    initStackDynamic();

    int size = 5, value = 0;

    for (int i = 0; i < size; i++) {

        printf("Insira o %d valor na pilha: ", i + 1);
        scanf("%d", &value);

        pushStackDynamic(value);

    }

    popStackDynamic();
    popStackDynamic();

    printf("%d", topStackDynamic->value);
}