#include <stdio.h>

int main() {
    int choice;
    double a, b, res;
    int i, n;
    long fact;

    printf("--- Simple Calculator ---\n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power (x^y)\n6. Factorial (x!)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 5) {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &a, &b);
    } else if (choice == 6) {
        printf("Enter a number: ");
        scanf("%d", &n);
    }

    switch (choice) {
        case 1: printf("Result: %.2f\n", a + b); break;
        case 2: printf("Result: %.2f\n", a - b); break;
        case 3: printf("Result: %.2f\n", a * b); break;
        case 4: 
            if (b != 0) printf("Result: %.2f\n", a / b);
            else printf("Error: Division by zero\n");
            break;
        case 5:
            res = 1;
            for (i = 1; i <= (int)b; i++) res = res * a;
            printf("Result: %.2f\n", res);
            break;
        case 6:
            fact = 1;
            for (i = 1; i <= n; i++) fact = fact * i;
            printf("Result: %ld\n", fact);
            break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}

