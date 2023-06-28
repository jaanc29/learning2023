#include <stdio.h>

int main() {
    FILE *source, *target;
    char sourceName[100], targetName[100];
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", sourceName);

    source = fopen(sourceName, "r");

    if (source == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    printf("Enter the target file name: ");
    scanf("%s", targetName);

    target = fopen(targetName, "w");

    if (target == NULL) {
        printf("Failed to create the target file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, target);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(target);

    return 0;
}