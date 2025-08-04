/*Create a square Matrix then find :
a) No of non zero elements
b) Print upper and lower trangular elements
c) Print the diagonal elements*/

#include <stdio.h>
int main(){
    int mat[4][4];

    printf("Enter elements for 4*4 matrix: ");
    for(int i = 0; i<4;i++){
        for(int j = 0; j<4;j++){
            printf("Enter the %d,%d: ",i,j );
            scanf("%d", &mat[i][j]);
        }
    }
    
    int count;
    for(int i = 0; i<4;i++){
        for(int j = 0; j<4;j++){
            if(mat[i][j] != 0){
                count++;

            }
            
        }
    }
    printf("\nThe Number of non-zero elements in the matrix is: %d", count);
    printf("\nThe elements in lower trangular matrix is: ");
     for(int i = 0; i<4;i++){
        for(int j = 0; j<i;j++){
            
            
                printf("%d",mat[i][j] );
                
            
        }
    }

    printf("\nThe elements in upper trangular matrix is: ");
     for(int i = 0; i<4;i++){
        for(int j = i+1; j<4;j++){
            
            
                printf("%d",mat[i][j] );
            
        }
    }

    printf("\nThe elements in diagonal of the matrix is: ");
     for(int i = 0; i<4;i++){
        for(int j = 0; j<=i;j++){
            
            if(i==j){
                printf("%d",mat[i][j] );
            }
        }
    }

    


    return 0;

}