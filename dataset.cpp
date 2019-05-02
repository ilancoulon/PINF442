#include <iostream>
#include <cassert>
#include <cfloat>	// for DBL_MAX
#include <fstream>


#include "dataset.hpp"

using std::ifstream;
using std::string;

dataset::dataset(string _filename)
{
  filename = _filename;
  numberOfWords = numberOfWordsInThisFile();
  n = 0;

  words = new word[numberOfWords];

  buildWordsFromFile();
}

dataset::~dataset()
{

}

void dataset::buildWordsFromFile() {
  // open data file
  ifstream is(filename.c_str());
  assert(is.is_open());

  int i = 0;
  string *lines = new string[3];
  string line;
  while (getline (is,line)) {
    lines[i] = line;

    if (i == 2) {
      i = 0;
      word *newWord = new word(lines[0], lines[1], lines[2]);
      addWord(*newWord);
    } else {
      i++;
    }
  }
  is.close();
}

void dataset::addWord(word newWord) {
  words[n] = newWord;
  n++;
}

int dataset::numberOfWordsInThisFile() {
  ifstream is(filename.c_str());
  assert(is.is_open());

  string line;
  int count = 0;

  while (getline(is, line))
    count++;

  is.close();

  return count/3;
}
