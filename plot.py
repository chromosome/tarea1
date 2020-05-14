import matplotlib.pyplot as plt
import numpy as np
from scipy.interpolate import make_interp_spline, BSpline

def read_data(name):
	with open(name) as f:
		n = []
		t = []
		for line in f.read().splitlines():
			x, y = line.split(':')
			n.append(float(x))
			t.append(float(y))
	return np.array(n), np.array(t)

def plot(data_name):

	pass

if __name__ == '__main__':
	path = 'results/'
	# programs = ['selection_sort', 'bubble_sort', 'insertion_sort', 
	# 			'merge_sort', 'quick_sort']
	programs = ['merge_sort', 'quick_sort']
	# programs = ['selection_sort', 'bubble_sort', 'insertion_sort']

	fig, ax = plt.subplots()
	fig.suptitle('Algoritmos de ordenamiento')
	for program in programs:
		n, t = read_data(path+program)
		# x, y = n, t
		x = np.linspace(n.min(), n.max(), 1000)
		spline = make_interp_spline(n, t, k=1)
		y = spline(x)
		ax.plot(x, y, label=program.replace("_", " "))

	plt.legend(loc="upper left")
	# plt.yscale('linear')
	# plt.xscale('log')
	# plt.show()
	plt.savefig('sort.png')