#include<stdio.h>
#include<conio.h>
#define SIZE 5
int x[SIZE];
void scanArray();
void linearSearch();
void displayArray();

void main()
{
	int choice , i;
	scanArray();
	while(1)
	{
		clrscr();
		displayArray();
		printf("\n1. For linear Search");
		printf("\n2. For Binary Search");
		printf("\n3. Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : linearSearch();
				 break;
			case 3 : exit(0);
			default : printf("\nInvalid choice");
		}
		getch();
	}
	getch();
}

void linearSearch()
{
	int i;
	int key;
	int index = -1;
	printf("\nEnter a key you want to search : ");
	scanf("%d",&key);
	for(i=0;i<SIZE;i++)
	{
		if(key == x[i])
		{
			index = i;
			break;
		}
	}
	if(index >= 0)
	{
		printf("\nThe key %d found at %d",key,index);
	}
	else
	{
		printf("\nThe key not found");
	}
}
void scanArray()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter the value of x[%d] : ",i);
		scanf("%d",&x[i]);
	}
}
void displayArray()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d\t",x[i]);
	}
}