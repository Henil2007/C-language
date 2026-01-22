/*
			Name : Henil Patel
			D.O.C : 24/12/2025
			Topic : TO create a program to find length of a string
				concate 2 string and compare two string without
				using string built function.
*/
#include<stdio.h>
#include<conio.h>

void main()
{
	char str1[20];
	char str2[20];
	char str3[20];
	int i,len=0,j=0;
	clrscr();
	printf("Enter string 1 : ");
	gets(str1);
	printf("Enter string 2 : ");
	gets(str2);

	for(i=0;str1[i]!='\0';i++)
	{
		len++;
	}
	printf("\nLength of %s is %d",str1,len);
	for(i=len-1;i>=0;i--)
	{
		str3[j] = str1[i];
		j++;
	}
	str3[j] = '\0';
	printf("\nReverse of %s is %s",str1,str3);

	j=0;

	getch();
}