#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//using general approach
int convert(char str[],int length){
    int number=0;
    int temp=0;
    for (int i = 0; i < length; i++)
    {
        temp=(int)str[i]-48;
        number=number*10;
        number=number+temp;
    }
    return number;
}

//using atoi function
int convertatoi(char str[]){
    int number=atoi(str);
    return number;
}

int main(){
    int length;
    printf("Enter the length of string :");
    scanf("%d",&length);
    char str[length];
    printf("\nEnter the string :");
    scanf("%s",str);
    printf("\nEntered String :%s",str);
    int number=convert(str,length);
    int num=convertatoi(str);
    printf("\nString Converted to number with help of general method :%d",number);
    printf("\nString Converted to number with help of atoi function method :%d",number);
}