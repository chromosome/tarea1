#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <time.h>

typedef void (*sort_t) (int* v, int n);

int profile (int* v, int n, sort_t sort) {
	clock_t start = clock();

	sort(v, n);

	return (clock() - start)*1000/CLOCKS_PER_SEC;
}

double high_res_profile (int* v, int n, sort_t sort) {
	struct timespec start, stop;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	sort(v, n);

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

	double result = (stop.tv_sec - start.tv_sec) * 1e6 
				  + (stop.tv_nsec - start.tv_nsec) / 1e3;
	return result;
}

void print_array (int* v, int n) {
	printf("[");
	for (int i = 0; i < n-1; ++i)
		printf("%i, ", v[i]);
	printf("%i]", v[n-1]);
}

void print_named_array (int* v, int n, char* name) {
	printf("%s: ", name);
	print_array(v, n);
	printf("\n");
}

void copy_array (int* dst, int* src, int n) {
	for (int i = 0; i < n; ++i)
		dst[i] = src[i];
}

void swap (int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void swap2 (int* v, int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int* merge (int* a, int na, int* b, int nb) {
	int* v = (int*) malloc((na+nb)*sizeof(int));
	for (int i = 0, ia = 0, ib = 0; i < na+nb; ++i) {
		if ((ib == nb || a[ia] < b[ib]) && ia < na) {
			v[i] = a[ia]; ++ia;
		}
		else {
			v[i] = b[ib]; ++ib;
		}
	}
	return v;
}

int partition (int* v, int n) {
	int f = 1;
	for (int i = 2; i < n; ++i) {
		if (v[i] < v[0]) {
			if (v[i] < v[f])
				swap(v+f, v+i);
			++f;
		}
		else if (v[f] < v[0] && v[f] < v[i])
			++f;
	}

	if (v[0] > v[f]) {
		swap(v, v+f);
		return f;
	}
	else if (v[0] > v[f-1])
		swap(v, v+f-1);

	return f-1;
}

#endif
