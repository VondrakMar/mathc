void test_gaussina(){
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
}

void test_poly(){
    size_t sample_size = 1000;
    size_t poly_degree = 3;
    double* x = (double*)calloc(sample_size,sizeof(double));
    double* y_sin = (double*)calloc(sample_size,sizeof(double));
    double increment = 2*M_PI/sample_size;
    for (size_t i = 0; i < sample_size; i++){
        x[i] = -M_PI+increment*i;
        y_sin[i] = sin(x[i]);
    }
    write_gnu(x,y_sin,sample_size,"test_file");
    double* poly_coefs = (double*)calloc(poly_degree+1,sizeof(double));
    for (size_t d = 0; d < poly_degree+1; d++){
        poly_coefs[d] = random_double(-1,1);
    }
    size_t opt_iteration = 10000;
    double lr = 1e-6;
    optimize_poly(poly_coefs,poly_degree,x,y_sin,sample_size,opt_iteration,lr);
    double* y_poly = polynomial(poly_coefs,poly_degree,x,sample_size);
    print_vector(y_poly,sample_size);
    write_gnu(x,y_poly,sample_size,"test_poly");
    free(x);
    free(y_sin);
    free(y_poly);
}