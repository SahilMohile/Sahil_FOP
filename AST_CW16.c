#include <stdio.h>

int main() {
    int n, i;
    int a[100], even[100], odd[100];
    int e_count = 0, o_count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        
        if (a[i] % 2 == 0) 
		{
            even[e_count] = a[i];
            e_count++;
        }
		 else
		 {
            odd[o_count] = a[i];
            o_count++;
        }
    }

    
    printf("\nEven numbers: ");
    for (i = 0; i < e_count; i++) 
	{
        printf("%d ", even[i]);
    }

    
    printf("\nOdd numbers: ");
    for (i = 0; i < o_count; i++) 
	{
        printf("%d ", odd[i]);
    }

    printf("\n");
    return 0;
}

