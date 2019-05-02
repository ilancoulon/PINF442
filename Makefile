main: dataset word main.cpp
	g++ -std=c++11 -o project main.cpp *.o

word: word.hpp word.cpp
	g++ -c word.cpp

dataset: word dataset.hpp dataset.cpp
	g++ -c dataset.cpp

clean:
	rm -vf test-graph test-dendro cloud-run *.o *~
