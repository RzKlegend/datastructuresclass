/*Problem 1: 905. Sort Array By Parity
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.
*/

#include <stdio.h>

int main() {
    int nums[100], n, i;
    int left = 0, right;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    right = n - 1;

    while (left < right) {
        if (nums[left] % 2 == 0) {
            left++;
        } else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right--;
        }
    }

    printf("\nArray after moving even numbers before odd numbers:\n");
    for (i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}
