#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    while (1) 
	{
        
        printf("\nBasic Calculator \n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        
        if (choice == 5) 
		{
            printf("Exiting program.\n");
            break;
        }

       
        if (choice < 1 || choice > 5) 
		{
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (choice) 
		{
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if (num2 != 0) 
				{
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } 
				else 
				{
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
        }
    }

    return 0;
}

