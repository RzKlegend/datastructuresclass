#include<stdio.h>
    void swap (int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int partition (int arr[], int low, int high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j<= high - 1; j++){
            if (arr[j] < pivot){
                i++;
                swap(&arr[i],&arr[j]);
            }
        }
        i++;
        swap(&arr[i],&arr[high]);
        return i;
    }

    void quickSort(int arr[],int low,int high){
        if (low < high){
            int pivotIndex = partition(arr,low,high);
            quickSort(arr,low, pivotIndex -1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    void display(int arr[], int n){
        for(int i = 0; i<n ; i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }

    int main(){
        int n;
        printf("enter number of elements in the array");
        scanf("%d",&n);
        int arr[n];
        printf("enter the elements of the array:");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        quickSort(arr,0,n-1);
        printf("Sorted array is:\n");
        display(arr,n);
    }