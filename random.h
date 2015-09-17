#ifndef RANDOM_H
#define RANDOM_H

#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Random
{
	public:
		// ctor/dtor
		Random();
		
		// pseudo-random generators
		bool  randBool();
		int   randInt(int min, int max);
		float randFloat(float min, float max);
		void  permuteInts( int* array, int n );

};

#endif