set -e

run() {
	cat /dev/null > ./results/"$1"
	for file in $(ls ./data/sort | sort -n); do
		bin/$1 ./data/sort/$file >> ./results/"$1"
	done
}

mkdir -p ./results
targets=$(ls --ignore=*.o bin/)
for target in $targets; do
	echo $target
	time run $target
done
