#include <stdio.h>

int main() 
{
    FILE *fp;

    // 1. OpenFile Connection
    fp = fopen("demo.txt" , "w");

    // 2. Operation
    fprintf(fp,"My Name is Henil Patel.");

    // 3. File Connection Close
    fclose(fp);
    
    return 0;
}