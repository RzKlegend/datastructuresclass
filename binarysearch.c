#include <stdio.h>

int main() 
{
    int arr[100], n, key;
    int low, high, mid;
    int found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    
    low = 0;         
    high = n - 1;

    
    while (low <= high) 
    {
        mid = (low + high) / 2;

        if (arr[mid] == key) 
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } 
        else if (key < arr[mid]) 
        {
            high = mid - 1; // Element is in the left half
        } 
        else 
        {
            low = mid + 1;  // Element is in the right half
        }
    }

    if (found == 0) 
    {
        printf("Element not found\n");
    }

    return 0;
}