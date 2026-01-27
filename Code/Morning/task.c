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