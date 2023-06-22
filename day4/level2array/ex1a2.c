#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int getTotalDays(char str[], int arr[]) {
    int days = atoi(str);
    int months = atoi(str + 3);
    int years = atoi(str + 6);
    int totalDays = arr[months - 1];
    totalDays += days;
    
    if (isLeapYear(years) && months > 2)
        totalDays++;
    
    return totalDays;
}

int main() {
    char str[10];
    printf("Enter the date in dd/mm/yyyy format: ");
    scanf("%s", str);
    int arr[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int totalDays = 0;
    int months = atoi(str + 3);
    
    if (months > 12) {
        printf("Enter a valid month.\n");
    } else {
        totalDays = getTotalDays(str, arr);
        printf("Total days: %d\n", totalDays);
    }

    return 0;
}
