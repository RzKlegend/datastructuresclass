#include<stdio.h>
int main(){
    int arr[100],n,key,i,found = -1;
    int count = 0;

    printf("enter the number of elements:");
    scanf("%d",&n);

    printf("enter the roll nos of the array:");

    for( i = 0 ; i<n ; i++){
        scanf("%d", &arr[i]);
    }

    printf("enter the roll no to search:");
    scanf("%d",&key);
    
    for(i=0;i<n;++i){
        count++;
        if (arr[i]==key){
            found = i;
            break;

        }
    }

    if (found != -1){
        printf("roll no found at index: %d\n ", found);
        }
    else{
            printf("roll no  is not found at all\n ");
        }
    printf("\nthe number of comparisions are: %d",count);
    return 0;
}