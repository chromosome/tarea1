#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

typedef void (*mat_mult_t)     (int* w, int* v, int* u, int n);
typedef void (*mat_mult_nm_t)  (int* w, int* v, int* u, int n, int m);
typedef void (*mat_mult_nml_t) (int* w, int* v, int* u, int n, int m, int l);

double high_res_mat_profile (int* w, int* v, int* u, 
							 int n, 
							 mat_mult_t mult) {
	struct timespec start, stop;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	mult(w, v, u, n);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
	double result = (stop.tv_sec - start.tv_sec) * 1e6 
				  + (stop.tv_nsec - start.tv_nsec) / 1e3;
	return result;
}

double high_res_mat_profile_nm (int* w, int* v, int* u, 
								int n, int m, 
								mat_mult_nm_t mult) {
	struct timespec start, stop;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	mult(w, v, u, n, m);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
	double result = (stop.tv_sec - start.tv_sec) * 1e6 
				  + (stop.tv_nsec - start.tv_nsec) / 1e3;
	return result;
}

double high_res_mat_profile_nml (int* w, int* v, int* u, 
								 int n, int m, int l,
								 mat_mult_nml_t mult) {
	struct timespec start, stop;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	mult(w, v, u, n, m, l);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
	double result = (stop.tv_sec - start.tv_sec) * 1e6 
				  + (stop.tv_nsec - start.tv_nsec) / 1e3;
	return result;
}


int* allocate_matrix (int n) {
	return (int*) calloc(n*n, sizeof(int));
}

int* allocate_matrix_nm (int n, int m) {
	return (int*) calloc(n*m, sizeof(int));
}

void print_matrix (int* mat, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%i ", mat[i*n+j]);
		}
		printf("\n");
	}
}

void print_matrix_nm (int* mat, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%i ", mat[i*m+j]);
		}
		printf("\n");
	}
}

void print_named_matrix(int* mat, int n, char* name) {
	printf("%s: \n", name);
	print_matrix(mat, n);
	printf("\n");
}

void print_named_matrix_nm(int* mat, int n, int m, char* name) {
	printf("%s: \n", name);
	print_matrix_nm(mat, n, m);
	printf("\n");
}

void print_matrix_addr(int* mat, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j){
			printf("%p ", mat+(i*n+j));
		}
		printf("\n");
	}
}

void print_named_matrix_addr(int* mat, int n, char* name) {
	printf("%s: \n", name);
	print_matrix_addr(mat, n);
	printf("\n");
}

int* transpose(int* mat, int n) {
	int* t = allocate_matrix(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			t[i*n + j] = mat[i + j*n];
	free(mat);
	return t;
}

int* transpose_nm(int* mat, int n, int m) {
	int* t = allocate_matrix_nm(n, m);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			t[i*n + j] = mat[i + j*m];
	free(mat);
	print_named_array(t, n*m, "t");
	return t;
}

int* sub_matrix(int* src, int n) {
	int* sub = allocate_matrix(n);
	for (int i = 0, k = 0; i < n; ++i, k+=n)
		for (int j = 0; j < n; ++j)
			sub[i*n+j] = src[i*n+k+j];
	return sub;
}

void copy_submatrix(int* dest, int* src, int n) {
	for (int i = 0, k = 0; i < n; ++i, k+=n)
		for (int j = 0; j < n; ++j)
			dest[i*n+k+j] = src[i*n+j];
}

int* zeros(int n) {
	return (int*) calloc(n*n, sizeof(int));
}

int* ones(int n) {
	int* mat = allocate_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i*n+j] = 1;
	return mat;
}

void scalar_mult(int* mat, int n, int scalar) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i*n+j] = mat[i*n+j]*scalar;
}

void mat_sum (int* c, int*a , int* b, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i*n + j] = a[i*n + j] + b[i*n + j];
}

void mat_sub (int* c, int*a , int* b, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i*n + j] = a[i*n + j] - b[i*n + j];
}

#endif
