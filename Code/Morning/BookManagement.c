#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 10

struct Book
{
    int bookId;
    char title[40];
    char author[30];
    float price;
    int issuedCount;
};

int findBookIndex(struct Book b[], int count, int id);
void addBook(struct Book b[], int *count);
void issueBook(struct Book b[], int count);
void returnBook(struct Book b[], int count);
void displayBooks(struct Book b[], int count);
void mostIssuedBook(struct Book b[], int count);
void deleteBook(struct Book b[], int *count);

int main()
{
    struct Book books[MAX];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Library Menu ---\n");
        printf("1. Add a new book\n");
        printf("2. Issue a book\n");
        printf("3. Return a book\n");
        printf("4. Display all books\n");
        printf("5. Display most issued book\n");
        printf("6. Delete a book by ID\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(books, &count);
            break;
        case 2:
            issueBook(books, count);
            break;
        case 3:
            returnBook(books, count);
            break;
        case 4:
            displayBooks(books, count);
            break;
        case 5:
            mostIssuedBook(books, count);
            break;
        case 6:
            deleteBook(books, &count);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return 0;
}

int findBookIndex(struct Book b[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (b[i].bookId == id)
            return i;
    }
    return -1;
}

void addBook(struct Book b[], int *count)
{
    if (*count == MAX)
    {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    int id;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    if (findBookIndex(b, *count, id) != -1)
    {
        printf("Book ID must be unique.\n");
        return;
    }

    b[*count].bookId = id;

    printf("Enter Title: ");
    scanf(" %[^\ns]", b[*count].title);

    printf("Enter Author: ");
    scanf(" %[^\ns]", b[*count].author);

    do
    {
        printf("Enter Price (>0): ");
        scanf("%f", &b[*count].price);
        if (b[*count].price <= 0)
            printf("Invalid price. Try again.\n");
    } while (b[*count].price <= 0);

    b[*count].issuedCount = 0;
    (*count)++;

    printf("Book added successfully.\n");
}

void issueBook(struct Book b[], int count)
{
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    int index = findBookIndex(b, count, id);
    if (index == -1)
    {
        printf("Invalid Book ID\n");
        return;
    }

    b[index].issuedCount++;
    printf("Book issued successfully.\n");
}

void returnBook(struct Book b[], int count)
{
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    int index = findBookIndex(b, count, id);
    if (index == -1)
    {
        printf("Invalid Book ID\n");
        return;
    }

    if (b[index].issuedCount == 0)
    {
        printf("Book was not issued\n");
    }
    else
    {
        b[index].issuedCount--;
        printf("Book returned successfully.\n");
    }
}

void displayBooks(struct Book b[], int count)
{
    if (count == 0)
    {
        printf("Library is empty\n");
        return;
    }

    printf("\nID\tTitle\t\tAuthor\t\tPrice\tIssuedCount\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t%-15s %-15s %.2f\t%d\n",
               b[i].bookId,
               b[i].title,
               b[i].author,
               b[i].price,
               b[i].issuedCount);
    }
}

void mostIssuedBook(struct Book b[], int count)
{
    if (count == 0)
    {
        printf("Library is empty\n");
        return;
    }

    int maxIndex = 0;
    for (int i = 1; i < count; i++)
    {
        if (b[i].issuedCount > b[maxIndex].issuedCount)
            maxIndex = i;
    }

    if (b[maxIndex].issuedCount == 0)
    {
        printf("No book has been issued yet\n");
        return;
    }

    printf("\nMost Issued Book:\n");
    printf("ID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\nIssued Count: %d\n",
           b[maxIndex].bookId,
           b[maxIndex].title,
           b[maxIndex].author,
           b[maxIndex].price,
           b[maxIndex].issuedCount);
}

void deleteBook(struct Book b[], int *count)
{
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    int index = findBookIndex(b, *count, id);
    if (index == -1)
    {
        printf("Book ID not found\n");
        return;
    }

    for (int i = index; i < *count - 1; i++)
    {
        b[i] = b[i + 1];
    }

    (*count)--;
    printf("Book deleted successfully.\n");
}
