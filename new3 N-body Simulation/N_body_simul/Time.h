//headerguard
#ifndef TIME_H
#define TIME_H

#include "Set.h"
#include "Particle.h"

using namespace std;

class Time//make time class
{
private:
	double tick;//time(sec) interval
	double cur_t;

public:
	bool vis;//boolean for visualization
	bool cg;//boolean for gracity

	Time();// construct time class//////////////////////////////////////////////////////////////////////////////////////////////////
	void ru(double duration, Set* set_all_);///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void ct(double tick_ = 1.0);//change timetick(sec)
	void pt();//print the current time
	

};

#endif