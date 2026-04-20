#include <stdio.h>


struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student s[100];
    int n, i;

    printf("How many students? ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("\nStudent %d details:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll: ");
        scanf("%d", &s[i].roll);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

   
    printf("\nRESULTS \n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.1f | ", s[i].roll, s[i].name, s[i].marks);
        
        if (s[i].marks >= 40) {
            printf("PASS\n");
        } else {
            printf("FAIL\n");
        }
    }

    return 0;
}

