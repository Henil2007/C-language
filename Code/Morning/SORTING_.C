/*
			Name : Henil Patel
			D.O.C : 30/12/2025
			Topic : Sorting of an array in asscending order
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[5],i,j,temp;
	clrscr();
	for(i=0;i<5;i++)
	{
		printf("Enter value of a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	for(i=0;i<5;i++)
	{
		printf("\t%d",a[i]);
	}

	getch();
}