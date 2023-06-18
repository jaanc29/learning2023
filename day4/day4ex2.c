#include<stdio.h>
#include <limits.h>

int minimum(int arr[],int length){
    int temp=INT_MAX;
    for(int i=0;i<length;i++){
        if(temp>arr[i]){
            temp=arr[i];
        }
    }
    return temp;
}

int maximum(int arr[],int length){
    int temp=INT_MIN;
    for(int i=0;i<length;i++){
        if(temp<arr[i]){
            temp=arr[i];
        }
    }
    return temp;
}

int main(){
    int length;
    printf("Enter the length of array :");
    scanf("%d",&length);
    int arr[length];
    printf("Enter the number in array :\n");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    int min=minimum(arr,length);
    printf("minimum digit of array is : %d\n",min);

    int max=maximum(arr,length);
    printf("maximum digit of array is : %d\n",max);
    return 0;
}