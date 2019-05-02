#pragma once

#include "graph.hpp"

class dendrogram {
  cloud *c;
  graph *g;

  int *parent;
  int *rank;
  
  void merge (int i, int j);

  void build ();
public:
  dendrogram (cloud &_c);
  ~dendrogram ();
  
  int find (int i);

  int get_depth ();

  int find (int i, int depth);
  void set_labels (int depth);
  void clear_labels ();

  void print_clusters ();	// For testing only
    
  friend class test_dendro;
};
