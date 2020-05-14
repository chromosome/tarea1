#include "matrix_mult.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
	if (argc < 0) {
		printf("[Error]: Se necesita archivo de entrada.\n");
		return 0;
	}

	int n;
	int* a = read_binary_mat_file(&n, argv[1]);
	int* b = read_binary_mat_file(&n, argv[1]);
	int* c = allocate_matrix(n);

	double t = high_res_mat_profile(c, a, b, n, row_major_mult);
	printf("%i:%f\n", n, t/1e6);

	return 0;
}
