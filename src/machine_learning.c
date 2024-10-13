#include "machine_learning.h"

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
