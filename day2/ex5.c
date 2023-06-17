#include <stdio.h>

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main() {
    int a1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(a1) / sizeof(a1[0]);

    printf("Original array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");

    swapAlternate(a1, size1);

    printf("Modified array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n\n");

    int a2[] = {10, 20, 30, 40, 50, 60};
    int size2 = sizeof(a2) / sizeof(a2[0]);

    printf("Original array: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", a2[i]);
    }
    printf("\n");

    swapAlternate(a2, size2);

    printf("Modified array: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", a2[i]);
    }
    printf("\n");

    return 0;
}