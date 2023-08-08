#define MAX_SIZE 5

typedef struct {
    int item[MAX_SIZE];
} Queue;

Queue queueStruct;
int queueEnd, queueStart;

void queueInit() {
    queueEnd = -1;
    queueStart = -1;
}

int queueEmpty() {
    return queueStart == -1;
}

int queueFull() {
    return queueEnd == (MAX_SIZE - 1);
}

void queue(int item) {

    if (queueFull()) {
        printf("Pilha cheia!");
        exit(EXIT_FAILURE);
    }

    if (queueStart == -1)
        queueStart = 0;

    queueStruct.item[++queueEnd] = item;
}

int dequeue() {

    if (queueEmpty()) {
        printf("\n Pilha vazia!");
        exit(EXIT_FAILURE);
    }

    return queueStruct.item[++queueStart];
}

void callQueue() {

    queueInit();

    queue(10);
    queue(20);
    queue(30);
    queue(40);
    queue(50);

    dequeue();
    dequeue();
    dequeue();

    printf("Fila -> %d", queueStruct.item[queueStart]);

}
