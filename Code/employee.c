#include<stdio.h>
#define EMPSIZE 100

struct employee // Structure of employee
{
    int id,salary,age,active;// 1 0 
    char name[50],dept[50];
};
struct employee emplist[EMPSIZE];
int empcount = 0;
void printemployee(struct employee e);

int login()
{
    int attempt = 0;
    char username[20],password[20];
    while(1)
    {
        printf("\nEnter user name : ");
        scanf("%s",&username);
        printf("\nEnter Password : ");
        scanf("%s",&password);
        if((strcmp(username,"admin") == 0) && (strcmp(password,"123") == 0))
        {
            return 1;
        }
        else
        {
            attempt++;
            printf("\nLogin attempt remaning : %d",(3-attempt));
        }
        if(attempt == 3)
        {
            printf("\nInsufficient attempt : %d\n\tlogin fail...!",attempt);
            // getch();
            return(0);
        }
    }
}
// Finding Index by Id
int findIndexById(int id)
{
    int i;
    for(i=0;i<empcount;i++)
    {
        if(emplist[i].active == 1 && emplist[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
// Searching Employee function
void searchEmpById()
{
    int id,index;
    printf("\nEnter Employee Id which you want to Search : ");
    scanf("%d",&id);

    if(findIndexById(id) == -1)
    {
        printf("\n%d Id is not present in the current Employee List.",id);
        return;
    }

    index = findIndexById(id);

    printemployee(emplist[index]);
}
void addemployee()
{
    struct employee e;
    int i;

    if(empcount > EMPSIZE)
    {
	printf("\nEnployee list is full.");
	return;
    }
    printf("\nEnter Employee Id : ");
    scanf("%d",&e.id);

    if(findIndexById(e.id) != -1)
    {
        printf("\n%d Id is alredy present in current Employee List. ",e.id);
        return;
    }
    e.active = 1;
    printf("\nEnter Employee Name : ");
    scanf("%s",&e.name);
    printf("\nEnter Employee Salary : ");
    scanf("%d",&e.salary);
    printf("\nEnter Employee Dept.Name : ");
    scanf("%s",&e.dept);
    printf("\nEnter Employee Age : ");
    scanf("%d",&e.age);

    emplist[empcount] = e;
    empcount++;
}
void updateemployee()
{
    int id,index;
    printf("\nEnter Employee Id Which you want to update : ");
    scanf("%d",&id);

    if(findIndexById(id) == -1)
    {
        printf("\n%d Id is not present in current Employee List.",id);
        return;
    }
    index = findIndexById(id);

    printf("\nEnter Employee Name : ");
    scanf("%s",&emplist[index].name);
    printf("\nEnter Employee salary : ");
    scanf("%d",&emplist[index].salary);
    printf("\nEnter Employee Age : ");
    scanf("%d",&emplist[index].age);
    printf("\nEnter Employee Dept Name : ");
    scanf("%s",&emplist[index].dept);

    printf("\nEmployee Id %d success Fully updated.",id);
}
// Sorting by salary
// Accending Sorting
void sortemployee()
{
    int i,j;
    struct employee temp;
    for(i=0;i<empcount;i++)
    {
        for(j=(i+1);j<empcount;j++)
        {
            if(emplist[i].salary > emplist[j].salary)
            {
                temp = emplist[i];
                emplist[i] = emplist[j];
                emplist[j] = temp;
            }
        }
    }
    printf("\nEmployee List sorted by salary.");
}
// Sorting by Age
// Sorting in accending order
void sortemployeeage()
{
    int i,j;
    struct employee temp;
    for(i=0;i<empcount;i++)
    {
        for(j=(i+1);j<empcount;j++)
        {
            if(emplist[i].age > emplist[j].age)
            {
                temp = emplist[i];
                emplist[i] = emplist[j];
                emplist[j] = temp;
            }
        }
    }
    printf("\nEmployee List sorted by age.");
}
void deleteemployee()
{
    int id,index;
    printf("\nEnter Employee Id : ");
    scanf("%d",&id);
    if(findIndexById(id) == -1)
    {
	printf("\n%d Id is not present in current Employee List.");
	return;
    }
    index = findIndexById(id);

    emplist[index].active = 0;

    printf("\n%d is successfully Deleted from Employee list.",id);
}
void printemployee(struct employee e)
{
    printf("\nId : %d\tName : %s\tSalary : %d\tDeptName : %s\tAge : %d",e.id,e.name,e.salary,e.dept,e.age);
}
void dispemployee()
{
    int i,flag = 1;
    for(i=0;i<empcount;i++)
    {
	    if(emplist[i].active == 1)
	    {
	        flag = 0;
	        printemployee(emplist[i]);
	    }
    }
    if(flag)
    {
	    printf("\nEmployee List is Empty.");
    }
}
int main()
{
    int choice;
    if(login())
    {
        do
        {
	        printf("\n1)Insert Employee");
	        printf("\n2)Update Employee");
	        printf("\n3)Delete Employee");
    	    rintf("\n4)Display All Employee");
	        printf("\n5)Search Employee by ID");
            printf("\n6)Sorting of Employee by Salary");
            printf("\n7)Sorting of Employee by Age");
            printf("\n8)For Exit Employee Application");
	        printf("\nEnter below choice : ");
	        scanf("%d",&choice);

	        switch(choice)
	        {
	            case 1 : addemployee();
	        	         break;
	            case 2 : updateemployee();
	        	         break;
	            case 3 : deleteemployee();
	        	         break;
	            case 4 : dispemployee();
	        	         break;
                case 5 : searchEmpById();
                         break;
                case 6 : sortemployee();
                         break;
                case 7 : sortemployeeage();
                         break;
	            default :
	        	    printf("\nInvalid choice");
	        }
        }
        while(choice != 8);
    }
    return 0;
}