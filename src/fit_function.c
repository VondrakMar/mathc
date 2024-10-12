/* #include "linalg.h" */
#include "util.c"
/* #include <math.h> */
/* #include <stdio.h> */
/* #include <stdlib.h> */

double random_double(double max_value, double min_value) {
    return min_value + (max_value - min_value) * ((double)rand() / RAND_MAX);
}


double* polynomial(double* coefs,size_t degree, double* x, size_t sample_size){
    double* y_poly = (double*)calloc(sample_size,sizeof(double));
    for (size_t i = 0; i < sample_size; i++){
        double temp_x = x[i];
        for (size_t d = 0; d < degree+1; d++){
            y_poly[i] += coefs[d] * pow(temp_x, d);
            /* y_poly[i] = a + b * temp_x + c * pow(temp_x,2) + d * pow(temp_x,3);  */
        }
    }
    return y_poly;
}

double loss_function(double* y_pred, double* y_ref, size_t sample_size){
    double loss = 0;
    for (size_t i = 0; i < sample_size ; i++){
        double diff = y_pred[i] - y_ref[i];
        loss += diff*diff;
    }
    return loss;
}

void print_vector(double* vector, size_t sample_size){
    for (size_t i = 0; i < sample_size ; i++){
        printf("%f ",vector[i]);
    }
    printf("\n");
}

/* void optimize_poly3(double* a, double* b, double* c, double* d, double* x,double* y_ref, size_t sample_size){ */
void optimize_poly(double* coefs, size_t degree, double* x,double* y_ref, size_t sample_size,size_t opt_steps, double lr){
    for (size_t iter = 0; iter < opt_steps; iter++){
        double* y_poly = polynomial(coefs,degree,x,sample_size);
        double L = loss_function(y_poly,y_ref,sample_size);
        if (iter%50==0) printf("iteration: %ld, loss: %f\n",iter,L);
        double* diff = (double*)calloc(sample_size,sizeof(double));
        double* grads = (double*)calloc(degree+1,sizeof(double));
        for (size_t i = 0; i < sample_size ; i++){
            diff[i] = y_poly[i] - y_ref[i];
            for (size_t d = 0; d < degree+1; d++){
                grads[d] += 2*diff[i]*pow(x[i], d);
            }
        }
        for (size_t d = 0; d < degree+1; d++){
            coefs[d] -= lr*grads[d];
        }
        free(grads);
        free(diff);
        free(y_poly);
    }
}

int main(){
    size_t sample_size = 1000;
    size_t poly_degree = 3;
    double* x = (double*)calloc(sample_size,sizeof(double));
    double* y_sin = (double*)calloc(sample_size,sizeof(double));
    double increment = 2*M_PI/sample_size;
    for (size_t i = 0; i < sample_size; i++){
        x[i] = -M_PI+increment*i;
        y_sin[i] = sin(x[i]);
    }
    write_gnu(x,y_sin,sample_size,"test_file");
    double* poly_coefs = (double*)calloc(poly_degree+1,sizeof(double));
    for (size_t d = 0; d < poly_degree+1; d++){
        poly_coefs[d] = random_double(-1,1);
    }
    size_t opt_iteration = 10000;
    double lr = 1e-6;
    optimize_poly(poly_coefs,poly_degree,x,y_sin,sample_size,opt_iteration,lr);
    double* y_poly = polynomial(poly_coefs,poly_degree,x,sample_size);
    print_vector(y_poly,sample_size);
    write_gnu(x,y_poly,sample_size,"test_poly");
    free(x);
    free(y_sin);
    free(y_poly);
    return 0;
}
