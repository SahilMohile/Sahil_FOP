#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

int main() 
{
    int i, n;

    
    srand(time(0));

    printf("How many random numbers to print? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
	{
       
        int r = rand() % 100; 
        printf("%d ", r);
    }

    printf("\n");
    return 0;
}

