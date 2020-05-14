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

int* read_binary_mat_file(int* n, const char* file) {
	FILE *f;

	if ( !(f = fopen(file, "rb")) ) {
		printf("[Error]: No se puede abrir archivo.%s\n\n", file);
		return NULL;
	}

	fread(n, sizeof(int), 1, f);

	int* dest = (int*) malloc((*n)*(*n)*sizeof(int));
	fread(dest, sizeof(int), (*n)*(*n), f);

	fclose(f);

	return dest;
}

#endif