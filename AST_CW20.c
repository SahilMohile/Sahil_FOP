#include <stdio.h>

int main() {
    int x = 10, y = 20;

    printf("Original: x = %d, y = %d\n", x, y);

    
    printf(" Swapping without Pointers \n");
    swapByValue(x, y);
    printf("After function call: x = %d, y = %d (No change!)\n", x, y);

    
    printf("Swapping with Pointers \n");
    swapByPointer(&x, &y);
    printf("After function call: x = %d, y = %d (Changed!)\n", x, y);

    return 0;
}

