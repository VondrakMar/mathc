#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int load_size_vector(char *file_name) {
    FILE *file;
    int n_vec;

    file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1; 
    }
    if (fscanf(file, "%d", &n_vec) != 1) {
        fclose(file);
        return -1;
    }
    fclose(file);
    return n_vec;
}

void load_vector(char *file_name,double* vec){ 
    
    FILE *ptr = fopen(file_name, "r");
    if (ptr == NULL) {
        perror("Error opening file");
        return;
    }

    int n;
    if (fscanf(ptr, "%d", &n) != 1) {
        perror("Error reading number of elements");
        fclose(ptr);
        return;
    }

    // Read the elements into the vector
    for (int i = 0; i < n; i++) {
        if (fscanf(ptr, "%lf", &vec[i]) != 1) { 
            perror("Error reading vector element");
            fclose(ptr);
            return;
        }
    }
   
}

double dot_product(double* vec1, double* vec2, int size){
    double result = 0;
    for (int i = 0; i < size ; i++){
        result += vec1[i]*vec2[i];
    }
    return result;
}

void print_vector(double* vec,int size){
    for (int i = 0; i < size; i++) {
        printf("%lf ", vec[i]);
    }
    printf("\n");
}

void do_dot_product(char *file_vec1, char *file_vec2){
    int n_vec1 = load_size_vector(file_vec1);
    if (n_vec1 == -1){
        printf("vector failed to load");
        return;
    }
    double *vec1 = (double*)calloc(n_vec1,sizeof(double));
    load_vector(file_vec1,vec1);
    int n_vec2 = load_size_vector(file_vec2);
    if (n_vec2 == -1){
        printf("vector failed to load");
        return;
    }
    double *vec2 = (double*)calloc(n_vec1,sizeof(double));
    load_vector(file_vec2,vec2);
    double dot12 = dot_product(vec1,vec2,n_vec1);
    printf("%lf\n",dot12);
    free(vec1);
    free(vec2);
}

int main(){
    do_dot_product("vec1","vec2");
    
    return 0;
}
