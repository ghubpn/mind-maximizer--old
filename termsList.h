#ifndef TERMSLIST_H
#define TERMSLIST_H

#include <vector>
#include <string>

#include "fileIO.h"

using namespace std;

class TermsList {
  class Term {
    friend class TermsList;
    string term;
    string definition;
  };
private:
  vector<Term> terms;
  void loadTerms( string filename );
public:
  TermsList( string filename );
  string getTerm( int i );
  string getDef( int i );
  int    listSize();
};

#endif
