#include <stdio.h>
int main()
{
    int x;
    printf("Enter the Array size :");
    scanf("%d", &x);
    int A[x], y;
    for (y = 0; y < x; y++)
    {
        scanf("%d", &A[y]);
    }
    for (y = 0; y < x; y++)
    {
        printf("%d", A[y]);
    }
    return 0;
}