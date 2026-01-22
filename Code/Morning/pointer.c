#include <stdio.h>

int main() 
{
    int a=10,b=20,*ptr,*ptr1;
    char ch = 'A',*cha;
    float c=20.32,d=50.62;

    *ptr = a;
    printf("Value of a using pointer is : %u",ptr);
    *ptr1 = b;
    printf("\nValue of b using pointer is : %u",ptr);
    *cha = ch;
    printf("\nValue of ch using pointer is : %u",ptr);
    return 0;
}