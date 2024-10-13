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


double random_double(double max_value, double min_value) {
    return min_value + (max_value - min_value) * ((double)rand() / RAND_MAX);
}


void print_vector(double* vector, size_t sample_size){
    for (size_t i = 0; i < sample_size ; i++){
        printf("%f ",vector[i]);
    }
    printf("\n");
}
