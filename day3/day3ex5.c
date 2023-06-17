#include<stdio.h>

void largestnumber(int n){
    int temp=0;
    int max=0;
    while(n!=0){
        temp=n%10;
        if(temp>max){
            max=temp;
        }
        n=n/10;
    }
    printf("The largest digit in number is %d",max);
}

void smallestnumber(int n){
    int temp=0;
    int min=9999999;
    while(n!=0){
        temp=n%10;
        if(temp<min){
            min=temp;
        }
        n=n/10;
    }
    printf("The largest digit in number is %d",min);
}

int main(){
    int number;
    printf("Enter the number :");
    scanf("%d",&number);
    largestnumber(number);
    printf("\n");
    smallestnumber(number);
}