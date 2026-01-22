#include <stdio.h>
struct student
{
    int rno;
    char name[20];
    int std;
    int marks;
};
int main() 
{
    struct student s1;
    FILE *fp;
    fp = fopen("info.dat","rb");

    while(fread(&s1,sizeof(struct student),1,fp))
    {
        printf("\n%d\t%s\t%d\t%d",s1.rno,s1.name,s1.std,s1.marks);
    } 
    fclose(fp);
    return 0;
}