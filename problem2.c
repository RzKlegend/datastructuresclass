#include <stdio.h>

int main() {
    int n, target;

    printf("enter the no of elements in the array: ");
    scanf("%d", &n);

    int products[n];

    printf("enter the product IDS (in sorted order): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &products[i]);
    }

    printf("enter the product ID to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid;
    int found = 0, comparisons = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;
        comparisons++;

        if (products[mid] == target) {
            found = 1;
            break;
        } else if (products[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (found) {
        printf("\nProduct ID %d found at index %d (Position %d).\n", target, mid, mid + 1);
    } else {
        printf("\nProduct ID %d not found in inventory.\n", target);
    }

    printf("Total comparisons performed: %d\n", comparisons);

    return 0;
}
