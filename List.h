#define MAX_SIZE 5

typedef struct NodeList {
    int number, next;
} List;

List *headList[MAX_SIZE];
int tail = -1, size = 0, head = -1;

void insertInLeft(int number) {

    if (size >= MAX_SIZE)
        exit(EXIT_FAILURE);

    headList[size]->number = number;
    headList[size]->next = head;
    head = size;

    if (tail == -1)
        tail = size;

    size++;
}

void insertInRight(int number) {

    if (size >= MAX_SIZE)
        exit(EXIT_FAILURE);

    headList[size]->number = number;
    headList[size]->next = -1;

    if (tail != -1)
        headList[tail]->next = size;

    tail = size;

    if (head == -1)
        head = size;

    size++;
}

void removeInLeft() {

    if (head == -1) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
        return;
    }

    int indexToRemove = head;
    head = headList[indexToRemove]->next;

    if (head == -1) {
        tail = -1;
    }

    size--;
}

void removeInRight() {

    if (tail == -1) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
        return;
    }

    if (head == tail) {
        head = -1;
        tail = -1;
    } else {

        int current = head;

        while (headList[current]->next != tail)
            current = headList[current]->next;


        tail = current;
        headList[current]->next = -1;
    }

    size--;

}

void viewList() {

    if (head == -1) {
        printf("\nFila Vazia!\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLista Atual\n");

    int current = head;

    while (current != -1) {
        printf("[%d]\n", headList[current]->number);
        current = headList[current]->next;
    }

}

int getNumber() {

    system("cls");
    getchar();

    int number = 0;

    printf("\nDigite o numero: ");
    scanf("%d", &number);

    return number;
}

void executeFunction(int code) {

    if (code == 1) {

        insertInRight(getNumber());

    } else if (code == 2) {

        insertInLeft(getNumber());

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

    printf("Selecao de numeros: ");

    int code = 0;

    do {

        printf("\nDigite alguma das opcoes abaixo:\n");
        printf("\n1 - Inserir numero no fim da lista.");
        printf("\n2 - Inserir numero no comeco da lista.");
        printf("\n3 - Remover numero do fim da lista.");
        printf("\n4 - Remover numero do comeco da lista.");
        printf("\n5 - Exibir a lista de numeros.");
        printf("\n0 - Sair da aplicacao.");

        scanf("%d", &code);
        executeFunction(code);

    } while (code > 0);

}