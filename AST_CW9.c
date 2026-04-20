#include <stdio.h>

int main() 
{
    int num, n, r, sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    n = num;

   
    while (n > 0) {
        r = n % 10;               
        sum = sum + (r * r * r);   
        n = n / 10;                
    }

    if (sum == num) {
        printf("It is an Armstrong number.\n");
    } else {
        printf("It is NOT an Armstrong number.\n");
    }

    return 0;
}

