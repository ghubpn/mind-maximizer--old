#include "quiz.h"
#include "fileIO.h"
#include "random.h"

#include <iostream>

using namespace std;
int main() {
	//Question* q = new Question( "question", "answer", "decoy1", "decoy2", "decoy3" );
	/*
	int ar[] = {0,1,2,3};
	Random r;
	r.permuteInts(ar, 4);
	cout << ar[0] << endl;
	cout << ar[1] << endl;
	cout << ar[2] << endl;
	cout << ar[3] << endl;
	cout << endl;
	*/
	Quiz* q = new Quiz( "list.txt" );
	cout << endl;
	q->run();
	cout << endl;
}
