


/* QUESTÃO 6 */

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

    Produto *produto[size];

    while (option != 0) {

        printf("\nSelecione uma opcao:");
        printf("\n1 - Inserir");
        printf("\n2 - Pesquisar");
        printf("\n3 - Remover");
        printf("\n0 - Sair\n");

        scanf("%d", &option);
        getchar();

        system("cls");

        if (option == 1) {

            if (amount >= size) {
                printf("A quantidade de produtos ultrapassa o limite permitido!");
                return;
            }

            Produto product = *produto[amount];

            printf("Insercao de Produto:\n\n");
            printf("Digite o codigo do produto: ");
            scanf("%d", &product.codeId);

            printf("Digite a quantidade inicial de estoque: ");
            scanf("%d", &product.amountAvailable);

            printf("Digite o preco: ");
            scanf("%f", &product.price);

            getchar();
            printf("De um nome para esse produto: ");
            scanf("%[0-9a-zA-Z,. ]", product.name);
            getchar();

            amount++;

        } else if (option == 2) {

            char productName[100];

            printf("Digite o nome do produto que deseja buscar:\n");
            scanf("%[0-9a-zA-Z,. ]", productName);

            int productPos = searchProduct(size, produto, productName);

            system("cls");

            if (productPos == -1) {

                printf("Nenhum produto encontrado com esse nome.");

            } else {

                Produto product = *produto[productPos];

                printf("Descricao do produto: ");
                printf("\nCodigo: %d", product.codeId);
                printf("\nNome: %s", product.name);
                printf("\nQuantidade disponivel: %d", product.amountAvailable);
                printf("\nPreco: %0.2f", product.price);

            }

        } else if (option == 3) {

            char productName[100];

            printf("Digite o nome do produto que deseja apagar:\n");
            scanf("%[0-9a-zA-Z,. ]", productName);

            int productPos = searchProduct(size, produto, productName);
            Produto prod = *produto[productPos], copyProd;

            for (int i = 0; i < size; i++) {

                if (productPos != i)
                    continue;

                if (i == (size - 1)) {

                    printf("DELETE LAST POS");

                    // LIMPAR PRIMEIRO PARA EVITAR QUALQUER PROBLEMA FUTURO

                    for (int i = 0; i < 100; i++) {
                        prod.name[i] = '\0';

                        printf("Number: %d", i);

                    }

                    printf("Sumiu -> %s", prod.name);

                    prod.price = 0;
                    prod.codeId = -1;
                    prod.amountAvailable = 0;

                } else {

                    printf("DELETE POS");

                    copyProd = *produto[i + 1];

                    // LIMPAR PRIMEIRO PARA EVITAR QUALQUER PROBLEMA FUTURO

                    for (int i = 0; i < 100; i++)
                        prod.name[i] = '\0';

                    for (int i = 0; i < 100; i++) {
                        prod.name[i] = copyProd.name[i];
                        copyProd.name[i] = '\0';
                    }

                    prod.price = copyProd.price;
                    prod.codeId = copyProd.codeId;
                    prod.amountAvailable = copyProd.amountAvailable;

                    // LIMPANDO A PRÓXIMA POSIÇÃO

                    copyProd.price = 0;
                    copyProd.codeId = -1;
                    copyProd.amountAvailable = 0;

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
    Vector vector[size];
    vector[0].id = 1;
    vector[1].id = 2;
    vector[2].id = 3;

    /* LIBERANDO ESPAÇO */
    //free(vector);

    //CRIANDO UM NOVO VETOR
    Vector newVector[size];
    newVector[0].id = 4;
    newVector[1].id = 5;
    newVector[2].id = 6;

    /* EFETUANDO A SOMA DE 2 VETORES */

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