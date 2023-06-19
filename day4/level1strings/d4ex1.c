#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ToggleCase(char str[], int length){
    for(int i=0;i<length;i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }
        else if(str[i]>=97 && str[i]<=122){
            str[i]-=32;
        }
    }
    printf("\nToggled String :%s",str);
}

int main(){
    int length;
    printf("Enter the length of string :");
    scanf("%d",&length);
    char str[length];
    printf("\nEnter the string :");
    scanf("%s",str);
    printf("\nEntered String :%s",str);
    ToggleCase(str,length);
}