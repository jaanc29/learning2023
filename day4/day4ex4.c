#include<stdio.h>

int evensum(int arr[],int length){
    int temp=0;
    for(int i=0;i<length;i++){
        if(arr[i]%2==0){
            temp=temp+arr[i];
        }
    }
    return temp;
}

int oddsum(int arr[],int length){
    int temp=0;
    for(int i=1;i<length;i++){
       if(arr[i]%2!=0){
            temp=temp+arr[i];
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
    int even=evensum(arr,length);

    int odd=oddsum(arr,length);

    int diff=0;
    if(even>=odd){
        diff=even-odd;
    }
    else{
        diff=odd-even;
    }

    printf("\nthe difference in even and odd is :%d",diff);
    return 0;
}