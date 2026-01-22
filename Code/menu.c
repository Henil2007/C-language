#include<stdio.h>
int main()
{
    int a,b,c,choice;
    printf("Enter number a : ");
    scanf("%d",&a);
    printf("Enter number b : ");
    scanf("%d",&b);

    printf("The choice are given below.");
    printf("\n1) For Addition");
    printf("\n2) For Substraction");
    printf("\n3) For Multiplication");
    printf("\n4) For Division");
    printf("\n5) Exit\n\n\tEnter the choice given above : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1 : c = a + b;
                    printf("Addition is : %d",c);
                    break;
        case 2 : c = a - b;
                    printf("Substraction is : %d",c);
                    break;
        case 3 : c = a * b;
                    printf("Multiplication is : %d",c);
                    break;
        case 4 : c = a / b;
                    printf("Division is : %d",c);
                    break;
        default:
                        printf("Please enter a valid choice ...");
    }
	return 0;
}
