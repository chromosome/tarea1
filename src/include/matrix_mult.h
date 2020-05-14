#ifndef MATRIX_MULT_H
#define MATRIX_MULT_H

#include "matrix.h"

void row_major_mult (int* c, int* a, int* b, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i*n + j] += a[i*n + k]*b[k*n + j];
}

void col_major_mult (int* c, int* a, int* b, int n) {
	b = transpose(b, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i*n + j] += a[i*n + k]*b[j*n + k];
}

void row_major_mult_nm (int* c, int* a, int* b, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				c[i*n + j] += a[i*m + k]*b[k*n + j];
}

void col_major_mult_nm (int* c, int* a, int* b, int n, int m) {
	b = transpose_nm(b, m, n);
	print_named_array(b, n*m, "bt");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				c[i*n + j] += a[i*m + k]*b[j*n + k];
}

void row_major_mult_nml (int* c, int* a, int* b, int n, int m, int l) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int k = 0; k < m; k++) {
				c[i*l + j] += a[i*m + k]*b[k*l + j];
				printf("a[%i,%i]: %i, ", i, k, a[i*m+k]);
				printf("b[%i,%i]: %i, ", k, j, b[k*l+j]);
				printf("a[%i,%i]*b[%i,%i]: %i\n", i,k,k,j, a[i*m+k]*b[k*l+j]);
				printf("c[%i,%i]: %i\n", i, j, c[i*l+j]);
				printf("\n");
			}
}

void col_major_mult_nml (int* c, int* a, int* b, int n, int m, int l) {
	b = transpose_nm(b, n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < l; j++)
			for (int k = 0; k < m; k++)
				c[i*n + j] += a[i*n + k]*b[k*m + j];
}

void strassen (int* c, int* a, int *b, int n) {
	if (n == 1) {
		c[0] += a[0]*b[0];
		return;
	}

	int m = n/2;

	int* a1=sub_matrix(a, m);
	int* a2=sub_matrix(a+m, m);
	int* a3=sub_matrix(a+n*m, m);
	int* a4=sub_matrix(a+n*m+m, m);
	int* b1=sub_matrix(b, m);
	int* b2=sub_matrix(b+m, m);
	int* b3=sub_matrix(b+n*m, m);
	int* b4=sub_matrix(b+n*m+m, m);
	int* aux1=allocate_matrix(m);
	int* aux2=allocate_matrix(m);
	int* aux3=allocate_matrix(m);
	int* aux4=allocate_matrix(m);
	int* c1=c;
	int* c2=c+m;
	int* c3=c+n*m;
	int* c4=c+n*m+m;

	int* p1 = allocate_matrix(m);
	int* p2 = allocate_matrix(m);
	int* p3 = allocate_matrix(m);
	int* p4 = allocate_matrix(m);
	int* p5 = allocate_matrix(m);
	int* p6 = allocate_matrix(m);
	int* p7 = allocate_matrix(m);

	int* tmp1 = allocate_matrix(m);
	mat_sub(tmp1, b2, b4, m);
	strassen(p1, a1, tmp1, m);

	int* tmp2 = allocate_matrix(m);
	mat_sum(tmp2, a1, a2, m);
	strassen(p2, tmp2, b4, m);

	int* tmp3 = allocate_matrix(m);
	mat_sum(tmp3, a3, a4, m);
	strassen(p3, tmp3, b1, m);

	int* tmp4 = allocate_matrix(m);
	mat_sub(tmp4, b3, b1, m);
	strassen(p4, a4, tmp4, m);

	int* tmp51 = allocate_matrix(m);
	int* tmp52 = allocate_matrix(m);
	mat_sum(tmp51, a1, a4, m);
	mat_sum(tmp52, b1, b4, m);
	strassen(p5, tmp51, tmp52, m);

	int* tmp61 = allocate_matrix(m);
	int* tmp62 = allocate_matrix(m);
	mat_sub(tmp61, a2, a4, m);
	mat_sum(tmp62, b3, b4, m);
	strassen(p6, tmp61, tmp62, m);

	int* tmp71 = allocate_matrix(m);
	int* tmp72 = allocate_matrix(m);
	mat_sub(tmp71, a1, a3, m);
	mat_sum(tmp72, b1, b2, m);
	strassen(p7, tmp71, tmp72, m);

	mat_sum(aux1,   p5, p4, m);
	mat_sub(aux1, aux1, p2, m);
	mat_sum(aux1, aux1, p6, m);
	mat_sum(aux2,   p1, p2, m);
	mat_sum(aux3,   p3, p4, m);
	mat_sum(aux4,   p1, p5, m);
	mat_sub(aux4, aux4, p3, m);
	mat_sub(aux4, aux4, p7, m);

	copy_submatrix(c1, aux1, m);
	copy_submatrix(c2, aux2, m);
	copy_submatrix(c3, aux3, m);
	copy_submatrix(c4, aux4, m);

	free(a1);free(a2);free(a3);free(a4);
	free(b1);free(b2);free(b3);free(b4);
	free(aux1);free(aux2);free(aux3);free(aux4);
	free(p1);free(tmp1);
	free(p2);free(tmp2);
	free(p3);free(tmp3);
	free(p4);free(tmp4);
	free(p5);free(tmp51);free(tmp52);
	free(p6);free(tmp61);free(tmp62);
	free(p7);free(tmp71);free(tmp72);
}

#endif
