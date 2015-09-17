#include "quiz.h"

Quiz::Quiz( string filename ) {
  r       = new Random();
  terms   = new TermsList( filename );
  correct = 0;
  total   = 0;
}

void Quiz::run() {
  // local variables
  string command = "";
  // while quit command not entered
  while ( command != "q!" ) {
    // run next question
    command = nextQuestion();
  }
}

string Quiz::nextQuestion() {
  // local variables
  int    answer;
  int    decoy1;
  int    decoy2;
  int    decoy3;
  // set answer from terms list
  answer = r->randInt( 0, terms->listSize() - 1 );
  // set decoy1 from terms list != answer
  do {
    decoy1 = r->randInt( 0, terms->listSize() - 1 );
  } while ( decoy1 == answer );
  // set decoy2 from terms list != answer and != decoy1
  do {
    decoy2 = r->randInt( 0, terms->listSize() - 1 );
  } while ( decoy2 == answer || decoy2 == decoy1 );
  // set decoy3 from terms list != answer and != decoy1 and != decoy2
  do {
    decoy3 = r->randInt( 0, terms->listSize() - 1 );
  } while ( decoy3 == answer || decoy3 == decoy1 || decoy3 == decoy2 );
  // print question
  printQuestion( answer, decoy1, decoy2, decoy3 );
  // check attempt
  return checkAttempt( answer );
}

void Quiz::printQuestion( int answer, int decoy1, int decoy2, int decoy3 ) {
  // local variables
  int choices[] = { answer, decoy1, decoy2, decoy3 };
  // permute choices
  r->permuteInts( choices, 4 );
  // print question
  cout << endl << terms->getDef(answer) << endl;
  // print choices
  cout << terms->getTerm(choices[0]) << endl;
  cout << terms->getTerm(choices[1]) << endl;
  cout << terms->getTerm(choices[2]) << endl;
  cout << terms->getTerm(choices[3]) << endl;
  cout << endl;
}

string Quiz::checkAttempt( int answer ) {
  // local variables
  string selection;
  // get user selection
  cin >> selection;
  // if quit not selected
  if ( selection != "q!" ) {
    // print correct answer
    cout << terms->getTerm(answer) << endl;
    // if user selection equals answer, increment correct count
    if ( selection == terms->getTerm(answer) )
      ++correct;
    // increment total count
    ++total;
  // if quit selected, print quit message
  } else
    cout << "Quit selected" << endl;
  // print score
  cout << "Score: " << correct << "/" << total << endl;
  // return user input
  return selection;
}
