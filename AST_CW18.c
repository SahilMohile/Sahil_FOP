#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100], rev[100];
    int i, j, len, flag = 0;

    printf("Enter a string: ");
    gets(s1); 

    
    for (len = 0; s1[len] != '\0'; len++);
    printf("Length of string: %d\n", len);

    
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = s1[i];
    }
    rev[j] = '\0';
    printf("Reversed string: %s\n", rev);

    
    printf("\nEnter another string to compare: ");
    gets(s2);
    flag = 0;
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) printf("Strings are equal.\n");
    else printf("Strings are not equal.\n");

   
    flag = 0;
    for (i = 0; i < len; i++) {
        if (s1[i] != rev[i]) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) printf("It is a palindrome.\n");
    else printf("It is not a palindrome.\n");

    
    printf("\nEnter a substring to search for: ");
    gets(s2);
    if (strstr(s1, s2)) printf("Substring found!\n");
    else printf("Substring not found.\n");

    return 0;
}

