
/* QUESTÃO 1
 * Resposta: Certo
 * */

/* QUESTÃO 2
 * Resposta: Certo
 * */

/* QUESTÃO 3
 * Resposta: Letra C
 * */

/* QUESTÃO 4
 * Resposta: Estrutura de dados, para mim, seria como os dados são armazenados e utilizados.
 * Sobre a importancia, seria facilidade na manipulação, eficiencia muitas vezes, otimização além da organização
 * e metodos de uso, como a pilha.
 * */

/* QUESTÃO 5
 * Resposta: Temos a alocação dinamica e estatica.
 * Estatica -> Seria a qual temos um limite bem definido, como um int array[100], então só poderemos utilizar esses 100 espaços.
 * Dinamica -> Serial a qual temos um limite variavel que muda de acordo com a demanda. Exemplo: Se temos um array de 50 posições
 * e precisamos de mais, usamos funções definidas para alocar mais espaços como o malloc e da mesma forma que aumentamos os espaços
 * podemos diminuir e liberar a memoria usando a função free.
 * */

/* QUESTÃO 6 */

int randNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

typedef struct {

    char name[100];
    float price;
    int codeId, amountAvailable;

} Produto;

int searchProduct(int size, Produto *produto, char productName[100]) {

    for (int i = 0; i < size; i++) {

        if (strcmp(produto[i].name, productName) == 0)
            return i;

    }

    return -1;

}

void av6() {

    int size = 0, option = 1, amount = 0;

    printf("\nDigite a quantidade de produtos que deseja cadastrar:\n");
    scanf("%d", &size);

    Produto *product = (Produto *) malloc(size * sizeof(Produto));

    while (option != 0) {

        printf("\nSelecione uma opcao:");
        printf("\n1 - Inserir");
        printf("\n2 - Pesquisar");
        printf("\n3 - Remover");
        printf("\n0 - Sair\n");

        scanf("%d", &option);
        system("cls");

        if (option == 1) {

            if (amount >= size) {
                printf("A quantidade de produtos ultrapassa o limite permitido!");
                return;
            }

            printf("Insercao de Produto:\n\n");
            printf("Digite o codigo do produto: ");
            scanf("%d", &product->codeId);

            printf("Digite a quantidade inicial de estoque: ");
            scanf("%d", &product->amountAvailable);

            printf("Digite o preco: ");
            scanf("%f", &product->price);

            getchar();
            printf("De um nome para esse produto: ");
            fgets(product->name, sizeof(product->name), stdin);

            amount++;

        } else if (option == 2) {

            char productName[100];

            getchar();
            printf("Digite o nome do produto que deseja buscar:\n");
            fgets(productName, sizeof(productName), stdin);

            int productPos = searchProduct(size, product, productName);

            system("cls");

            if (productPos == -1) {

                printf("Nenhum produto encontrado com esse nome.");

            } else {

                Produto searchedProd = product[productPos];

                printf("Descricao do produto: ");
                printf("\nCodigo: %d", searchedProd.codeId);
                printf("\nNome: %s", searchedProd.name);
                printf("\nQuantidade disponivel: %d", searchedProd.amountAvailable);
                printf("\nPreco: %0.2f", searchedProd.price);

            }

        } else if (option == 3) {

            char productName[100];

            getchar();
            printf("Digite o nome do produto que deseja apagar:\n");
            fgets(productName, sizeof(productName), stdin);

            int productPos = searchProduct(size, product, productName);
            Produto searchedProd = product[productPos];

            for (int i = 0; i < size; i++) {

                if (productPos != i)
                    continue;

                if (i == (size - 1)) {

                    printf("DELETE LAST POS");

                    // LIMPAR PRIMEIRO PARA EVITAR QUALQUER PROBLEMA FUTURO

                    for (int i = 0; i < 100; i++)
                        searchedProd.name[i] = '\0';

                    searchedProd.price = 0;
                    searchedProd.codeId = -1;
                    searchedProd.amountAvailable = 0;

                } else {

                    printf("DELETE POS");

                    Produto cloneProd = product[i + 1];

                    // LIMPAR PRIMEIRO PARA EVITAR QUALQUER PROBLEMA FUTURO

                    for (int i = 0; i < 100; i++)
                        searchedProd.name[i] = '\0';

                    for (int i = 0; i < 100; i++) {
                        searchedProd.name[i] = cloneProd.name[i];
                        cloneProd.name[i] = '\0';
                    }

                    searchedProd.price = cloneProd.price;
                    searchedProd.codeId = cloneProd.codeId;
                    searchedProd.amountAvailable = cloneProd.amountAvailable;

                    // LIMPANDO A PRÓXIMA POSIÇÃO

                    cloneProd.price = 0;
                    cloneProd.codeId = -1;
                    cloneProd.amountAvailable = 0;

                }

            }

        }

    }

}

typedef struct {

    int id;

} Vector;

void av7() {

    int size = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    /* CRIANDO UM VETOR */
    Vector *vector = (Vector *) malloc(size * sizeof(Vector));

    for (int i = 0; i < size; i++)
        vector[i].id = randNumber(1, 100);

    /* LIBERANDO ESPAÇO */
    free(vector);

    // CRIANDO UM NOVO VETOR
    Vector *newVector = (Vector *) malloc(size * sizeof(Vector));

    for (int i = 0; i < size; i++)
        newVector[i].id = randNumber(1, 100);

    // ALOCANDO NOVAMENTE O PRIMEIRO VETOR, JÁ QUE FOI FEITO A LIBERAÇÃO DO MESMO
    vector = (Vector *) malloc(size * sizeof(Vector));

    for (int i = 0; i < size; i++)
        vector[i].id = randNumber(1, 100);

    /* EFETUANDO A SOMA DOIS 2 VETORES */

    Vector baseVector[size];

    for (int i = 0; i < size; i++)
        baseVector[i].id = vector[i].id += newVector[i].id;

    for (int i = 0; i < size; i++)
        printf("\nResultado da soma de dois vetores pos=%d, result=%d.", i + 1, baseVector[i].id);

    /* PRODUTO INTERNO */

    int prodInt = 0;

    for (int i = 0; i < size; i++)
        prodInt += vector[i].id * newVector[i].id;

    printf("\nResultado do produto interno result=%d", prodInt);

    /* PRODUTO VETORIAL */

    if (size != 3) {
        printf("\nO calculo do produto vetorial é feito somente em vetores tridimensionais.");
        exit(EXIT_FAILURE);
    }

    baseVector[0].id = vector[1].id * newVector[2].id - vector[2].id * newVector[1].id;
    baseVector[1].id = vector[2].id * newVector[0].id - vector[0].id * newVector[2].id;
    baseVector[2].id = vector[0].id * newVector[1].id - vector[1].id * newVector[0].id;

    for (int i = 0; i < size; i++)
        printf("\nResultado do produto vetorial pos=%d, result=%d.", i + 1, baseVector[i].id);

}