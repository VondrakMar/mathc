#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void write_gnu(double* data_x, double* data_y, int data_size, char* filename);

double random_double(double max_value, double min_value);

void print_vector(double* vector, size_t sample_size);

void angle3Drad(double x1, double y1, double z1,double x2, double y2, double z2); 
#endif // UTILS_H
