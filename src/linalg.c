#include "linalg.h"

double random_number(int min_value, int max_value) {
    double range = (max_value - min_value);
    double div = RAND_MAX / range;
    return min_value + (rand() / div);
}

void init_random_vector(double *vec, size_t size) {
    for (size_t i = 0; i < size; i++) {
        vec[i] = random_number(-10, 10);
    }
}

void init_random_matrix(double **mat, size_t dim1, size_t dim2) {
    for (size_t i = 0; i < dim1; i++) {
        for (size_t j = 0; j < dim2; j++) {
            mat[i][j] = random_number(-10, 10);
        }
    }
}

double dot_product(double *vec1, double *vec2, size_t size) {
    double result = 0;
    for (size_t i = 0; i < size; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double** matmul(double **A, double **B, size_t dimA, size_t dim_both, size_t dimB) {
    double **resM = (double**)malloc(dimA * sizeof(*resM));
    for (size_t i = 0; i < dimA; i++) {
        resM[i] = (double*)malloc(dimB * sizeof(double));
    }

    for (size_t rowA = 0; rowA < dimA; rowA++) {
        for (size_t colB = 0; colB < dimB; colB++) {
            resM[rowA][colB] = 0;
            for (size_t com = 0; com < dim_both; com++) {
                resM[rowA][colB] += A[rowA][com] * B[com][colB];
            }
        }
    }
    return resM;
}

// void print_vector(double *vec, size_t size) {
//     for (size_t i = 0; i < size; i++) {
//         printf("%lf ", vec[i]);
//     }
//     printf("\n");
// }

void print_matrix(double **mat, size_t dim1, size_t dim2) {
    for (size_t i = 0; i < dim1; i++) {
        for (size_t j = 0; j < dim2; j++) {
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double** alloc_2d_array(size_t rows, size_t cols){
    double **array2D = (double**)malloc(rows * sizeof(*array2D));
    for (size_t i = 0; i < rows; i++) {
        array2D[i] = (double*)malloc(cols * sizeof(double));
    }
    return array2D;
}

void free_2d_array(double** array2D, size_t rows){
    for (size_t i = 0; i < rows; i++) {
         free(array2D[i]);
    }
    free(array2D);
}
