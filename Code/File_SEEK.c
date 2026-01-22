#include <stdio.h>

int main() 
{
    FILE *fp;
    int i=0,position=0;
    char name[50],c;
    printf("\nEnter name : ");
    gets(name);
    
    fp = fopen("w+.txt" , "w+");
    while(name[i] != '\0')
    {
        fputc(name[i],fp);
        i++;
    }
    printf("\n--------------------------------------------\n");
    rewind(fp);  // fseek(fp,0,SEEK_SET);
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fseek(fp,8,SEEK_SET);
    fprintf(fp,"C++");
    rewind(fp);
    printf("\n--------------------------------------------\n");
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fseek(fp,8,SEEK_SET);
    fprintf(fp,"Java");
    rewind(fp);
    printf("\n--------------------------------------------\n");
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c",c);
    }
    fseek(fp,0,SEEK_SET);
    // fprintf(fp,"Java");
    position = ftell(fp);
    printf("\nw+.txt file size : %d Bytes.",position);
    // printf("\n--------------------------------------------");
    fclose(fp);    
    return 0;
}