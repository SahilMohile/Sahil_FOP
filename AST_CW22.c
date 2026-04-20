#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        printf("\n--- String Operations Menu ---");
        printf("\n1. Length (strlen)");
        printf("\n2. Copy (strcpy)");
        printf("\n3. Concatenate (strcat)");
        printf("\n4. Compare (strcmp)");
        printf("\n5. Reverse (strrev - non-standard)");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 6) break;

        printf("Enter string: ");
        fgets(str1, sizeof(str1), stdin);
        str1[strcspn(str1, "\n")] = 0; 

        switch (choice) {
            case 1:
                printf("Length: %zu\n", strlen(str1));
                break;
            case 2:
                strcpy(str2, str1);
                printf("Copied to str2: %s\n", str2);
                break;
            case 3:
                printf("Enter string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                strcat(str1, str2);
                printf("Result: %s\n", str1);
                break;
            case 4:
                printf("Enter string to compare: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                if (strcmp(str1, str2) == 0) printf("Strings are equal.\n");
                else printf("Strings are different.\n");
                break;
            case 5:
                
                printf("Reverse: %s\n", strrev(str1)); 
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

