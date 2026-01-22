#include <stdio.h>
#include <stdlib.h>
#define EMPSIZE 100

struct employee // Structure of employee
{
    int id, salary, age, active; // 1 0
    char name[50], dept[50];
};
struct employee emplist[EMPSIZE];
int empcount = 0, empId = 0;
void printemployee(struct employee e);

int findIndexById(int id);
void searchEmpById();
void addemployee();
void updateemployee();
void deleteemployee();
void printemployee(struct employee e);
void dispemployee();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert Employee.\n");
        printf("2. Update Employee.\n");
        printf("3. Delete Employee.\n");
        printf("4. Display all Employees.\n");
        printf("5. Display perticular Employee.\n");
        printf("6. Exit.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addemployee();
            break;
        case 2:
            updateemployee();
            break;
        case 3:
            deleteemployee();
            break;
        case 4:
            dispemployee();
            break;
        case 5:
            searchEmpById();
            break;
        case 6:
            exit(0);
        default:
            printf("\nENter valid choice...");
        }
    }

    return 0;
}

int findIndexById(int id)
{
    int i;
    for (i = 0; i < empcount; i++)
    {
        if (emplist[i].active == 1 && emplist[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void searchEmpById()
{
    int id, index;
    printf("\nEnter Employee Id which you want to Search : ");
    scanf("%d", &id);

    if (findIndexById(id) == -1)
    {
        printf("\n%d Id is not present in the current Employee List.", id);
        return;
    }

    index = findIndexById(id);

    printemployee(emplist[index]);
}

void addemployee()
{
    struct employee e;
    int i;

    if (empcount == 0)
    {
        for (i = 0; i < EMPSIZE; i++)
        {
            emplist[i].id = 0;
        }
    }
    if (empcount >= EMPSIZE)
    {

        printf("\nEnployee list is full.");
        return;
    }

    printf("\nEnter Employee Id : ");
    scanf("%d", &e.id);

    if (findIndexById(e.id) != -1)
    {
        printf("\n%d Id is alredy present in current Employee List. ", e.id);
        return;
    }
    e.active = 1;
    printf("\nEnter Employee Name : ");
    scanf("%s", &e.name);
    printf("\nEnter Employee Salary : ");
    scanf("%d", &e.salary);
    printf("\nEnter Employee Dept.Name : ");
    scanf("%s", &e.dept);
    printf("\nEnter Employee Age : ");
    scanf("%d", &e.age);

    emplist[empcount] = e;
    empcount++;
}

void updateemployee()
{
    int id, index;
    printf("\nEnter Employee Id Which you want to update : ");
    scanf("%d", &id);

    if (findIndexById(id) == -1)
    {
        printf("\n%d Id is not present in current Employee List.", id);
        return;
    }
    index = findIndexById(id);

    printf("\nEnter Employee Name : ");
    scanf("%s", &emplist[index].name);
    printf("\nEnter Employee salary : ");
    scanf("%d", &emplist[index].salary);
    printf("\nEnter Employee Age : ");
    scanf("%d", &emplist[index].age);
    printf("\nEnter Employee Dept Name : ");
    scanf("%s", &emplist[index].dept);

    printf("\nEmployee Id : %d success Fully updated.", id);
}

void deleteemployee()
{
    int id, index;
    printf("\nEnter Employee Id : ");
    scanf("%d", &id);
    if (findIndexById(id) == -1)
    {
        printf("\n%d Id is not present in current Employee List.");
        return;
    }
    index = findIndexById(id);

    emplist[index].active = 0;

    printf("\n%d is successfully Deleted from Employee list.", id);
}

void printemployee(struct employee e)
{
    printf("\nId : %d | Name : %s | Salary : %d | DeptName : %s | Age : %d", e.id, e.name, e.salary, e.dept, e.age);
}

void dispemployee()
{
    int i, flag = 1;
    for (i = 0; i < empcount; i++)
    {
        if (emplist[i].active == 1)
        {
            flag = 0;
            printemployee(emplist[i]);
        }
    }
    if (flag)
    {
        printf("\nEmployee List is Empty.");
    }
}