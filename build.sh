set -e

# targets=$(ls ./src/*.c | basename -s .c ./src/*.c | paste -sd " ")
# make TARGETS="$targets"

for target in $(ls ./src/*.c | basename -s .c ./src/*.c); do
	make TARGETS="$target"
done
