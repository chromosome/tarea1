set -e

for target in $(ls ./src/*.c | basename -s .c ./src/*.c); do
	make TARGETS="$target"
done
