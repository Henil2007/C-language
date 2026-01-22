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
    struct student s[] = {
                            {1,"Henil",10,90},
                            {2,"Devansh",10,80},
                            {3,"Daksh",10,85}
                        };
    FILE *fp;
    fp = fopen("info.dat","wb");
    fwrite(&s,sizeof(struct student),3,fp);

    fclose(fp);
    printf("\nSuccess");
    return 0;
}