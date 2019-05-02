#pragma once // single incl.

#include "point.hpp"

class cloud
{
private:
  int d;
  int n;
  int k;

  // maximum possible number of points
  int nmax;

  point *points;
  point *centers;

public:
  cloud(int _d, int _nmax, int _k);
  ~cloud();

  // Getters
  
  int get_d();
  int get_n();
  int get_k();

  point& get_point(int i);
  point& get_center(int j);

  // Setters
  
  void set_center(point &p, int j);

  // Helper methods
  
  void add_point(point &p, int label);

  double intracluster_variance();

  void set_voronoi_labels();
  void set_centroid_centers();

  void kmeans();

  // Cluster initialisation options
  
  void init_forgy();
  void init_plusplus();
  void init_random_partition();
};
