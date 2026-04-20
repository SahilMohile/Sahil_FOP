#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    char ch;

    
    printf("Enter source file path: ");
    scanf("%s", sourcePath);
    printf("Enter destination file path: ");
    scanf("%s", destPath);

    
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(EXIT_FAILURE);
    }

    
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        fclose(sourceFile);
        printf("Error: Cannot open destination file.\n");
        exit(EXIT_FAILURE);
    }

   
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

