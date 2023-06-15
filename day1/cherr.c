#include <stdio.h>

int bit_operations(int num, int oper_type) {
    if (oper_type == 1) {
        // Set 1st bit
        num |= 1;
    } else if (oper_type == 2) {
        // Clear 31st bit
        num &= ~(1 << 31);
    } else if (oper_type == 3) {
        // Toggle 16th bit
        num ^= (1 << 16);
    }

    return num;
}

int main() {
    int num = 123456789;  // Example input number
    int oper_type = 3;    // Example operation type (1, 2, or 3)
    int result = bit_operations(num, oper_type);

    printf("Result: %d\n", result);

    return 0;
}