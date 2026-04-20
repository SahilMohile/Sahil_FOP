#include <stdio.h>
#include <math.h>

int main() 
{
    int i, n;
    float x, deg, term, sum;

    printf("Enter angle in degrees: ");
    scanf("%f", &deg);
    printf("Enter number of terms: ");
    scanf("%d", &n);

    
    x = deg * (3.14159 / 180);

    term = x; 
    sum = x;

    for (i = 1; i < n; i++) 
	{
    
        term = term * (-1) * x * x / ((2 * i) * (2 * i + 1));
        sum = sum + term;
    }

    printf("Sum of sine series for %.2f degrees is: %.4f\n", deg, sum);
    printf("Actual sin(%.2f) using math library: %.4f\n", deg, sin(x));

    return 0;
}

