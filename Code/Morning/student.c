#include <stdio.h>
#include<stdlib.h>
#define SIZE 3
struct student
{
    int sid , fees;
    char name[20];
}s[SIZE];

void addStudent()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("Enter Student ID : ");
        scanf("%d",&s[i].sid);
        printf("Enter student name : ");
        scanf("%s",&s[i].name);
        printf("Enter student fees : ");
        scanf("%d",&s[i].fees);
    }
}

void displayStudent()
{
    int i;
    printf("SID\tName\tFeesn");
    printf("\n----------------------\n");
    for ( i = 0; i < SIZE; i++)
    {
        printf("%d\t%s\t%d\n",s[i].sid,s[i].name,s[i].fees);
    }
    
}

int main() 
{
    int choice;
    while (1)
    {
        printf("\n==============Index==============");
        printf("\n1. Add student details");
        printf("\n2. Display student Details");
        printf("\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: addStudent();
                break;
        case 2: displayStudent();
                break;
        case 3: exit(0);
        default: printf("Enter a valid choice...");
            break;
        }
    }
    
    return 0;
}

