#define MAX_SIZE 5

typedef struct {
    int item[MAX_SIZE];
} Stack;

Stack stack;
int top;

void initStack() {
    top = -1;
}

int emptyStack() {
    return top == -1;
}

int fullStack() {
    return top == (MAX_SIZE - 1);
}

void push(int item) {

    if (fullStack()) {
        printf("Pilha cheia!");
        exit(EXIT_FAILURE);
    }

    stack.item[top++] = item;
}

int pop() {

    if (emptyStack()) {
        printf("\n Pilha vazia!");
        exit(EXIT_FAILURE);
    }

    return stack.item[top--];
}

void callStack() {

    initStack();

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("\nTopo: %d", top);

    pop();
    pop();
    pop();

    printf("\nTopo: %d", top);

}
