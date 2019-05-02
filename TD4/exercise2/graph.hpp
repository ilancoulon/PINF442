#include "cloud.hpp"
#include "edge.hpp"

/*  graph -- a array of edges arranged by
 *  increasing length.  Allows iteration:
 *
 *  init_iteration() places current at
 *    the start of the array
 *  get_next() returns the current edge
 *    and advances to the next one
 */
class graph {
  cloud *c;
  edge **edges;

  long size;
  int iterator_pos;

public:
  graph (cloud &_c);
  ~graph ();

  void start_iteration();
  edge *get_next();
  
  long get_size();
};
  
  
  
