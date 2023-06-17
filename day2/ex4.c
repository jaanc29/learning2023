#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        if (num & 1)  // Check the least significant bit
            count++;
        num >>= 1;   // Right-shift the number by 1
    }
    return count;
}

int main() {
    int a[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(a) / sizeof(a[0]);

    int totalBits = 0;
    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(a[i]);
    }

    printf("Total number of set bits in the given array is: %d\n", totalBits);

    return 0;
}