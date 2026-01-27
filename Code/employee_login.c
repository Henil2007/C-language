#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define EMPSIZE 100

struct employee // Structure of employee
{
    int id, salary, age, active; // 1 0
    char name[50], dept[50];
};
struct employee emplist[EMPSIZE];
int empcount = 0,empId = 0;
void printemployee(struct employee e);

int login()
{
    int attempt = 0;
    char userName[50], password[50];

    while (1)
    {
        printf("\nEnter UserName :");
        gets(userName);
        printf("\nEnter password:");
        gets(password);

        if ((strcmp(userName, "admin") == 0) && (strcmp(password, "123") == 0))
        {
            return 1;
        }
        else
        {
            attempt++;
            printf("\nLogin Attempt Remaning : %d", (3 - attempt));
        }

        if (attempt == 3)
        {
            printf("\nInsuficient Attempt : %d,\n\tLogin in failed", attempt);
            return (0);
        }
    }
}
// Finding Index by Id
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
// Searching Employee function
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
void sortEmployeeBySalary()
{
    int i, j;
    struct employee temp;
    for (i = 0; i < empcount; i++)
    {
        for (j = (i + 1); i < empcount; j++)
        {
            if (emplist[i].salary > emplist[j].salary)
            {
                temp = emplist[i];
                emplist[i] = emplist[j];
                emplist[j] = temp;
            }
        }
    }
    printf("\nEmployee List sorted by salary.");
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


    int main() {
    int choice;

    if (login()) {
        do {
            printf("\n\n--- Employee Management System ---");
            printf("\n1) Insert Employee");
            printf("\n2) Update Employee");
            printf("\n3) Delete Employee");
            printf("\n4) Display All Employees");
            printf("\n5) Search Employee by ID");
            printf("\n6) Sort Employees by Salary");
            printf("\n7) Exit");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);

            switch (choice)
            {
                case 1: addemployee(); 
                    break;
                case 2: updateemployee(); 
                    break;
                case 3: deleteemployee(); 
                    break;
                case 4: dispemployee();
                    break;
                case 5: searchEmpById(); 
                    break;
                case 6: sortEmployeeBySalary();
                    break;
                case 7: exit(0); 
                    // return 0;
                default: printf("\nInvalid choice...\n");
            }
        } while (choice != 0);
    } else {
        printf("\nLogin Failed! Exiting program.\n");
    }

    return 0;
}