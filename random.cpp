#include "random.h"

using namespace std;

Random::Random()
{
	srand (time(NULL));
}

bool Random::randBool()
{
	return (rand() % (int)(2));
}

int Random::randInt(int min, int max)
{
	return min + (rand() % (int)(max - min + 1));
}

float Random::randFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max-min)));
}

void Random::permuteInts( int* array, int n ) {
	int r;
	int temp;
	for ( int i = 0; i < n; ++i ) {
		r        = randInt( i, n-1 );
		temp     = array[r];
		array[r] = array[i];
		array[i] = temp;
	}
}
