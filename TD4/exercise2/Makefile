main: cloud MyArea cloud-run.cpp
	g++ -std=c++11 -o cloud-run cloud-run.cpp *.o `pkg-config gtkmm-3.0 --cflags --libs`

point: point.cpp point.hpp
	g++ -c point.cpp

cloud: point cloud.cpp cloud.hpp
	g++ -c cloud.cpp

graph: cloud graph.cpp graph.hpp edge.cpp edge.hpp
	g++ -c graph.cpp edge.cpp

dendrogram: graph dendrogram.cpp dendrogram.hpp
	g++ -c dendrogram.cpp

test-graph: graph test-graph.cpp
	g++ -o test-graph test-graph.cpp *.o

test-dendrogram: dendrogram test-dendro.cpp test-dendro.hpp
	g++ -o test-dendro test-dendro.cpp *.o

all-tests: test-graph test-dendrogram

MyArea: cloud MyArea.cpp MyArea.hpp
	g++ -std=c++11 -c MyArea.cpp `pkg-config gtkmm-3.0 --cflags --libs`

clean:
	rm -vf test-graph test-dendro cloud-run *.o *~
