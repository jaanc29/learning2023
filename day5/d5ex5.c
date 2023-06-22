#include <stdio.h>

struct swap {
    int x;
    int y;
};

typedef struct swap Point;

void swapnumber(Point* p1,Point* p2) {

    int temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;

    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}

int main() {

    Point point1;
    Point point2;

    printf("Enter the coordinates of Point 1 (x y): ");
    scanf("%d %d", &point1.x, &point1.y);

    printf("Enter the coordinates of Point 2 (x y): ");
    scanf("%d %d", &point2.x, &point2.y);

    printf("Before swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    swapnumber(&point1, &point2);

    printf("\nAfter swapping:\n");
    printf("Point 1: x = %d, y = %d\n", point1.x, point1.y);
    printf("Point 2: x = %d, y = %d\n", point2.x, point2.y);

    return 0;
}