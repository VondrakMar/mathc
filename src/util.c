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
