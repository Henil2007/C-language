#include<stdio.h>
#define BOOKSIZE 100
struct book
{
    int id,quantity,price;
    char title[50],author[50];
    int active;
}booklist[BOOKSIZE];
int bookcount = 0;
void printbook(struct book b);
                
int login()
{
    int attempt = 0;
    char username[20],password[20];
    while(1)
    {
        printf("\nEnter user name : ");
        scanf("%s",&username);
        printf("\nEnter Password : ");
        scanf("%s",&password);
        if((strcmp(username,"admin") == 0) && (strcmp(password,"123") == 0))
        {
            return 1;
        }
        else
        {
            attempt++;
            if(strcmp(username,"admin") != 0)
            {
                if((strcmp(password,"admin123") != 0))
                {
                    printf("\nWrong user name and password");
                }
                else
                {
                   printf("Wrong User name"); 
                } 
            }
            else
            {
                printf("Wrong Password");
            }
            printf("\nLogin attempt remaning : %d",(3-attempt));
        }
        if(attempt == 3)
        {
            printf("\nInsufficient attempt : %d\n\tlogin fail...!",attempt);
            return(0);
        }
    }
}
int findIndexById(int id)
{
    int i;
    for(i=0;i<bookcount;i++)
    {
        if(booklist[i].active == 1 && booklist[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
void searchbookid()
{
    int id,index;
    printf("\nEnter Book Id which you want to search : ");
    scanf("%d",&id);
    if(findIndexById(id) == -1)
    {
        printf("\nId is not present in the current book list.");
        return;
    }
    index = findIndexById(id);

    printbook(booklist[index]);
}
void searchbookbytitle()
{
    int id,index;
    printf("\nEnter Book title which you want to search : ");
    scanf("%d",&id);
    if(findIndexById(id) == -1)
    {
        printf("\nBook title is not present in the current book list.");
        return;
    }
    index = findIndexById(id);

    printbook(booklist[index]);
}
void addbook()
{
    struct book b;
    int i;
    if(bookcount >= BOOKSIZE)
    {
        printf("\nBook list is full.");
        return;
    }
    printf("\nEnter Book Id : ");
    scanf("%d",&b.id);
    if(findIndexById(b.id) != -1)
    {
        printf("\nEntered id alredy exist...");
        return;
    }
    b.active = 1;
    printf("\nEnter book Title : ");
    scanf("%s",&b.title);
    printf("\nEnter Book Author : ");
    scanf("%s",&b.author);
    printf("\nEnter book quantity : ");
    scanf("%d",&b.quantity);
    printf("\nEnter book price : ");
    scanf("%d",&b.price);

    booklist[bookcount] = b;
    bookcount++;
}
void deletebook()
{
    int id,index;
    printf("\nEnter book Id you want to delete : ");
    scanf("%d",&id);
    if(findIndexById(id) == -1)
    {
        printf("\nId is not present in the current book list.");
        return;
    }
    index = findIndexById(id);
    
    booklist[index].active = 0;
    printf("\nEntered id no. %d is been deleted sucessfully.",id);
}
void sortbookbyid()
{
     int i,j;
    struct book temp;
    for(i=0;i<bookcount;i++)
    {
        for(j=(i+1);j<bookcount;j++)
        {
            if(booklist[i].id > booklist[j].id)
            {
                temp = booklist[i];
                booklist[i] = booklist[j];
                booklist[j] = temp;
            }
        }
    }
    printf("\nBook List sorted by Id.");
}
void printbook(struct book b)
{
    printf("\nBook Id : %d\nTitle : %s\nAuthor : %s\nQuantity : %d\nPrice : %d",b.id,b.title,b.author,b.quantity,b.price);
    printf("\n------------------------------------------------------");
}
void displaybook()
{
    int i,flag = 1;
    for(i=0;i<bookcount;i++)
    {
        if(booklist[i].active == 1)
        {
            flag = 0;
            printbook(booklist[i]);
        }
    }
    if(flag)
    {
        printf("\nBook list is empty...");
    }
}
void issuebook()
{
    int id, i, found = 0;
    if (bookcount == 0)
    {
	    printf("\nNo books available to issue!");
	    return;
    }
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (i = 0; i < bookcount; i++)
    {
	    if (booklist[i].id == id && booklist[i].active == 1)
	    {
	        found = 1;
	        if (booklist[i].quantity > 0)
	        {
		        booklist[i].quantity--;
		        printf("\nBook Issued Successfully!");
		        printf("\nRemaining Quantity: %d", booklist[i].quantity);
	        }
	        else
	        {
		        printf("\nBook not available (Out of Stock)!");
	        }
	        break;
	    }
    }

    if (!found)
	printf("\nBook not found!");
}
void returnbook()
{
    int id, i, found = 0;
    if (bookcount == 0)
    {
	    printf("\nNo books in library to return!");
	    return;
    }
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (i = 0; i < bookcount; i++)
    {
	    if (booklist[i].id == id && booklist[i].active == 1)
	    {
	        booklist[i].quantity++;
	        printf("\nBook Returned Successfully!");
	        printf("\nUpdated Quantity: %d", booklist[i].quantity);
	        found = 1;
	        break;
	    }
    }
    if (!found)
	printf("\nBook not found or inactive!");
}
int main()
{
    int choice;
    if(login())
    {
        do
        {
            printf("\n===== LIBRARY MANAGEMENT SYSTEM =====");
            printf("\n1.Add Book");
            printf("\n2. Display All Books");
            printf("\n3. Search Book by Id");
            printf("\n4. Search Book by title");
            printf("\n5. Delete Book");
            printf("\n6. Sorting by Id");
            printf("\n7. Issue Book");
            printf("\n8. Return book");
            printf("\n9. Exit the program");
            printf("\nEnter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1 : addbook();
                         break;
                case 2 : displaybook();
                         break;
                case 3 : searchbookid();
                         break;
                case 4 : searchbookbytitle();
                         break;
                case 5 : deletebook();
                         break;
                case 6 : sortbookbyid();
                         break;
                case 7 : issuebook();
                         break;
                case 8 : returnbook();
                         break;
                default : printf("\nExicting program...");
            }
        }while(choice != 9);
    }
    return 0;
}