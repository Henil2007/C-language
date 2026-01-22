#include <stdio.h>
#include <stdlib.h>
#define PROSIZE 100
struct product
{
    int id;
    char name[50];
    char ctgr[30];
    int quantity;
    int price;
    int active;
} prolist[PROSIZE];
int procount = 0;

int findIndexById(int id);
void searchproduct();
void addproduct();
void updateproduct();
void deleteproduct();
void printproduct(struct product p);
void displayproduct();

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Add Product");
        printf("\n2. Display Product");
        printf("\n3. Display particular Product");
        printf("\n4. Update Product");
        printf("\n5. Delete Product");
        printf("\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            displayproduct();
            break;
        case 3:
            searchproduct();
            break;
        case 4:
            updateproduct();
            break;
        case 5:
            deleteproduct();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter a valid choice...");
        }
    }

    return 0;
}

int findIndexById(int id)
{
    int i;
    for (i = 0; i < procount; i++)
    {
        if (prolist[i].active == 1 && prolist[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
void searchproduct()
{
    int id, index;
    printf("\nEnter product Id which you want to search : ");
    scanf("%d", &id);
    if (findIndexById(id) == -1)
    {
        printf("\nId is not present in the current product list.");
        return;
    }
    index = findIndexById(id);

    printproduct(prolist[index]);
}
void addproduct()
{
    struct product p;
    int i;
    if (procount >= PROSIZE)
    {
        printf("\nProduct list is full.");
        return;
    }
    printf("\nEnter product Id : ");
    scanf("%d", &p.id);
    if (findIndexById(p.id) != -1)
    {
        printf("\nEntered id alredy exist...");
        return;
    }
    p.active = 1;
    printf("\nEnter product name : ");
    scanf("%s", &p.name);
    printf("\nEnter product category : ");
    scanf("%s", &p.ctgr);
    printf("\nEnter product quantity : ");
    scanf("%d", &p.quantity);
    printf("\nEnter product price : ");
    scanf("%d", &p.price);

    prolist[procount] = p;
    procount++;
}
void updateproduct()
{
    struct product p;
    int id, index;
    printf("\nEnter product Id you want to update : ");
    scanf("%d", &id);
    if (findIndexById(id) == -1)
    {
        printf("\nId no. %d is not present in the current product list.", id);
        return;
    }
    index = findIndexById(id);

    printf("\nEnter product name : ");
    scanf("%s", &prolist[index].name);
    printf("\nEnter product category : ");
    scanf("%s", &prolist[index].ctgr);
    printf("\nEnter product quantity : ");
    scanf("%d", &prolist[index].quantity);
    printf("\nEnter product price : ");
    scanf("%d", &prolist[index].price);

    printf("\nProduct id %d is updated sucessfully.", id);
}
void deleteproduct()
{
    int id, index;
    printf("\nEnter product Id you want to delete : ");
    scanf("%d", &id);
    if (findIndexById(id) == -1)
    {
        printf("\nId is not present in the current product list.");
        return;
    }
    index = findIndexById(id);

    prolist[index].active = 0;
    printf("\nEntered id no. %d is been deleted sucessfully.", id);
}
void printproduct(struct product p)
{
    printf("\nId : %d\nName : %s\nCategory : %s\nQuantity : %d\nPrice : %d", p.id, p.name, p.ctgr, p.quantity, p.price);
    printf("\n------------------------------------------------------");
}
void displayproduct()
{
    int i, flag = 1;
    for (i = 0; i < procount; i++)
    {
        flag = 0;
        printproduct(prolist[i]);
    }
    if (flag)
    {
        printf("\nProduct list is empty...");
    }
}