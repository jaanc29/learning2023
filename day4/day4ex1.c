#include<stdio.h>

int sumof(int arr[],int length){
    int temp=0;
    for(int i=0;i<length;i++){
        temp=temp+arr[i];
    }
    return temp;
}

int averageof(int sum,int length){
    int temp=sum/length;
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
    int sum=sumof(arr,length);
    printf("Sum of array is : %d\n",sum);

    int average=averageof(sum,length);
    printf("Average of array is : %d\n",average);
    return 0;
}