#include "cloud.hpp"

/* edge -- pairs of cloud point indices with methods to
 *  - compute the distance from source to target
 *  - compare the lengths of two edges -- needed for sorting
 */

class edge {
  int  s, t;

  static cloud *c;  
  static int comp_count;	// For testing only
  
public:
  edge(int _s, int _t) {
    assert( c != NULL );
    assert( _s >= 0 && _s < c->get_n() );
    assert( _t >= 0 && _t < c->get_n() );

    s = _s;
    t = _t;
  }

  static bool set_cloud (cloud *_c);

  int get_source() { return s; }
  int get_target() { return t; }
  
  static double dist (edge *e);
  static bool compare (edge* e1, edge *e2);

  static int get_comp_count();
  static void inc_comp_count();
};
