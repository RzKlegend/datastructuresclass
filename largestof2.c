#include<stdio.h>
int main(){
    int a,b,c;
    printf("enter 3 nums");
    scanf("%d %d %d", &a, &b, &c);
    if(a>b>c){
        printf("%d is the greatest", a);
    }
    else if (a<b && b>c){
        printf("%d is greatest",b);
    }
    else if (c>a && c>b){
        printf("%d is the greatest",c);
    }
    else{
        printf("all are equal");
    }
    return 0;
    
}