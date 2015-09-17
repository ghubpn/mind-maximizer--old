#include "termsList.h"

TermsList::TermsList( string filename ) {
  loadTerms( filename );
}

void TermsList::loadTerms( string filename ) {
  // local variables
  string lineT;
  string lineD;
  bool   incomplete = true;
  int    current    = 1;
  Term   curTerm;
  // while EOF not reached
  while ( incomplete ) {
    if ( loadLine( filename, current, &lineT ) ) {
      ++current;
      if ( loadLine( filename, current, &lineD ) ) {
        curTerm.term       = lineT;
        curTerm.definition = lineD;
        terms.push_back( curTerm );
        current += 2;
      } else
        incomplete = false;
    } else
      incomplete = false;
  }
}

string TermsList::getTerm( int i ) {
  return terms[i].term;
}

string TermsList::getDef( int i ) {
  return terms[i].definition;
}

int TermsList::listSize() {
  return terms.size();
}
