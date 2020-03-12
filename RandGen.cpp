#include "RandGen.hpp"

int RandGen::ourInitialized;

RandGen::RandGen(){
	if(!ourInitialized){
		ourInitialized = 1;
		time_t now;
		time(&now);
		srand(int((sin(double(now)) * 1000000)));
	}
}

int RandGen::randInt(int max){
	return int(randReal() * max);
}

int RandGen::randInt(int min,int max){
	return min + randInt(max - min + 1);
}
double RandGen::randReal(){
	return rand() / (double(RAND_MAX) + 1);
}

double RandGen::randReal(double min,double max){
	double width = fabs(max - min);
	double theMin = min < max ? min : max;
	return randReal() * width + theMin;
}
