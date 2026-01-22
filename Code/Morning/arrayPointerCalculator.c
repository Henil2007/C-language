#include<stdio.h>
#include<stdlib.h>>
#define SIZE 5
void main()
{
	int a[SIZE],b[SIZE],c[SIZE];
	int *p,*q,*r;
	int i,choice;
	p=a;
	q=b;
	r=c;
	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter the value of a[%d] : ",i);
		scanf("%d",p+i);
	}//end of for
	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter the value of b[%d] : ",i);
		scanf("%d",q+i);
	}//end of for
	while(1)
	{
		printf("\nEnter Your Choice : ");
		printf("\n1---Addition");
		printf("\n2---Subtraction");
		printf("\n3---Multiplication");
		printf("\n4---Division");
		printf("\n5---Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: for(i=0;i<SIZE;i++)
				{
					*(r+i) = *(p+i) + *(q+i);
				}//end of for
				for(i=0;i<SIZE;i++)
				{
					printf("\n%d",*(r+i));
				}//end of for
			break;
			case 2: for(i=0;i<SIZE;i++)
				{
					*(r+i) = *(p+i) - *(q+i);
				}//end of for
				for(i=0;i<SIZE;i++)
				{
					printf("\n%d",*(r+i));
				}//end of for
			break;
			case 3: for(i=0;i<SIZE;i++)
				{
					*(r+i) = *(p+i) * *(q+i);
				}//end of for
				for(i=0;i<SIZE;i++)
				{
					printf("\n%d",*(r+i));
				}//end of for
			break;
			case 4: for(i=0;i<SIZE;i++)
				{
					*(r+i) = *(p+i) / *(q+i);
				}//end of for
				for(i=0;i<SIZE;i++)
				{
					printf("\n%d",*(r+i));
				}//end of for
			break;
			case 5: exit(0);
			break;
			default:printf("\nInvalid choice...");
		}//end of switch
	}//end of while
}//end of main

