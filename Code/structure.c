#include<stdio.h>
struct student
{
    int sid;
    char name[30];
    float fees;
}s1,s2;
void scandetails();
void displaydetails();
void main()
{
    int choice;
    while(1)
    {
        printf("\n1--------- Scan");
        printf("\n2--------- Display");
        printf("\n3--------- Exit ");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : scandetails();
                        break;
            case 2 : displaydetails();
                        break;
            case 3 : exit(0);
        }
    }
}
void scandetails()
{
    float temp;
    printf("Enter student id : ");
    scanf("%d",&s1.sid);
    printf("Enter student name : ");
    scanf("%s",&s1.name);
    printf("Enter fees : ");
    scanf("%f",&temp);
    s1.fees = temp;

    printf("Enter student id : ");
    scanf("%d",&s2.sid);
    printf("Enter student name : ");
    scanf("%s",&s2.name);
    printf("Enter fees : ");
    scanf("%f",&temp);
    s2.fees = temp;
}
void displaydetails()
{
    printf("\nsid\tname\tfees");
    printf("\n%d\t%s\t%.2f",s1.sid,s1.name,s1.fees);
    printf("\n%d\t%s\t%.2f",s2.sid,s2.name,s2.fees);
}
