#pragma once // single incl.

#include "word.hpp"

using std::string;

class dataset
{
private:
  word *words;
  int numberOfWords;
  int n;

  string filename;

  void buildWordsFromFile();
  void addWord(word newWord);
  int numberOfWordsInThisFile();



public:
  dataset(string _filename);
  ~dataset();


};
