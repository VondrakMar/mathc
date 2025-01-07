#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linalg.h"
#include "basis_functions.h"
#include "machine_learning.h"
#include "util.h"

#include "test.c"


double* gauss_elimination(double** A, double* b, size_t n){
    // n = m, so that is why we take only n
    // this is gaussian elimination
    // this is here just for checking stuff
    double** augmented = alloc_2d_array(n,n+1); // for creating augmented matrix
    double* solution = (double*)malloc(n*sizeof(double));
    for (size_t i = 0; i < n ; i++){
        for (size_t j = 0; j < n ; j++){
            augmented[i][j] = A[i][j];
        }
        augmented[i][n] = b[i];
    }
    for (size_t pivot = 0; pivot < n -1; pivot++){
        for (size_t i = 1+pivot; i < n ; i++){
            double current_mult = augmented[i][pivot]/augmented[pivot][pivot];
            for (size_t j = 0; j < n+1 ; j++){
                augmented[i][j] -= augmented[pivot][j]*current_mult;
            }
        }
    }
    solution[n-1] = augmented[n-1][n]/augmented[n-1][n-1]; // can this be rewritten with do while?
    for (size_t sol = n-1; sol > 0; sol--){
        for (size_t c = 0; c < n ; c++){
            augmented[sol-1][n] -= solution[c]*augmented[sol-1][c];
        }
        solution[sol-1] = augmented[sol-1][n]/augmented[sol-1][sol-1];
    }
    free_2d_array(augmented,n);
    return solution;
}

void switch_col(double** A, size_t col1,size_t col2,size_t col_size){
    /* double* temp_row = (double*)malloc(row_size*sizeof(double)); */
    double temp_value;
    for (size_t i = 0; i < col_size; i++){
        /* temp_row = A[col1][i]; */
        temp_value = A[i][col1];
        A[i][col1] = A[i][col2];
        A[i][col2] = temp_value;
    }
    /* free(temp_row); */
}


void switch_row(double** A, size_t row1,size_t row2,size_t col_size){
    /* double* temp_row = (double*)malloc(row_size*sizeof(double)); */
    double temp_value;
    for (size_t i = 0; i < col_size; i++){
        /* temp_row = A[row1][i]; */
        temp_value = A[row1][i];
        A[row1][i] = A[row2][i];
        A[row2][i] = temp_value;
    }
    /* free(temp_row); */
}

double trace(double** A, size_t rows, size_t cols) {
    if (rows != cols) {
        printf("This is not a square lula");
        return -1; 
    }
    double trace = 0.0;
    for (size_t i = 0; i < rows; i++) {
        trace += A[i][i];
    }
    return trace;
}

//void LUdcmp(double** A, int n, ){

//}


int main(){
    /* test_poly(); */
    size_t n = 3;
    size_t m = 2;
    double** U = alloc_2d_array(3,3);
    double** L = alloc_2d_array(4,3);
    read_matrix("U",U,3,3);
    read_matrix("L",L,4,3);
    double** LU = matmul(L,U, 4, 3, 3); 
    print_matrix(U,3,3);
    print_matrix(L,4,3);
    print_matrix(LU,4,3);
    free_2d_array(L,4);
    free_2d_array(U,3);
    free_2d_array(LU,4);
    return 0;
}
