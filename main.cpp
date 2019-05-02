#include <iostream>
#include <cassert>
#include <cfloat>	// for DBL_MAX
#include <fstream>

#include "word.hpp"
#include "dataset.hpp"

using std::ifstream;
using std::cout; using std::endl;

int main(int argc, char **argv)
{
  dataset *data = new dataset("EUKSIG_13.red");
}
