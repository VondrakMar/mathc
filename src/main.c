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
    solution[n-1] = augmented[n-1][n]/augmented[n-1][n-1];
    for (size_t sol = n-1; sol > 0; sol--){
        for (size_t c = 0; c < n ; c++){
            augmented[sol-1][n] -= solution[c]*augmented[sol-1][c];
        }
        solution[sol-1] = augmented[sol-1][n]/augmented[sol-1][sol-1];
    }
    /* free_2d_array(augmented,n); */
    return solution;
}


int main(){
    /* test_poly(); */
    size_t n = 10;
    size_t m = 10;
    double** mat = alloc_2d_array(n,m);
    double* vec = (double*)malloc(10*sizeof(double));
    read_matrix("mat_linalg",mat,n,m);
    read_vector("vet_linalg",vec,n);
    double* sol = gauss_elimination(mat,vec,n);
    /* printf("Vector\n"); */
    print_vector(sol,10);
    /* printf("Matrix\n"); */
    /* print_matrix(mat,n,m); */
     return 0;
}
