#include <stdio.h>

// Function to read matrix from user
void readMatrix(int matrix[][100], int row, int col) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[][100], int mat2[][100], int result[][100], 
                      int r1, int c1, int r2, int c2) {
    // Initialize result matrix with 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[100][100], mat2[100][100], result[100][100];
    int r1, c1, r2, c2;
    
    printf("========================================\n");
    printf("     MATRIX MULTIPLICATION PROGRAM\n");
    printf("========================================\n\n");
    
    // Input dimensions of first matrix
    printf("Enter rows and columns for FIRST matrix: ");
    scanf("%d %d", &r1, &c1);
    
    // Input dimensions of second matrix
    printf("Enter rows and columns for SECOND matrix: ");
    scanf("%d %d", &r2, &c2);
    
    // Check if multiplication is possible
    if (c1 != r2) {
        printf("\nError: Matrix multiplication not possible!\n");
        printf("Number of columns in first matrix (%d) must equal\n", c1);
        printf("number of rows in second matrix (%d).\n", r2);
        return 1;
    }
    
    // Read first matrix
    printf("\n--- FIRST MATRIX (%dx%d) ---\n", r1, c1);
    readMatrix(mat1, r1, c1);
    
    // Read second matrix
    printf("\n--- SECOND MATRIX (%dx%d) ---\n", r2, c2);
    readMatrix(mat2, r2, c2);
    
    // Multiply matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);
    
    // Display all matrices
    printf("\n========================================\n");
    printf("FIRST MATRIX:\n");
    displayMatrix(mat1, r1, c1);
    
    printf("\nSECOND MATRIX:\n");
    displayMatrix(mat2, r2, c2);
    
    printf("\nRESULTANT MATRIX (Product):\n");
    displayMatrix(result, r1, c2);
    printf("========================================\n");
    
    return 0;
}
