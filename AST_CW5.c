#include <stdio.h>

int main() {
    int A[3][3], B[3][3], sum[3][3], n = 3;
    int i, j, k;

    printf("Enter elements for a 3x3 Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("\nEnter another 3x3 Matrix to add:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("\nResult of Addition:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%d ", sum[i][j]);
        printf("\n");
    }

    
    int found = 0;
    for (i = 0; i < n; i++) {
        int min_row = A[i][0], col_idx = 0;
        for (j = 1; j < n; j++) {
            if (A[i][j] < min_row) {
                min_row = A[i][j];
                col_idx = j;
            }
        }
        
        int is_saddle = 1;
        for (k = 0; k < n; k++) {
            if (A[k][col_idx] > min_row) {
                is_saddle = 0;
                break;
            }
        }
        if (is_saddle) {
            printf("\nSaddle Point found: %d\n", min_row);
            found = 1;
        }
    }
    if (!found) printf("\nNo Saddle Point found.\n");

    
    int d1 = 0, d2 = 0;
    for (i = 0; i < n; i++) {
        d1 += A[i][i];
        d2 += A[i][n - 1 - i];
    }

    if (d1 == d2) printf("\nMatrix is a Magic Square (Diagonal sums match).\n");
    else printf("\nNot a Magic Square.\n");

    return 0;
}

