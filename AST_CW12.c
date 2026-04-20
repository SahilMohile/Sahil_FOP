#include <stdio.h>

int main() {
    int n1, n2, i, smallest, gcd;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    
    int min = (n1 < n2) ? n1 : n2;
    smallest = 0; 

    for (i = 2; i <= min; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            smallest = i;
            break; 
        }
    }

    
    for (i = 1; i <= min; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }

    
    if (smallest != 0) {
        printf("Smallest common divisor: %d\n", smallest);
    } else {
        printf("No common divisor other than 1.\n");
    }
    
    printf("Greatest Common Divisor (GCD): %d\n", gcd);

    return 0;
}

