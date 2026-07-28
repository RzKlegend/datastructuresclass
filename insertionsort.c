#include <stdio.h>

int main() {
    int arr[100], n, i, j, key;
    int comparisons = 0, shifts = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        if (j >= 0)
            comparisons++;
        arr[j + 1] = key;
    }

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal comparisons: %d", comparisons);
    printf("\nTotal shifts: %d\n", shifts);

    return 0;
}
