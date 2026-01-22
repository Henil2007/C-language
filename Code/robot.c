#include<stdio.h>
#define ROBOSIZE 100
struct robot
{
    int id,battery;
    char name[20],type[20],task[50],status[50];
}robolist[ROBOSIZE] , r;
robocount = 0;
int findIndexById(int id)
{
    int i;
    for(i=0;i<robocount;i++)
    {
        if(robocountlist[i].active == 1 && robolist[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
void 
void addrobot()
{
    if(robocount >= ROBOSIZE)
    {
        printf("\nRobot list is full.");
        return;
    }
    printf("\nEnter robot Id : ");
    scanf("%d",&r.id);
    if(findIndexById(r.id) != -1)
    {
        printf("\nId alredy exist...");
        return;
    }
    r.active = 1;
    printf("Enter Robot name : ");
    scanf("%s",&r.name);
    printf("Enter robot type (humanoid / Industrial / Service) : ");
    scanf("%s",&r.type);
    printf("Enter RObot task : ");
    scanf("%s",&r.task);
    printf("ENter battery level (in percentage) : ");
    scanf("%d",&r.battery);
    printf("Enter robot status (Active / Charging / Idel) : ");
    scanf("%s",&r.status);

    robolist[robocount] = r;
    robocount++;
}
int main()
{
    int choice;
    do
    {
        printf("\n1. Add Robot");
        printf("\n2. Display Robots");
        printf("\n3. search Robot by Id");
        printf("\n4. delete robot");
        printf("\n5. update robot");
        printf("\n6. Exit the program");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1 : addrobot();
                     break;
            case 2 : displayrobot();
                     break;
            case 3 : searchrobot();
                     break;
            case 4 : deleterobot();
                     break;
            case 5 : updaterobot();
                     break;
            default : printf("Exiting the program...");
        }
    }while(choice != 5);
    return 0;
}