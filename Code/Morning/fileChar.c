#include <stdio.h>

int main() 
{
    FILE *fp;
    char ch;
    fp = fopen("t1.txt","w");
    while (ch = getchar()!='\n')
    {
        putc(ch,fp);
    }
    fclose(fp);
    fp = fopen("t1.txt","r");
    printf("\nThe content of the file are : ");
    while ((ch=getc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    fclose(fp);
    return 0;
}