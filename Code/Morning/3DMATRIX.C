#include<stdio.h>
#include<conio.h>
#define ROW 3
#define COL 3
#define SIZE 3
void main()
{
	int a[ROW][COL];
	int b[SIZE][ROW][COL];
	int i,j,k;
	clrscr();
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("\nEnter the value of a[%d][%d] : ",i,j);
		}
	}
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("\nEnter the value of b[%d][%d][%d] : "i,j,k);
				scanf("%d",&b[i][j][k]);
			}
		}
	}
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d",b[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

	getch();
}