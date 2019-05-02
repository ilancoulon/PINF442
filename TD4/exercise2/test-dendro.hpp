#pragma once

#include "dendrogram.hpp"

class test_dendro {
  dendrogram *dg;

public:
  test_dendro (dendrogram &_dg);

  int get_rank (int i);
  int get_parent (int i);
  int trace_find (int i);
  void print_point (int i);
};
