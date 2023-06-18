#include<stdio.h>


int main(){
    int length;
    printf("Enter the length of array :");
    scanf("%d",&length);
    int arr[length];
    printf("Enter the number in array :\n");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array :\n");
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    int mid=0;
    if(length%2==0){
        mid=length/2;
    }
    else{
        mid=(length+1)/2;
    }
    for(int i=0,j=length-1;i<mid;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("\nReverse array :\n");
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}