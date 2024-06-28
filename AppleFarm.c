#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long maximum2dSubMatrixSum(int* Grid[], int rows, int cols, int squareAmt) {
    if (rows == 0 || cols == 0) {
        return 0;
    }
    
    long max = LONG_MIN;

    for (int i = 1; i <= squareAmt; i++) {
        for (int j = 1; j <= squareAmt; j++) {
            int runRows = i;
            int runCols = j;  

            if (runRows <= rows && runCols <= cols && runRows*runCols <= squareAmt) {
                int colBounds = cols - runCols + 1;
                int rowBounds = rows - runRows + 1;

                // Iterate through all bounds
                for (int j = 0; j < rowBounds; j++) {
                    for (int k = 0; k < colBounds; k++) {
                        long tempSum = 0;

                        // Iterate through submatrix square
                        for (int l = 0; l < runRows; l++) {
                            for (int m = 0; m < runCols; m++) {
                                tempSum += Grid[j + l][k + m];
                            }
                        }

                        if (tempSum > max) {
                            max = tempSum;
                        }
                    }
                }
            }
        }
    }

    return max;
}

int main() {
    int cols, rows;
    scanf("%d %d", &cols, &rows);

    int pw, pwpersq;
    scanf("%d %d", &pw, &pwpersq);

    if (cols == 0 || rows == 0) {
        printf("0");
        return 0;
    }

    int* Grid[rows];
    for (int i = 0; i < rows; i++)
        Grid[i] = (int*)malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &Grid[i][j]);
        }
    }

    int squareAmt = pw / pwpersq;
    if (squareAmt > rows * cols) {
        squareAmt = rows * cols;
    }

    if (pw == 0) {
        printf("0");
        return 0;        
    }

    long maximumSum = maximum2dSubMatrixSum(Grid, rows, cols, squareAmt);

    printf("%ld", maximumSum);

    for (int i = 0; i < rows; i++)
        free(Grid[i]);

    return 0;
}