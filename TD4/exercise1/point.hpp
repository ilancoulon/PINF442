#pragma once // single incl.

class point
{
public:
  static int d;
  double *coords;
  int label;
  
  point ();
  ~point ();

  void print();
  double dist (point &q);
};
