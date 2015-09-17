#ifndef QUIZ_H
#define QUIZ_H

#include "termsList.h"
#include "random.h"

using namespace std;

class Quiz {
  class Question {
    friend class Quiz;
    string question;
    string answer;
    string choices[4];
  };
private:
  Random*    r;
  TermsList* terms;
  Question   current;
  int        correct;
  int        total;
  string     nextQuestion();
  void       printQuestion( int answer, int decoy1, int decoy2, int decoy3 );
  string     checkAttempt( int answer );
public:
  Quiz( string filename );
  void run();

};

#endif
