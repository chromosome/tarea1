# set -e

build() {
	make TARGETS="$1"
}

build_sort() {
	# for target in $(ls ./src/*.c | basename -s .c ./src/*.c); do
	targets=("bubble_sort" "insertion_sort" "selection_sort" 
			 "merge_sort" "quick_sort")
	for target in ${targets[@]}; do
		# make TARGETS="$target"
		build $target
	done
}

build_matrix() {
	targets=("cubic" "transpose" "strassen")
	# targets=("cubic")
	for target in ${targets[@]}; do
		# make TARGETS="$target"
		build $target
	done
}

build_all() {
	build_sort
	build_matrix
}
