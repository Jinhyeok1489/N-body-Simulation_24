#pragma once
class Time//make time class
{
private:
	double cTime;//current time
	double tick;//time(sec) interval

public:
	Time(double tick_ = 1.0);// construct timetick(sec)
	void ct(double tick_);//change timetick(sec)
	void pt();//print the current time

};