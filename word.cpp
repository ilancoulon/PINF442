#include <iostream>
#include <cassert>
#include <cfloat>	// for DBL_MAX
#include <fstream>
#include <string>
using namespace std;

#include "word.hpp"

word::word(string firstL, string secondL, string thirdL)
{
  description = firstL;
  acids = secondL;


  cleavageSite = getCleavageSiteFromString(thirdL);
  cout << thirdL << endl;
  cout << cleavageSite << endl;
}
word::word() {

}

word::~word()
{

}

int word::getCleavageSiteFromString(string thirdL) {
  int l = thirdL.length();
  int toReturn;

  for (int i = 0; i < l; i++) {
    if (thirdL[i] == 'C') {
      toReturn = i;
      i = l;
    }
  }

  return toReturn;
}
