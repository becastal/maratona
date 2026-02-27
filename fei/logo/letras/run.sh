bash make.sh

printf "" > pontos
for i in letra?
	do
		./pp < $i >> pontos
	done

printf "\n" >> pontos
for i in _letra*
	do
		./pp < $i >> pontos
	done

printf "" > arestas
for i in letra?
	do
		./pa < $i >> arestas
	done

printf "\n" >> arestas
for i in _letra*
	do
		./pa < $i >> arestas
	done
