#include <stdio.h>
#include <stdlib.h>

struct BankAccount
{
    int accountNumber;
    float balance;
    float interest;
};

int main()
{
    struct BankAccount acc;        
    struct BankAccount *ptr = &acc; 

    int choice;
    float amount;
    int opened = 0;

    while (1)
    {
        printf("\n---- BANK MENU ----\n");
        printf("1. Open Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Calculate Interest\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:   
            printf("Enter Account Number: ");
            scanf("%d", &ptr->accountNumber);

            printf("Enter Initial Balance: ");
            scanf("%f", &ptr->balance);

            ptr->interest = 0.0f;
            opened = 1;

            printf("Account opened successfully.\n");
            break;

        case 2:   
            if (!opened)
            {
                printf("Please open an account first.\n");
                break;
            }

            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if (amount > 0)
            {
                ptr->balance += amount;
                printf("Deposit successful.\n");
            }
            else
            {
                printf("Invalid deposit amount.\n");
            }
            break;

        case 3:   
            if (!opened)
            {
                printf("Please open an account first.\n");
                break;
            }

            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount > 0 && (ptr->balance - amount) >= 1000)
            {
                ptr->balance -= amount;
                printf("Withdrawal successful.\n");
            }
            else
            {
                printf("Withdrawal not allowed. Minimum balance must be 1000.\n");
            }
            break;

        case 4:   
            if (!opened)
            {
                printf("Please open an account first.\n");
                break;
            }

            if (ptr->balance >= 50000)
                ptr->interest = ptr->balance * 0.06f;
            else if (ptr->balance >= 20000)
                ptr->interest = ptr->balance * 0.04f;
            else
                ptr->interest = ptr->balance * 0.02f;

            printf("Interest calculated successfully.\n");
            break;

        case 5:   
            if (!opened)
            {
                printf("Please open an account first.\n");
                break;
            }

            printf("\n--- ACCOUNT DETAILS ---\n");
            printf("Account Number  : %d\n", ptr->accountNumber);
            printf("Balance         : %.2f\n", ptr->balance);
            printf("Interest        : %.2f\n", ptr->interest);
            printf("Final Amount    : %.2f\n", ptr->balance + ptr->interest);
            break;

        case 6:   
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
