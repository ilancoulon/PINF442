#pragma once // single incl.

using namespace std;


class word
{
private:
  std::string description;
  std::string acids;
  int cleavageSite;

  int getCleavageSiteFromString(string thirdL);

public:
  word();
  word(string firstL, string secondL, string thirdL);
  ~word();


};
