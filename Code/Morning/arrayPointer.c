#include<stdio.h>

int main()
{
    int a[5],*y,i;
    y = a;
    for(i=0;i<5;i++)
    {
        printf("\nEnter the value of a[%d] : ",i);
        scanf("%d",y+i);
    }
    for(i=0;i<5;i++)
    {
        printf("\n%d--------%u",*(y+i),y+i);
    }
    
    float b[5],*f;
    f = b;
    for(i=0;i<5;i++)
    {
        printf("\nEnter the value of b[%d] : ",i);
        scanf("%f",f+i);
    }
    for(i=0;i<5;i++)
    {
        printf("\n%f--------%u",*(f+i),f+i);
    }

    char ch[5];
    char *c;
    c = ch;
    for(i=0;i<5;i++)
    {
        printf("\nEnter the value of ch[%d] : ",i);
        scanf("%d",c+i);
    }
    for(i=0;i<5;i++)
    {
        printf("\n%d--------%u",*(c+i),c+i);
    }
    return 0;
}