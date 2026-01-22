/*
		printing rectangular pattern
		using for loop
		while loop
		do while loop
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j;
	clrscr();
	for(i=0;i<5;i++)
	{
		printf("\n");
		for(j=0;j<=10;j++)
		{
			if(j%2 == 0)
			{
				printf("*");
			}
			else
			{
				printf("#");
			}
		}
	}
	getch();
}