#include<stdio.h>

void number_ascending(int n){
    for(int i=1;i<=n;i++)
    {
        printf("%d",i);
    }
}
void spaces(int m){
    for (int i=0; i<m; i++)
    {
        printf(" ");
    }
    
}
void number_decending(int n){
    for(int i=n;i>0;i--)
    {
        printf("%d",i);
    }
}

int main(){
    int n;
    printf("Enter the number :");
    scanf("%d",&n);
    int m=0;
    for(int i=n;i>0;i--){
        m=(n-i);

        number_ascending(i);

        m=m*2;

        spaces(m);

        number_decending(i);
        
        printf("\n");
    }
}