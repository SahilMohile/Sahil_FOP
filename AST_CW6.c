#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) 
	{
        printf("Factorial of negative numbers is not possible.\n");
    } 
	else 
	{
        printf("Iterative: %ld\n", factorialIterative(num));
        printf("Recursive: %ld\n", factorialRecursive(num));
    }
    return 0;
}

