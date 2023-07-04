void executeBank() {

    struct Account {

        int numberAccount;
        char name[64];
        float balance;

    };

    struct Account account;

    int option = 0;

    do {

        system("cls");
        printf("Bem-vindo ao BANCO VITIN");
        printf("\nEscolha sua opcao:");
        printf("\n 1 - Inicie uma conta");
        printf("\n 2 - Deposite um valor");
        printf("\n 3 - Sacar um valor");
        printf("\n 4 - Verificar saldo");
        printf("\n 0 - Finalizar \n");

        scanf("%d", &option);

        system("cls");

        if (option == 1) {

            getchar();
            printf("Iniciando criacao de conta:");
            printf("\nDigite seu nome completo: ");
            scanf("%[0-9a-zA-Z,. ]", account.name);
            getchar();

            printf("Deposite um saldo inicial: ");
            scanf("%f", &account.balance);

            account.numberAccount = 1;

        } else {

            int accountNumber = 0;
            printf("Para continuar, informe seu numero de conta: ");
            scanf("%d", &accountNumber);

            if (account.numberAccount != accountNumber) {

                printf("Nao foi encontrada nenhuma conta com esse numero.");

            } else {

                system("cls");

                if (option == 2) {

                    float value = 0.0F;

                    printf("Digite o valor que deseja depositar: ");
                    scanf("%f", &value);

                    account.balance += value;

                    system("cls");
                    printf("Deposito de %0.2f efetuado com sucesso.", value);

                } else if (option == 3) {

                    float value = 0.0F;

                    printf("Digite o valor que deseja sacar: ");
                    scanf("%f", &value);

                    system("cls");

                    if (account.balance >= value) {
                        account.balance -= value;
                        printf("Saque de %0.2f efetuado com sucesso.", value);
                    } else {
                        printf("Voce nao tem esse saldo suficiente para sacar.");
                    }

                } else if (option == 4) {

                    system("cls");
                    printf("Nome: %s", account.name);
                    printf("\nNumero da conta %d", account.numberAccount);
                    printf("\nSaldo total de R$%0.2f.", account.balance);

                }

                printf("\nDeseja finalizar o app? ");
                printf("\n0 - Sim | 1 - Nao\n");
                scanf("%d", &option);

            }

        }

    } while (option != 0);

}
