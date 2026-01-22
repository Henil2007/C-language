#include <stdio.h>

int main() 
{
    FILE *fp;
    char buff[255];
    int wc=0;
    
    // 1. Open File Connection
    fp = fopen("demo.txt" , "r");

    // 2. Operation
    while((fscanf(fp,"%s",buff)) != EOF)
    {
        wc++;
        printf("%s ",buff);
    }  
    
    // 3. File Connection Close
    fclose(fp);
    printf("\nTotal word count : %d",wc);
    return 0;
}