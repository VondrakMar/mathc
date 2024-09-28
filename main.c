#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>




double random_number(int min_value,int max_value){
    double range = (max_value - min_value);
    double div = RAND_MAX  / range;
    double r_n = min_value + (rand() / div);
    return r_n;
}

void init_random_vector(double *vec, int size){
    for (int i = 0 ; i < size; i++){
        vec[i] = random_number(-10,10);
    }
}

void init_random_matrix(double **mat, int dim1,int dim2){
    for (int i = 0 ; i < dim1; i++){
        for (int j = 0 ; j < dim2 ; j++){
            mat[i][j] = random_number(-10,10);
        }
    }
}

double dot_product(double* vec1, double* vec2, int size){
    double result = 0;
    for (int i = 0; i < size ; i++){
        result += vec1[i]*vec2[i];
    }
    return result;
}

double** matmul(double** A,double** B, int dimA, int dim_both, int dimB){
    double **resM = (double**)malloc(dimA*sizeof(*resM));
    for (int i = 0; i < dimA; i++){
        resM[i] = (double*)malloc(dimB*sizeof(double));
    }
    for (int rowA =0 ; rowA < dimA; rowA++){
        for (int colB = 0 ; colB < dimB ; colB++){
            resM[rowA][colB] = 0;
            for (int com = 0 ; com < dim_both ; com++){
                resM[rowA][colB] += A[rowA][com]*B[com][colB];
            }
        }
    }
    return resM;
}
    
void print_vector(double* vec,int size){
    for (int i = 0; i < size; i++) {
        printf("%lf ", vec[i]);
    }
    printf("\n");
}

void print_matrix(double **mat, int dim1,int dim2){
    for (int i = 0 ; i < dim1; i++){
        for (int j = 0 ; j < dim2 ; j++){
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    /* int n_vec1 = 10; */
    /* double *vec1 = (double*)calloc(n_vec1,sizeof(double)); */
    /* init_random_vector(vec1,n_vec1); */
    /* print_vector(vec1,n_vec1); */
    int dimA1 = 4;
    int dimA2 = 6;
    /* Init rows */
    double **matrix1 = (double**)malloc(dimA1*sizeof(*matrix1));
    for (int i = 0; i < dimA1; i++){
        /* Init cols */
        matrix1[i] = (double*)malloc(dimA2*sizeof(double));
    }
    init_random_matrix(matrix1,dimA1,dimA2);
    int dimB1 = 6;
    int dimB2 = 3;
    double **matrix2 = (double**)malloc(dimB1*sizeof(*matrix1));
    for (int i = 0; i < dimB1; i++){
        matrix2[i] = (double*)malloc(dimB2*sizeof(double));
    }
    init_random_matrix(matrix2,dimB1,dimB2);
    print_matrix(matrix1,dimA1,dimA2);
    printf("############################\n");
    print_matrix(matrix2,dimB1,dimB2);
    double **matmul_result = matmul(matrix1,matrix2,dimA1,dimA2,dimB2);
    
    print_matrix(matmul_result,dimA1,dimB2);
    return 0;
}
