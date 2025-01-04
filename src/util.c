#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "linalg.h"

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


double random_double(double max_value, double min_value) {
    return min_value + (max_value - min_value) * ((double)rand() / RAND_MAX);
}

/* double angle3Drad(double x1, double y1, double z1,double x2, double y2, double z2,double x2, double y2, double z2){ */
    /* double vec[3]; */
    /* vec[0] = x1 - x2; */
    /* vec[1] = y1 - y2; */
    /* vec[2] = z1 - z2; */
    /* double mag = sqrt(dot_product(vec,vec,3)); */
/* } */

void print_vector(double* vector, size_t sample_size){
    for (size_t i = 0; i < sample_size ; i++){
        printf("%f ",vector[i]);
    }
    printf("\n");
}
