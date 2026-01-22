#include <stdio.h>

int main() 
{
    FILE *fp;
    char name[30];
    char fileName[30];
    char str[30];
    printf("Enter the file name you want to create : ");
    scanf("%s",fileName);
    fp=fopen(fileName,"w");
    printf("\nEnter the content : ");
    scanf("%s",str);
    fprintf(fp,"%s",str);
    fclose(fp);
    fp = fopen(fileName,"r");
    fscanf( fp,"%s",name);
    printf("\nThe contant of the file are %s",name);
    fclose(fp);
    return 0;
}