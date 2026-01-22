#include <stdio.h>

int main() 
{
    FILE *fp1,*fp2;
    int num,i;

    fp1 = fopen("even.txt","w");
    fp2 = fopen("odd.txt","w");
    for(i=1;i<=10;i++)
    {
        printf("ENter the number : ");
        scanf("%d",&num);
        if(num%2==0)
        {
            putw(num,fp1);
        }
        else
        {
            putw(num,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fp1 = fopen("even.txt","r");
    fp2 = fopen("odd.txt","r");
    printf("This are the set of even number : \n");
    while ((num=getw(fp1))!=EOF)
    {
        printf("%d",num);
    }
    printf("\nThis are the set of odd number : \n");
    while ((num=getw(fp2))!=EOF)
    {
        printf("%d",num);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}