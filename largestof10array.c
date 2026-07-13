#include<stdio.h>
int main(){
    int arr[100], i, n;
    printf("enter the number of elements in the array ");
    scanf("%d", &n);

    printf("enter the elements of the array:");
    for(i =0 ; i<n ; i++){
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];

    for(i=0;i<n;i++){
        if (arr[i]>largest){
            largest = arr[i];
            
        }
    }

    printf("largest number  in the array is %d",largest);
    return 0;
}
