#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

struct Employee
{
    int id;
    char name[50];
    float salary;
};// End of structure employees

void scanEmployee(struct Employee *e);
void displayEmployee(struct Employee *e);
void displayAll(struct Employee emp[], int n);
void displayParticular(struct Employee emp[], int n, int id);
void updateEmployee(struct Employee emp[], int n, int id);
void deleteEmployee(struct Employee emp[], int *n, int id);

int main()
{
    struct Employee emp[MAX];
    int n = 0, choice, id;

    while (1)
    {
        printf("\n----- Employee Management System -----");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Display Particular Employee");
        printf("\n4. Update Employee");
        printf("\n5. Delete Employee");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (n < MAX)
            {
                scanEmployee(&emp[n]);
                n++;
            }
            else
            {
                printf("\nEmployee limit reached!");
            }
            break;

        case 2:
            displayAll(emp, n);
            break;

        case 3:
            printf("\nEnter Employee ID: ");
            scanf("%d", &id);
            displayParticular(emp, n, id);
            break;

        case 4:
            printf("\nEnter Employee ID to update: ");
            scanf("%d", &id);
            updateEmployee(emp, n, id);
            break;

        case 5:
            printf("\nEnter Employee ID to delete: ");
            scanf("%d", &id);
            deleteEmployee(emp, &n, id);
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid choice!");
        } // End of switch
    } // End of While
    return 0;
} // End of main()

void scanEmployee(struct Employee *e)
{
    printf("\nEnter Employee ID: ");
    scanf("%d", &e->id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", e->name);

    printf("Enter Employee Salary: ");
    scanf("%f", &e->salary);
} // End of sacn enployees function

void displayEmployee(struct Employee *e)
{
    printf("\nID: %d", e->id);
    printf("\nName: %s", e->name);
    printf("\nSalary: %.2f\n", e->salary);
}// End of display function

void displayAll(struct Employee emp[], int n)
{
    int i;
    if (n == 0)
    {
        printf("\nNo employees to display!");
        return;
    }

    for (i = 0; i < n; i++)
    {
        displayEmployee(&emp[i]);
    }
} // End of display all function

void displayParticular(struct Employee emp[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            displayEmployee(&emp[i]);
            return;
        }
    }
    printf("\nEmployee not found!");
} // End of display particular function

void updateEmployee(struct Employee emp[], int n, int id)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (emp[i].id == id)
        {
            printf("\nEnter new Name: ");
            scanf(" %[^\n]s", emp[i].name);

            printf("Enter new Salary: ");
            scanf("%f", &emp[i].salary);

            printf("\nEmployee updated successfully!");
            return;
        }// End of if
    } // end of for loop
    printf("\nEmployee not found!");
} // End of Update function

void deleteEmployee(struct Employee emp[], int *n, int id)
{
    int i, j;
    for (i = 0; i < *n; i++)
    {
        if (emp[i].id == id)
        {
            for (j = i; j < *n - 1; j++)
            {
                emp[j] = emp[j + 1];
            } // End of inner for loop
            (*n)--;
            printf("\nEmployee deleted successfully!");
            return;
        } // End of if 
    } // End of outer for loop
    printf("\nEmployee not found!");
} // End of delete function
