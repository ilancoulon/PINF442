#include <iostream>
#include <cfloat>	// for DBL_MAX
#include <fstream>

#include "graph.hpp"

using std::cout; using std::endl;

int main (int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Please provide a data file"
	 << " -- this test expects 'iris.data'!"
	 << endl;
    return 0;
  }
  
  const int d = 4;
  const int nmax = 150;

  cloud c(d, nmax);

  std::ifstream is(argv[1]);
  assert(is.is_open());

  c.load(is);
  is.close();

  cout << "Loaded "
       << c.get_n()
       << " points from "
       << argv[1];
  cout << ((c.get_n() == 150) ? "\t[OK]" : "\t[NOK]") << endl;
  if (c.get_n() != 150)
    cout << "Must have loaded 150 points" << endl;

  graph g (c);
  cout << "Initialisation of the complete graph\t[OK]" << endl;
  cout << "Expected graph size:\t" << g.get_size() << endl;
  
  int count = 0;
  int comp_count = edge::get_comp_count();
  edge *e;
  
  g.start_iteration();
  while ((e = g.get_next()) != NULL) {
    count++;
  }
  cout << "Actual graph size:\t" << count;
  assert(g.get_size() == count);
  cout << "\t\t[OK]" << endl;
  cout << "Number of edge comparisons for sorting:\t"
       << comp_count << endl;
  
  g.start_iteration();
  edge *e1 = g.get_next();
  edge *e2;

  double min = edge::dist(e1);
  double max = min;
  
  g.start_iteration();  
  while (e1 != NULL && (e2 = g.get_next()) != NULL) {
    if (edge::compare(e2, e1)) {
      cout << "Edge sorting failed!!" << endl;
      break;
    }

    double d = edge::dist(e2);
    if (d < min)
      min = d;

    if (d > max)
      max = d;
    
    e1 = e2;
  }

  if (e2 == NULL) {
    cout << "Edge sorting\t\t\t\t[OK]" << endl;
    cout << "Number of edge comparisons for testing:\t"
	 << edge::get_comp_count() - comp_count << endl;

    cout << "Min distance between points:\t" << min << endl;
    cout << "Max distance between points:\t" << max << endl;
    cout << "Last distnace between points:\t" << edge::dist(e1) << endl;
  }
  return 0;
}
