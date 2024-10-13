#include "basis_functions.h"

double gaussian(double x, double r_A, double alpha_A){
    /* unnormalized gaussian exp(-alpha*(r-r_A)**2) */
    /* witdh of the Gaussian is sigma = 1/pi*alpha_A */
    double dist = pow(r_A - x,2);
    double result = exp(-alpha_A*dist);
    return result;
}

double* gaussian_fill(double* data_x, int size_x, double mu,double sigma){
    double* gaus_y = (double*)malloc(size_x*sizeof(double));
    for (int i = 0 ; i < size_x; i++){
        gaus_y[i] = gaussian(data_x[i],mu,sigma);
    }
    return gaus_y;
}

/* function for calculation new r for a product of 2 gaussians */
double gaussian_product_new_r(double alpha_A,double r_A,double alpha_B, double r_B){
    double new_r = (alpha_A*r_A+alpha_B*r_B)/(alpha_A + alpha_B);
    return  new_r;
}
    
double gaussian_product_prefactor(double alpha_A,double r_A,double alpha_B, double r_B){
    double prefactor = (alpha_A*alpha_B)/(alpha_A + alpha_B);
    prefactor = exp(-prefactor*pow(r_A-r_B,2));
    return prefactor;
}

double gaussian_product_new_alpha(double alpha_A,double alpha_B){
    double new_alpha = (alpha_A + alpha_B);
    return new_alpha;
}
