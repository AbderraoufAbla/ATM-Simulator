#include <stdio.h>

int main() {
    // initialize account balance and transaction history
    float balance = 1000;
    float transactions[100] = {0};
    int num_transactions = 0;

    // display welcome message and menu
    printf("Welcome to MyBank ATM\n");
    printf("Please select an option:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Transaction History\n");
    printf("5. Exit\n");

    // process user input
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // deposit operation
                float deposit;
                printf("\nEnter amount to deposit: ");
                scanf("%f", &deposit);
                balance += deposit;
                transactions[num_transactions] = deposit;
                num_transactions++;
                printf("\nDeposit of $%.2f successful. New balance is $%.2f\n", deposit, balance);
                break;
            case 2:
                // withdrawal operation
                float withdrawal;
                printf("\nEnter amount to withdraw: ");
                scanf("%f", &withdrawal);
                if (withdrawal > balance) {
                    printf("\nInsufficient funds. Withdrawal not possible.\n");
                } else {
                    balance -= withdrawal;
                    transactions[num_transactions] = -withdrawal;
                    num_transactions++;
                    printf("\nWithdrawal of $%.2f successful. New balance is $%.2f\n", withdrawal, balance);
                }
                break;
            case 3:
                // balance inquiry
                printf("\nCurrent balance is $%.2f\n", balance);
                break;
            case 4:
                // transaction history
                printf("\nTransaction History:\n");
                for (int i = 0; i < num_transactions; i++) {
                    if (transactions[i] > 0) {
                        printf("Deposit of $%.2f\n", transactions[i]);
                    } else {
                        printf("Withdrawal of $%.2f\n", -transactions[i]);
                    }
                }
                break;
            case 5:
                // exit program
                printf("\nThank you for using MyBank ATM!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
