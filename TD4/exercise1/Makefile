main: cloud MyArea cloud-run.cpp
	g++ -std=c++11 -o cloud-run cloud-run.cpp *.o `pkg-config gtkmm-3.0 --cflags --libs`

point: point.cpp point.hpp
	g++ -c point.cpp

cloud: point cloud.cpp cloud.hpp
	g++ -c cloud.cpp

cloud-tests: point cloud cloud-tests.cpp
	g++ -o cloud-tests cloud-tests.cpp point.o cloud.o

MyArea: cloud MyArea.cpp MyArea.hpp
	g++ -std=c++11 -c MyArea.cpp `pkg-config gtkmm-3.0 --cflags --libs`

clean:
	rm -vf cloud-tests cloud-run *.o *~
