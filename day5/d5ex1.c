#include <stdio.h>

struct Dimension {
    float length;
    float width;
    float height;
};

typedef struct Dimension Dimension;

float calculateVolumeArrow(Dimension* dimen) {
    float volume = dimen->length * dimen->width * dimen->height;
    return volume;
}

float calculateSurfaceAreaArrow(Dimension* dimen) {
    float area = 2 * (dimen->length * dimen->width + dimen->length * dimen->height + dimen->width * dimen->height);
    return area;
}

float calculateVolumeDot(Dimension* dimen) {
    float volume = (*dimen).length * (*dimen).width * (*dimen).height;
    return volume;
}

float calculateSurfaceAreaDot(Dimension* dimen) {
    float area = 2 * ((*dimen).length * (*dimen).width + (*dimen).length * (*dimen).height + (*dimen).width * (*dimen).height);
    return area;
}

int main() {
    Dimension mydimen;

    printf("Enter the Length: ");
    scanf("%f", &mydimen.length);
    printf("Enter the Width: ");
    scanf("%f", &mydimen.width);
    printf("Enter the Height: ");
    scanf("%f", &mydimen.height);

    Dimension* dimenPtr = &mydimen;

    float volumeDot = calculateVolumeDot(dimenPtr);
    float surfaceAreaDot = calculateSurfaceAreaDot(dimenPtr);
    printf("\nWith the help of (*) asterisk or indirection operator and (.) dot operator:\n");
    printf("Volume: %.2f\n", volumeDot);
    printf("Surface Area: %.2f\n", surfaceAreaDot);

    float volumeArrow = calculateVolumeArrow(dimenPtr);
    float surfaceAreaArrow = calculateSurfaceAreaArrow(dimenPtr);
    printf("\nWith the help of (->) Arrow operator using pointer as well as dot representation:\n");
    printf("Volume: %.2f\n", volumeArrow);
    printf("Surface Area: %.2f\n", surfaceAreaArrow);

    return 0;
}
