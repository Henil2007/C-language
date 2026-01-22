#include <stdio.h>

int main() 
{
    FILE *fp;
    int i=0;
    char name[50];
    printf("\nEnter name : ");
    gets(name);
    
    fp = fopen("w+.txt" , "w+");
    while(name[i] != '\0')
    {
        fputc(name[i],fp);
        i++;
    }
    fclose(fp);
    printf("\nSuccessfully...");
    return 0;
}