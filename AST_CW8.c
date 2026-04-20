#include <stdio.h>

int main() {
    float m1, m2, m3, m4, m5, total, percentage;
    int pass = 1;

    printf("Enter marks for 5 courses (out of 100 each):\n");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    
    if (m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40) {
        pass = 0;
    }

    if (pass == 0) 
	{
        printf("\nResult: FAIL (Scored below 40 in one or more subjects)\n");
    } else {
        total = m1 + m2 + m3 + m4 + m5;
        percentage = total / 5;

        printf("\nTotal Marks: %.2f", total);
        printf("\nPercentage: %.2f%%", percentage);
        printf("\nResult: PASS");
        printf("\nGrade: ");

        if (percentage >= 75) {
            printf("Distinction\n");
        } 
		else if (percentage >= 60) {
            printf("First Division\n");
        } 
		else if (percentage >= 50) {
            printf("Second Division\n");
        } 
		else if (percentage >= 40) {
            printf("Third Division\n");
        }
    }

    return 0;
}

