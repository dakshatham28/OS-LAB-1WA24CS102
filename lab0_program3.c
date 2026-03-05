#include <stdio.h>

int main() {
    int r = 3, c = 3;
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += mat[i][j];
        }
        printf("Sum of row %d: %d\n", i+1, rowSum);
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += mat[i][j];
        }
        printf("Sum of column %d: %d\n", j+1, colSum);
    }

    return 0;
}
