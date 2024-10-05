#include "linalg.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void write_gnu(double* data_x, double* data_y, int data_size, char* filename){
    FILE *fgnu;
    fgnu = fopen(filename,"w");
    if (fgnu) {
        for (int i = 0; i < data_size; i++){
            fprintf(fgnu,"%f %f\n",data_x[i],data_y[i]);
        }
        fclose(fgnu);
    }
}

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

int main(){
    size_t size_x = 1000;
    double* test_x = (double*)calloc(size_x,sizeof(double));
    for (int i = 0; i < size_x; i++){
        test_x[i] = (-100+i)*0.01;
    }
    double r_A = 3;
    double r_B = 4;
    double sigma_A = 2;
    double sigma_B = 1.4;
    double alpha_A = 1/(sqrt(M_PI)*sigma_A);
    double alpha_B = 1/(sqrt(M_PI)*sigma_B);

    double* test_yA = gaussian_fill(test_x, size_x,r_A,alpha_A);
    double* test_yB = gaussian_fill(test_x, size_x,r_B,alpha_B);
    double new_R = gaussian_product_new_r(alpha_A,r_A,alpha_B,r_B);
    double new_alpha = gaussian_product_new_alpha(alpha_A,alpha_B);
    double new_prefactor = gaussian_product_prefactor(alpha_A,r_A,alpha_B,r_B);
    printf("%f %f %f\n",alpha_A,alpha_B,new_alpha);
    printf("%f %f %f\n",r_A,r_B,new_R);
    double* test_y_new = gaussian_fill(test_x, size_x,new_R,new_alpha);
    for (int i = 0; i < size_x; i++){
        test_y_new[i] = new_prefactor*test_y_new[i];
    }
    write_gnu(test_x,test_yA,size_x,"testA.txt");
    write_gnu(test_x,test_yB,size_x,"testB.txt");
    write_gnu(test_x,test_y_new,size_x,"test_new.txt");
    free(test_x);
    free(test_yA);
    free(test_yB);
    free(test_y_new);
    return 0;
}
