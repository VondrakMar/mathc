#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


double random_number(int min_value, int max_value);

void init_random_vector(double *vec, size_t size);

void init_random_matrix(double **mat, size_t dim1, size_t dim2);

double dot_product(double *vec1, double *vec2, size_t size);

double** matmul(double **A, double **B, size_t dimA, size_t dim_both, size_t dimB);

// void print_vector(double *vec, size_t size);

void print_matrix(double **mat, size_t dim1, size_t dim2);

double** alloc_2d_array(size_t rows, size_t cols);

void free_2d_array(double** array2D, size_t rows);

#endif // MATRIX_OPERATIONS_H
