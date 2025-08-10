/*calculate transporse of the given sparse matrix in 3 tuple format    
2D ->   sparse 0 0 33 
        matrix 1 1 17
        truple 2 3 46
        format 3 3 51 */
#include <stdio.h>

int main() {
    // row, col, value
    int sparseMatrix[4][3] = {
        {0, 2, 33},
        {1, 1, 17},
        {2, 3, 46},
        {3, 3, 51}
    };

    int rows = 4;
    int cols = 4;

    int fullMatrix[4][4] = {0};

    for (int i = 0; i < 4; i++) {
        int r = sparseMatrix[i][0];
        int c = sparseMatrix[i][1];
        int val = sparseMatrix[i][2];
        fullMatrix[c][r] = val;
    }

    printf("Full Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", fullMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}