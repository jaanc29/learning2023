#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

typedef struct Complex number;

number readComplex() {
    struct Complex c;
    printf("Enter real part: ");
    scanf("%lf", &c.real);
    printf("Enter imaginary part: ");
    scanf("%lf", &c.imaginary);
    return c;
}

void writeComplex(number com) {
    printf("Complex number: %.2lf + %.2lfi\n", com.real, com.imaginary);
}

number addComplex(number com1, number com2) {
    number result;
    result.real = com1.real + com2.real;
    result.imaginary = com1.imaginary + com2.imaginary;
    return result;
}

number multiplyComplex(number com1, number com2) {
    number result;
    result.real = com1.real * com2.real - com1.imaginary * com2.imaginary;
    result.imaginary = com1.real * com2.imaginary + com1.imaginary * com2.real;
    return result;
}

int main() {
    number num1, num2, addition, multiply;

    printf("Enter the first complex number:\n");
    num1 = readComplex();

    printf("Enter the second complex number:\n");
    num2 = readComplex();

    addition = addComplex(num1, num2);
    multiply = multiplyComplex(num1, num2);

    printf("Sum of the complex numbers:\n");
    writeComplex(addition);

    printf("Product of the complex numbers:\n");
    writeComplex(multiply);

    return 0;
}