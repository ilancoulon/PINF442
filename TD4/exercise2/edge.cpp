#include "edge.hpp"

/* edge -- method implementations */

cloud *edge::c = NULL;
int edge::comp_count = 0;

bool edge::set_cloud (cloud *_c) {
  if (c != NULL)
    return false;

  c = _c;
  return true;
}

double edge::dist (edge *e) {
  return c->get_point(e->s).dist(c->get_point(e->t));
}

bool edge::compare (edge* e1, edge *e2) {
  inc_comp_count();		// for testing only
  return edge::dist(e1) < edge::dist(e2);
}

int edge::get_comp_count() {
  return comp_count;
}

void edge::inc_comp_count() {
  comp_count++;
}
