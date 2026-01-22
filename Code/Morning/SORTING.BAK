/*
				Name : Henil Patel
				D.O.C : 31/12/2025
				Topic : Sorting
*/
#include<stdio.h>
#include<conio.h>
#define SIZE 5
void main()
{
	int i,j,temp;
	int a[SIZE];
	int exch=1;
	int count=0;
	clrscr();
	for(i=0;i<SIZE;i++)
	{
		printf("Enter the value of a[%d] : ",i);
		scanf("%d",&a[i]);
	}

	for(i=0;i<SIZE;i++)
	{
		exch=0;
		for(j=0;j<SIZE-1;j++)
		{
			count++;
			if(a[j] > a[j+1])
			{
				exch=1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("\nThe array after sorting\n");
	for(i=0;i<SIZE;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}