#include<stdio.h>

int difference(int arr[],int length){
    int even=0;
    int odd=0;
    for(int i=0;i<length;i++){
        if(i%2==0){
            even=even+arr[i];
        }
        else{
            odd=odd+arr[i];
        }
    }
    int diff=0;
    if(even>=odd){
        diff=even-odd;
    }
    else{
        diff=odd-even;
    }
    return diff;
}

int main()
{
    int length;
    printf("Enter the length of array :");
    scanf("%d",&length);
    int arr[length];
    printf("Enter the number in array :\n");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    int diff=difference(arr,length);

    printf("\nthe difference in even and odd is :%d",diff);
    return 0;
}