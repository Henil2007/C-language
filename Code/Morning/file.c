#include <stdio.h>

int main() 
{
    FILE *fp;
    char name[30];
    fp=fopen("test.txt","w");
    fprintf(fp,"%s","India");
    fclose(fp);
    fp = fopen("test.txt","r");
    fscanf( fp,"%s",name);
    printf("\nThe contant of the file are %s",name);
    fclose(fp);
    return 0;
}