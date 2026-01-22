/*
		Revision of For loop
		While loop
		Do While loop
*/
#include<stdio.h>
#include<conio.h>
void whilefun();
void main()
{
	void whilefun();
	clrscr();
	getch();
}
void forfun()
{
	int i,j;
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void whilefun()
{
	int i,j;
	i=0;
	j=0;
	while(i<=5)
	{
		while(j<=i)
		{
			printf("*");
		}
		printf("\n");
	}
}