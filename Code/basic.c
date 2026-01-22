#include <stdio.h>

int main() 
{
    int a,b,c,choice;
    printf("Enter number a : ");
    scanf("%d",&a);
    printf("Enter number b : ");
    scanf("%d",&b);

    printf("\n1. For Addition");
    printf("\n2. For Substraction");
    printf("\n3. For Multiplication");
    printf("\n4. For Division");
    printf("\nEnter the choice : ");
    scanf("%d",&choice);

    if (choice == 1)
    {
        c = a + b;
        printf("\nAddition is : %d",c);
    }
    else if (choice == 2)
    {
        c = a - b;
        printf("\nSubstration is  : %d",c);
    }
    else if (choice == 3)
    {
        c = a * b;
        printf("Multiplication is : %d",c);
    }
    else if (choice == 4)
    {
        if (b == 0)
        {
            printf("\nUndefined");
        }
        else
        {
            c = a / b;
            printf("\nDivision is : %d",c);
        }
    }
    else
    {
        printf("\nEnter a valid choice...");
    }
    
    return 0;
}