typedef struct ThreeBinary {

    int value;
    struct ThreeBinary *nohLeft, *nohRight;

} Three;

Three *insertThree(Three *node, int value) {

    Three *newThree = (Three *) malloc(sizeof(Three));

    if (newThree == NULL) {
        printf("\nMemory error!");
        exit(EXIT_FAILURE);
    }

    newThree->value = value;
    newThree->nohLeft = NULL;
    newThree->nohRight = NULL;

    if (node == NULL) {
        node = newThree;
    } else {

        if (value > node->value) {
            node->nohRight = newThree;
        } else if (value < node->value) {
            node->nohLeft = newThree;
        }

    }

    return node;
}

void callThreeBinary() {


}