#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include "common.h"

void selection_sort (int* v, int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (v[i] < v[j])
				swap(v+i, v+j);
}

void bubble_sort (int* v, int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n-1; ++j)
			if (v[j] > v[j+1])
				swap(v+j, v+j+1);
}

void insertion_sort (int* v, int n) {
	for (int i = 0; i < n; ++i)
		for (int j = i; j > 0; --j)
			if (v[j] < v[j-1])
				swap(v+j, v+j-1);
}

void merge_sort (int* v, int n) {
	if (n == 1)
		return;

	int* vl = v;
	int* vh = v+n/2;
	int  nl = n/2;
	int  nh = n-n/2;

	merge_sort(vl, nl);
	merge_sort(vh, nh);

	int* aux = merge(vl, nl, vh, nh);
	copy_array(v, aux, n);
	free(aux);
}

void quick_sort (int* v, int n) {
	if (n == 1 || n == 0)
		return;

	int p = partition(v, n);

	quick_sort(v, p);
	quick_sort(v+p+1, n-p-1);
}

#endif
