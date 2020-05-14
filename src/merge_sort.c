#include "sorting.h"
#include "utils.h"

int main(int argc, char const *argv[])
{
	if (argc < 0) {
		printf("[Error]: Se necesita archivo de entrada.\n");
		return 0;
	}

	int n;
	int* a = read_binary_file(&n, argv[1]);

	double t = high_res_profile(a, n, merge_sort);
	printf("%i:%f\n", n, t/1e6);

	return 0;
}