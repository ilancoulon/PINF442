#include <iostream>

#include "dendrogram.hpp"

using std::cout; using std::endl;

dendrogram::dendrogram (cloud &_c) {
  c = &_c;
  g = new graph (_c);

  parent = new int[c->get_n()];
  rank = new int[c->get_n()];

  for (int i = 0; i < c->get_n(); i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  build();
}

dendrogram::~dendrogram() {
  delete[] parent;
  delete[] rank;
}

void dendrogram::clear_labels () {
  for (int i = 0; i < c->get_n(); i++) {
    c->get_point(i).label = 0;
  }
}

int dendrogram::get_depth () {
  return rank[find(0)]; // Only one root
}

int dendrogram::find (int i) {
  int p = parent[i];

  if (p == i)
    return i;
  
  return find(p);
}

void dendrogram::merge (int i, int j) {
  int ci = find(i);
  int cj = find(j);

  if (ci == cj)	return;		// Already the same cluster
  
  if (rank[ci] < rank[cj]) {
    parent[ci] = cj;
  }
  else {
    parent[cj] = ci;

    if (rank[ci] == rank[cj])
      rank[ci]++;
  }
}

void dendrogram::build () {
  g->start_iteration ();

  edge *e; 
  while ((e = g->get_next()) != NULL) {
    merge (e->get_source(), e->get_target());
  }

}

int dendrogram::find (int i, int depth) {
  if (c->get_point(i).label != 0)
    return c->get_point(i).label; // Label already set

  int p = parent[i];

  if (p == i || (get_depth() - rank[p]) < depth)
    return c->get_point(i).label = i;

  return c->get_point(i).label = find (p, depth);
}

void dendrogram::set_labels (int depth) {
  for (int i = 0; i < c->get_n(); i++) {
    find (i, depth);
  }
}

void dendrogram::print_clusters () { // For testing only
  for (int start = 0; start < c->get_n(); start++) {
    int cluster = c->get_point(start).label;
    if (cluster < 0)
      continue;
    
    cout  << "Cluster " << cluster << endl;
    
    for (int i = start; i < c->get_n(); i++) {
      if (c->get_point(i).label == cluster) {
	cout << i << " (";
	c->get_point(i).print();
	cout << ")" << endl;
	
	c->get_point(i).label = -1;
      }
    }
  }
}

