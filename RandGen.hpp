#ifndef RANDGEN_H
#define RANDGEN_H
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <math.h>

class RandGen{
	public:
		RandGen();
		int randInt(int max = INT_MAX);
		int randInt(int min,int max);
		double randReal();
		double randReal(double min,double max);
	private:
		static int ourInitialized;
};

#endif

