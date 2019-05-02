#include <algorithm>

#include "graph.hpp"

/* graph -- method implementations */

graph::graph (cloud &_c) {
  c = &_c;
  edge::set_cloud (c);
  
  size = c->get_n() * (c->get_n() - 1) / 2;

  edges = new edge*[size];
  int current_edge = 0;
  for (int i = 0; i < c->get_n(); i++)
    for (int j = 0; j < i; j++)
      if (i != j)
	edges[current_edge++] = new edge(i, j);

  std::sort(edges, edges+size, edge::compare);

  iterator_pos = 0;
}

graph::~graph() {
  for (int i = 0; i < size; i++)
    delete edges[i];
  
  delete[] edges;
}

void graph::start_iteration () {
  iterator_pos = 0;
}

edge *graph::get_next() {
  if (iterator_pos < size)
    return edges[iterator_pos++];
  else
    return NULL;
}

long graph::get_size() {
  return size;
}
