#include<stdio.h>
#define emplist 5

int empCount = 0;
struct Employee
{
	int id , salary, active , age;
	char name[100] , dept[100];
}emp[emplist] , e;


int searchEmployee(int id)
{
	int i;
	for(i = 0 ; i < empCount ;i++)
	{	
		if(emp[i].id == id && emp[i].active == 1)
		{
			return i;
		}
	}
	return -1;
}

void addEmployee()
{
	if(empCount > emplist)
	{
		return ;
	}
	else
	{	
		printf("Enter ID : ");
		scanf("%d",&e.id);
		
		if(searchEmployee(e.id) != -1)
		{
			printf("Employee Already Exists..");
			return ;
		}
		
		printf("Enter Age : ");
		scanf("%d",&e.age);
		
		printf("Enter Salary : ");
		scanf("%d",&e.salary);
		
		e.active = 1;
		
		printf("Enter Name : ");
		scanf("%s",&e.name);
		
		printf("Enter Department : ");
		scanf("%s",&e.dept);
		
		emp[empCount] = e;
		printf("Employee Added Successfully...\n");
		
		empCount++;
	}
}

void updateEmployee()
{
	int id;
	int index;
	
	printf("Enter Id at which you want to update : ");
	scanf("%d",&id);
	
	index = searchEmployee(id);
	
	if(index == -1)
	{
		printf("Employee Does not Exist....");
		return ;
	}
	
	printf("Enter Age : ");
	scanf("%d",&e.age);

	printf("Enter Salary : ");
	scanf("%d",&e.salary);

	printf("Enter Name : ");
	scanf("%s",&e.name);
		
	printf("Enter Department : ");
	scanf("%s",&e.dept);
	
	emp[index] = e;
	printf("Employee at index %d upadted Successfully\n",index);
	
}

void deleteEmployee()
{
	int id;
	int index;
	
	printf("Enter ID at which you want to delete the employee : ");
	scanf("%d",&id);
	
	index = searchEmployee(id);
	
	if(index == -1)
	{
		printf("Employee Does not Exist....");
		return ;
	}
	
	emp[index].active = 0;
	printf("Employee at index %d with id %d deleted Successfully\n",index , id);
}

void displayEmployee()
{
	int i;
	printf("ID\tName\tAge\tSalary\tDepartment\n");
	for(i = 0 ; i <empCount ;i++)
	{       if(emp[i].active != 0)
		{
			printf("%d\t%s\t%d\t%d\t%s\n",emp[i].id,emp[i].name,emp[i].age,emp[i].salary,emp[i].dept);
		}
	}
	printf("\n");
}

int main()
{	
	int choice;
	int isRunning = 1;
	int id;
	// clrscr();

	while(isRunning)
	{
		printf("\n1. Add\n2. Update\n3. Delete\n4. Search\n5. Display\n6. Exit");
		printf("nEnter Your Choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : addEmployee();
					 break;

			case 2 : updateEmployee();
					 break;

			case 3 : deleteEmployee();
					 break;

			case 4 : printf("Enter Id you want to search : ");
				 scanf("%d",&id);
				 searchEmployee(id);
				 break;
					 
			case 5 : displayEmployee();
					 break;
					 
			case 6 : printf("Exiting the Employee Management System");
					 isRunning = 0;
					 break;
					 
			default : printf("Wrong Choice...");	 
		}	
	}
	return 0;
	// getch();
} //end of main