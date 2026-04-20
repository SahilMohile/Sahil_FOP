#include <stdio.h>
#include <math.h>

int main() 
{
    int num, i, j, isPrime, temp;
    long fact;

    printf("Enter a number: ");
    scanf("%d", &num);

    
    printf("Square Root: %.2f\n", sqrt(num));
    printf("Square: %d\n", num * num);
    printf("Cube: %d\n", num * num * num);

   
    isPrime = 1;
    if (num < 2) isPrime = 0;
    for (i = 2; i <= num / 2; i++) 
	{
        if (num % i == 0) 
		{
            isPrime = 0;
            break;
        }
    }
    if (isPrime) printf("%d is a Prime number.\n", num);
    else printf("%d is NOT a Prime number.\n", num);

    
    fact = 1;
    for (i = 1; i <= num; i++) 
	{
        fact = fact * i;
    }
    printf("Factorial: %ld\n", fact);

    
    printf("Prime Factors: ");
    temp = num;
    for (i = 2; i <= temp; i++) 
	{
        while (temp % i == 0) 
		{
            printf("%d ", i);
            temp = temp / i;
        }
    }
    printf("\n");

    return 0;
}

