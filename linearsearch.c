#include<stdio.h>
int main(){
    int arr[100],n,key,i,found = -1;

    printf("enter the number of elements:");
    scanf("%d",&n);

    printf("enter the elements of the array:");

    for( i = 0 ; i<n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("enter the element to search:");
    scanf("%d",&key);
    
    for(i=0;i<n;++i){
        if (arr[i]==key){
            found = i;
            break;
        }
    }

    if (found != -1){
        printf("element found at index: %d", found);
        }
    else{
            printf("element  is not found at all");
        }
    
    return 0;
}