#ifndef ML_H
#define ML_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void optimize_poly(double* coefs, size_t degree, double* x,double* y_ref, size_t sample_size,size_t opt_steps, double lr);

double* polynomial(double* coefs,size_t degree, double* x, size_t sample_size);

double loss_function(double* y_pred, double* y_ref, size_t sample_size);

#endif //ML_H