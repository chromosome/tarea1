# from random import random, uniform, randint, sample

# n = 100
# print(sample(range(0, n), n))

def write_array_data(n):
	import numpy as np
	a = np.random.choice(n, n, replace=False)
	d = np.concatenate([[n], a])
	print(d)
	d.astype('int32').tofile(f"data/sort/{n}.dat")

def write_matrix_data(n):
	import numpy as np
	a = np.random.choice(n**2, n**2, replace=False)
	d = np.concatenate([[n], a])
	print(d)
	d.astype('int32').tofile(f"data/matrix/{n}.dat")


def write_array_files():
	array_sizes = [100, 200, 300, 400, 500, 
				   1000, 2000, 3000, 4000, 5000,
				   10000, 20000, 30000, 40000, 50000,
				   100000, 200000, 300000, 400000, 500000,
				   1000000, 2000000, 3000000, 4000000, 5000000,
				   10000000]
	for n in array_sizes:
		write_array_data(n)

def write_matrix_files():
	strassen_sizes = [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096]
	for n in strassen_sizes:
		write_matrix_data(n)


if __name__ == '__main__':
	write_array_files()
	write_matrix_files()