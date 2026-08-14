#include <stdio.h> 

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid; 
    int L[n1], R[n2]; 

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; 
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; 
    }

    int i = 0, j = 0, k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    } 

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    } 

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    } 
} 

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right); 

        merge(arr, left, mid, right); 
    } 
} 

int* sortArray(int* nums, int numsSize, int* returnSize) {
    mergeSort(nums, 0, numsSize - 1); 

    *returnSize = numsSize;
    return nums; 
} 

int main() {
    int nums[] = {5, 2, 3, 1};
    int size = 4;
    int returnSize; 

    sortArray(nums, size, &returnSize); 
    printf("Sorted Array: "); 

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", nums[i]); 
    } 
    printf("\n");

    return 0; 
}