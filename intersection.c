#include <stdio.h>

int main()
{
    int a1[20], a2[20], u[40], i, j, k = 0, n, m;
    printf("Enter size of first array:");
    scanf("%d", &n);
    printf("Enter elements of first array in ascending order:\n");
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a1[i]);
    }
    printf("\nEnter size of second array:");
    scanf("%d", &m);
    printf("Enter elements of second array in ascending order:\n");
    for (i = 0; i < m; ++i)
    {
        scanf("%d", &a2[i]);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a1[i] == a2[j])
            {
                u[k] = a1[i];
                k++;
            }
        }
    }
    printf("\nIntersection of two arrays is:\n");
    for (i = 0; i < k; ++i)
    {
        printf("%d ", u[i]);
    }
    return 0;
}