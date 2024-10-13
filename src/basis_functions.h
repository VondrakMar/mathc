#ifndef BASIS_H
#define BASIS_H
#include "util.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double gaussian(double x, double r_A, double alpha_A);

double* gaussian_fill(double* data_x, int size_x, double mu,double sigma);

double gaussian_product_new_r(double alpha_A,double r_A,double alpha_B, double r_B);

double gaussian_product_prefactor(double alpha_A,double r_A,double alpha_B, double r_B);

double gaussian_product_new_alpha(double alpha_A,double alpha_B);

#endif