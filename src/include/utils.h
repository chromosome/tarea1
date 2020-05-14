#ifndef UTILS_H
#define UTILS_H

int* read_binary_file(int* n, const char* file) {
	FILE *f;

	if ( !(f = fopen(file, "rb")) ) {
		printf("[Error]: No se puede abrir archivo.%s\n\n", file);
		return NULL;
	}

	fread(n, sizeof(int), 1, f);

	int* dest = (int*) malloc(*n*sizeof(int));
	fread(dest, sizeof(int), *n, f);

	fclose(f);

	return dest;
}

// int read_binary_file2(int** dest, char* file) {
// 	FILE *f;

// 	if ( !(f = fopen(file, "rb")) ) {
// 		printf("[Error]: No se puede abrir archivo.%s\n\n", file);
// 		return -1;
// 	}

// 	int n;
// 	fread(&n, sizeof(int), 1, f);

// 	dest = (int*) malloc(n*sizeof(int));
// 	fread(*dest, sizeof(int), n, f);

// 	fclose(f);

// 	return n;
// }

#endif