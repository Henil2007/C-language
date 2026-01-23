#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct customer
{
    int cid;
    char name[50];
    char branch[300];
} c[SIZE];

void scanFunction();
void displayFunction();
void displayParticularFunction();
void deleteFunction();
void updateFunction();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Scan Details");
        printf("\n2. Display Details");
        printf("\n3. Display Particular");
        printf("\n4. Delete");
        printf("\n5. Update");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanFunction();
            break;
        case 2:
            displayFunction();
            break;
        case 3:
            displayParticularFunction();
            break;
        case 4:
            deleteFunction();
            break;
        case 5:
            updateFunction();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter a valid choice...");
        } // End of Switch
    } // End of While
    return 0;
} // End of main()

/* Scan Details */
void scanFunction()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter customer ID : ");
        scanf("%d", &c[i].cid);

        printf("Enter customer Name : ");
        scanf("%s", c[i].name);

        printf("Enter branch : ");
        scanf("%s", c[i].branch);
    }
}

/* Display All Records */
void displayFunction()
{
    int i;
    printf("\nCID\tName\tBranch\n");
    for (i = 0; i < SIZE; i++)
    {
        if (c[i].cid != -1)
            printf("%d\t%s\t%s\n", c[i].cid, c[i].name, c[i].branch);
    }
}

/* Display Particular Customer */
void displayParticularFunction()
{
    int id, i, found = 0;
    printf("Enter customer ID to search : ");
    scanf("%d", &id);

    for (i = 0; i < SIZE; i++)
    {
        if (c[i].cid == id)
        {
            printf("\nCID : %d", c[i].cid);
            printf("\nName : %s", c[i].name);
            printf("\nBranch : %s\n", c[i].branch);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Customer not found!\n");
}

/* Delete Record */
void deleteFunction()
{
    int id, i, found = 0;
    printf("Enter customer ID to delete : ");
    scanf("%d", &id);

    for (i = 0; i < SIZE; i++)
    {
        if (c[i].cid == id)
        {
            c[i].cid = -1; // mark as deleted
            found = 1;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Customer not found!\n");
}

/* Update Record */
void updateFunction()
{
    int id, i, found = 0;
    printf("Enter customer ID to update : ");
    scanf("%d", &id);

    for (i = 0; i < SIZE; i++)
    {
        if (c[i].cid == id)
        {
            printf("Enter new name : ");
            scanf("%s", c[i].name);

            printf("Enter new branch : ");
            scanf("%s", c[i].branch);

            found = 1;
            printf("Record updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Customer not found!\n");
}
