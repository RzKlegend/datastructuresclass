#include<stdio.h>
    void merge (int arr[], int left, int mid, int right){
        int i = low;
        int j= mid + 1;
        int k = 0;
        int temp[high-low+1];

        while(i<=mid && j<=high){
            if(arr[i] <= arr[j]){
                temp[k++] = temp[i++];
            }
            else{
                temp[k++] = temp[j++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }

        while (j <= high){
            temp[k++] = arr[j++];
        }

        for(int i = low,k=0; i<=high ; i++,k++){
            arr[i] = temp[k];
        }
    }
    void mergeSort(int arr[], int low, int high){
        if(low<high){
            int mid  = (low+high)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);

        }
    }
    int main(){
        int n;
        int arr[100];
        printf("enter no of elements");
        scanf("%d",&n);

        printf("enter the array elements");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        mergeSort(arr,0,n-1);

        printf("the sorted array is ");
        for(int i = 0;i <n;i++){
            scanf("%d",&arr[i]);
        }
    }
