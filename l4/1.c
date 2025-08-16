//WAP to perform addition of two given sparse matrix in 3–tuple format.
/*Sample Input:
Enter sparse matrix-I in 3-tuple format
1st tuple format: rows cols non-zero elements
mat input frm 2nd tuple onwards
0 3 30
1 1 10
2 3 40
3 4 21
Enter sparse matrix-2 in 3-tuple format
4 5 5
0 2 65
1 1 65
2 3 12
3 3 71

*/




#include <stdio.h>

int main() {
    int a[16][3], b[16][3], c[32][3];
    int rows1, cols1, m, rows2, cols2, n, k = 0;
    // trying the code not to be hard coded
    printf("Enter sparse matrix-1 in 3-tuple format\n");
    printf("1st tuple format: rows cols non-zero elements\n mat input frm 2nd tuple onwards\n");
    scanf("%d %d %d", &rows1, &cols1, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    
    printf("Enter sparse matrix-2 in 3-tuple format\n");
    printf("1st tuple format: rows cols non-zero elements\n mat input frm 2nd tuple onwards\n");
    scanf("%d %d %d", &rows2, &cols2, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
    }

    if(rows1 != rows2 || cols1 != cols2) {
        printf("Matrix dimensions do not match. Addition not possible.\n");
        return 0;
    }
    
    // Copy A to result
    for(int i = 0; i < m; i++) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
    }
    
    // Add B elements
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < k; j++) {
            if(b[i][0] == c[j][0] && b[i][1] == c[j][1]) {
                c[j][2] += b[i][2];
                found = 1;
                break;
            }
        }
        if(!found) {
            c[k][0] = b[i][0];
            c[k][1] = b[i][1];
            c[k][2] = b[i][2];
            k++;
        }
    }
    
    // Print result in normal matrix form
    printf("\nResultant Matrix:\n");
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols1; j++) {
            int val = 0;
            for(int x = 0; x < k; x++) {
                if(c[x][0] == i && c[x][1] == j) {
                    val = c[x][2];
                    break;
                }
            }
            printf("%d ", val);
        }
        printf("\n");
    }

    return 0;
}
