void ex1() {

    int value1, value2, *p1 = &value1, *p2 = &value2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &value1);

    system("cls");

    printf("Digite o segundo numero: ");
    scanf("%d", &value2);

    system("cls");

    printf("Adicao: %d\n", *p1 + *p2);
    printf("Subtracao: %d\n", *p1 - *p2);
    printf("Multiplicacao: %d\n", *p1 * *p2);
    printf("Divisao: %d", *p1 / *p2);

}

void ex2() {

    int values[3], *p = values;

    for (int i = 0; i < 3; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    system("cls");

    int help = 0;

    for (int i = 0; i < 3; i++) {

        for (int k = (i + 1); k < 3; k++) {

            if (*(p + i) > *(p + k)) {
                help = *(p + i);
                *(p + i) = *(p + k);
                *(p + k) = help;
            }

        }

    }

    for (int i = 0; i < 3; i++)
        printf("Numero %d - Endereco (%d)\n", values[i], &values[i]);

}

void ex3() {

    int values[6], *p = &values;

    for (int i = 0; i < 6; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < 6; i++)
        printf("Numero %d: %d Endereco %d\n", i + 1, values[i], &values[i]);

}

void ex4() {

    int values[4], *p = &values;

    for (int i = 0; i < 4; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int max = values[0], min = values[0];

    for (int i = 0; i < 4; i++) {

        if (*(p + i) > max) {
            max = *(p + i);
        } else if (*(p + i) < min) {
            min = *(p + i);
        }

    }

    system("cls");

    printf("Maior numero do vetor: %d\n", max);
    printf("Menor numero do vetor: %d", min);

}

void ex5() {

    char phrase[50], *p = &phrase;

    printf("Digite uma frase para contar os caracteres: ");
    scanf("%[^\n]%*c", phrase);

    int count = 0;

    while (*(p + count) != '\0')
        count++;

    printf("Total de caracteres: %d", count);

}

void ex6() {

    char phrase[60], *p = &phrase;

    printf("Digite uma frase para separar as palavras: ");
    scanf("%[^\n]%*c", phrase);

    int count = 0;

    while (*(p + count) != '\0') {

        if (*(p + count) != ' ') {
            printf("%c", phrase[count]);
        } else if (*(p + count) == ' ') {
            printf("%c", '\n');
        }

        count++;
    }

}