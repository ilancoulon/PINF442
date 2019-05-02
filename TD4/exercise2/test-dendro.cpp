#include <iostream>
#include <fstream>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for rand seed

#include "dendrogram.hpp"
#include "test-dendro.hpp"

using std::cout; using std::endl;

test_dendro::test_dendro (dendrogram &_dg) {
  dg = &_dg;
}

int test_dendro::get_rank(int i) {
  return dg->rank[i];
}

int test_dendro::get_parent (int i) {
  return dg->parent[i];
}

int test_dendro::trace_find (int i) {
  int p = dg->parent[i];

  cout << get_rank(i) << "\t";
  print_point(i);
  cout << "\t";
  print_point(p);
  cout << endl;
  
  if (p == i)
    return i;
  
  return trace_find(p);
}

void test_dendro::print_point (int i) {
  cout << i << " (";
  dg->c->get_point(i).print();
  cout << ")";
}

int main (int argc, char *argv[]) {
  srand (time(NULL));
  
  if (argc < 2) {
    cout << "Please provide data file"
	 << " -- this test expects 'iris.data'!"
	 << endl;
    return 0;
  }

  
  const int d = (argc > 2) ? std::stoi(argv[2]) : 4;
  const int nmax = (argc > 3) ? std::stoi(argv[3]) : 150;

  cloud c(d, nmax);

  std::ifstream is(argv[1]);
  assert(is.is_open());

  c.load(is);
  is.close();

  cout << "Loaded "
       << c.get_n()
       << " points from "
       << argv[1];
  cout << ((c.get_n() == nmax) ? "\t[OK]" : "\t[NOK]") << endl;
  if (c.get_n() != nmax)
    cout << "Must have loaded " << nmax << " points" << endl;
  
  dendrogram dg (c);
  test_dendro tdg (dg);
  
  int depth = dg.get_depth();
  cout << "Depth of the dendrogram:\t"
       << depth
       << ((depth == 4) ? "\t[OK]" : "\t[NOK]") << endl;
  if (depth != 4)
    cout << "The depth of the dendrogram should be 4 (for 'iris.data')" << endl;
  

  cout << "Printing traces to root from 10 random points..." << endl;
  cout << "Rank\tpoint\tparent" << endl;
  for (int i = 0; i < 10; i++) {
    int node = rand() % c.get_n();
    tdg.trace_find(node);
    cout << endl;
  }

  for (int dp = depth; dp >= 0; dp--) {
    bool flag = true;
    cout << "Testing labels at depth " << dp;
    dg.clear_labels();
    for (int i = 0; i < c.get_n(); i++) {
      dg.find(i, dp);
      if (tdg.get_rank(i) == depth - dp &&
	  c.get_point(i).label != i) {
	flag = false;
	break;
      }
    }
    cout << "\t\t" << (flag ? "[OK]" : "[NOK]") << endl;
    if (!flag)
      cout << "The labelling mechanism in 'int find (int i, int depth)'" << endl
	   << "    must ensure that cluster representatives are labelled" << endl
	   << "    by their own ids" << endl;

    dg.print_clusters();
  }
  cout << endl;
  
  cout << "Printing points by rank..." << endl;
  cout << "point\tparent\trank" << endl;
  for (int dp = 0; dp <= depth; dp++) {
    for (int i = 0; i < c.get_n(); i++) 
      if (tdg.get_rank(i) == depth - dp) {
	tdg.print_point(i);
	cout << "\t";
	tdg.print_point(tdg.get_parent(i));
	cout << "\t"
	     << tdg.get_rank(i) << endl;
      }
    cout << endl;
  }


  return 0;
}
