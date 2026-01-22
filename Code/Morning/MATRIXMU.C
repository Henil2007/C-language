#include<stdio.h>
#include<conio.h>
void main()
{
	int a[3][3],b[3][3],c[3][3];
	int i,j,k;
	clrscr();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}// End of inner for
	}//	End of Outer for
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter b[%d][%d] : ",i,j);
			scanf("%d",&b[i][j]);
		}//	End of Inner for
	}//	End of Outer for
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j] = 0;
		}// End of inner for
	}// End of outer for
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}// End of inner i for loop
		}// End of inner j loop
	}// End of outer for loop

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",c[i][j]);
		}// End of inner for loop
		printf("\n");
	}// End of Outer loop

	getch();
}// End of main()