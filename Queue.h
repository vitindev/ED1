#define MAX_SIZE 5

typedef struct {
    int item[MAX_SIZE];
} Stack;

Stack queue;
int top;

void initStack() {
    top = -1;
}

int empty() {
    return top == -1;
}

int full() {
    return top == (MAX_SIZE - 1);
}

void push(Stack *stack, int item) {

    if (full()) {
        printf("Pilha cheia!");
        exit(EXIT_FAILURE);
    }

    stack->item[top++] = item;
}

int pop(Stack *stack) {

    if (empty()) {
        printf("\n Pilha vazia!");
        exit(EXIT_FAILURE);
    }

    return stack->item[top--];
}

void call() {

    initStack();

    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);
    push(&queue, 40);
    push(&queue, 50);

    printf("\nTopo: %d", top);

    pop(&queue);
    pop(&queue);
    pop(&queue);

    printf("\nTopo: %d", top);

}
