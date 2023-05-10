#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **addend(char **arr, int len, char *str)
{
    arr = (char **)realloc(arr, (len + 1) * sizeof(char *));
    arr[len] = (char *)malloc(10 * sizeof(char));
    strcpy(arr[len],str);
    return arr;
}
char **addbig(char **arr, int len, char *str)
{
    arr = (char **)realloc(arr, (len + 1) * sizeof(char *));
    arr[len] = (char *)malloc(10 * sizeof(char));
    for (int i = len - 1; i >= 0; i--)
    {
        strcpy(arr[i+1],arr[i]);
    }
    strcpy(arr[0],str);
    return arr;
}
char **del(char **arr, int len, int x)
{
    for (int i = x; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr = (char **)realloc(arr, (len - 1) * sizeof(char *));
    return arr;
}

int main()
{
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);
    char **arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(10 * sizeof(char));
        printf("Enter element %d: ", i + 1);
        scanf("%s", arr[i]);
    }
    while (1)
    {
        printf("1) Add a string to the end of the array\n");
        printf("2) Add a string to the beginning of the array\n");
        printf("3) Delete the element at index 'x' (taken as input) of the arrav\n");
        printf("4) Display the length of the array\n");
        printf("5) Display all the elements of the array in sequence\n");
        printf("6) Exit\n");
        int ch;
        printf("Enter choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            char *str = (char *)malloc(10 * sizeof(char));
            printf("Enter string to be added at end: ");
            scanf("%s",str);
            arr = addend(arr, n, str);
            n += 1;
        }
        else if (ch == 2)
        {
            char *str = (char *)malloc(10 * sizeof(char));
            printf("Enter string to be added at start: ");
            scanf("%s", str);
            arr = addbig(arr, n, str);
            n += 1;
        }
        else if (ch == 3)
        {
            int x;
            printf("Enter index to be deleted : ");
            scanf("%d", &x);
            arr = del(arr, n, x);
            n -= 1;
            printf("Deleted!\n");
        }
        else if (ch == 4)
        {
            printf("The length is : %d\n", n);
        }
        else if (ch == 5)
        {
            printf("Printing elements of the array \n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; *(*(arr + i) + j) != '\0'; j++)
                {
                    printf("%c", *(*(arr + i) + j));
                }
                printf("\n");
            }
        }
        else if (ch == 6)
        {
            printf("Exiting... \n");
            break;
        }
        else
        {
            printf("Please choose a valid option\n");
        }
    }
    return 0;
}