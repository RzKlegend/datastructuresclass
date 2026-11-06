/*75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
*/

#include <stdio.h>

int main() {
    int nums[100], n, i;
    int low = 0, mid = 0, high;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array (only 0, 1, 2):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }

    printf("\nSorted array (0-Red, 1-White, 2-Blue):\n");
    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
