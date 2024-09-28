#include "linalg.h"

int main() {
    srand(time(NULL));

    size_t dimA1 = 4;
    size_t dimA2 = 6;
    double **matrix1 = alloc_2d_array(dimA1,dimA2);
    init_random_matrix(matrix1, dimA1, dimA2);

    size_t dimB1 = 6;
    size_t dimB2 = 3;
    
    double **matrix2 = alloc_2d_array(dimB1,dimB2);
    init_random_matrix(matrix2, dimB1, dimB2);

    print_matrix(matrix1, dimA1, dimA2);
    print_matrix(matrix2, dimB1, dimB2);
    double **matmul_result = matmul(matrix1, matrix2, dimA1, dimA2, dimB2);
    print_matrix(matmul_result, dimA1, dimB2);

    free_2d_array(matrix1,dimA1);
    free_2d_array(matrix2,dimB1);
    free_2d_array(matmul_result,dimA1);

    return 0;
}
