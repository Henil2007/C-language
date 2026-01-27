/*
An integer N (8 ≤ N ≤ 20)

An integer array of size N

A pointer pointing to the first element of the array

Read N integers into the array using only a pointer and a for loop.

Reverse only the first half of the array in place using:
-> Pointer arithmetic
-> A for loop

If N is odd, exclude the middle element from reversing

Traverse the array using a pointer and a for loop.

For every element that satisfies both conditions:
-> Position is a multiple of 3 (0-based index)
-> Element value is negative

Replace the element with the sum of its immediate neighbors.

Skip the first and last elements to avoid invalid memory access.

Move the pointer to the last element of the array.

Traverse the array backwards using a for loop and pointers:
-> Replace each element with the difference between itself and the previous element

Display the final array using only pointers and a for loop.

Constraints :
-Only one array
-Only one pointer variable
-No extra arrays
-No while loops
-No array indexing ( arr[i] ) after declaration
-Do not modify N
*/

#include <stdio.h>

int main()
{
    int N;
    printf("Enter size of an array : ");
    scanf("%d", &N);
    int arr[N];
    int *ptr = arr;
    for (int i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", ptr + i);
    }
    ptr = arr;
    int half = N / 2;
    for (int i = 0; i < half; i++)
    {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + (N - 1 - i));
        *(ptr + (N - 1 - i)) = temp;
    }
    ptr = arr;
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0 && *(ptr + i) < 0)
        {
            if (i > 0 && i < N - 1)
            {
                *(ptr + i) = *(ptr + (i - 1)) + *(ptr + (i + 1));
            } // End of inner if
        } // End of outer if
    } // End of for loop
    ptr = arr + N - 1;
    for (int j = N - 1; j >= 0; j--)
    {
        if (j == N - 1)
        {
            continue;
        }
        else
        {
            *(ptr - j) = *(ptr - j) - *(ptr - (j + 1));
        }
    }
    ptr = arr;
    for (int k = 0; k < N; k++)
    {
        printf("%d ", *(ptr + k));
    }

    return 0;
}