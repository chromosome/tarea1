#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

typedef int* matrix;


int* allocate_matrix (int n) {
	// return (int*) malloc(n*n*sizeof(int));
	return (int*) calloc(n*n, sizeof(int));
}

int* allocate_matrix_nm (int n, int m) {
	// return (int*) malloc(n*m*sizeof(int));
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
	// int m = n/2;
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


// int** allocate_matrix (int n) {
// 	int* cols = (int*) malloc(n*n*sizeof(int));
// 	int** rows = (int**) malloc(n*sizeof(int*));

// 	return rows;
// }

// int** allocate_matrix_nm (int n, int m) {
// 	return (int**) malloc(n*m*sizeof(int));
// }

#endif
