#include <stdio.h>
int main()
{
    int arr[10], i, element;
    printf("Enter 5 Array Elements: ");
    for (i = 0; i < 5; i++)
        scanf("%d", &arr[i]);
    printf("Enter Element to Insert: ");
    scanf("%d", &element);
    arr[i] = element;
    printf("The New Array is:");
    for (i = 0; i < 6; i++)
        printf("%d  ", arr[i]);
    return 0;
}