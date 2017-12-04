#pragma once
class Particle//saves characteristic of particles 
{
private:

	double mass; //mass of particle
	double position[2];//position of particle consist of [x axis, y axis] array 
	double velocity[2];//velocity of particle consist of [x vector, y vector] array 

public:
	Particle(double mass_, double x_position, double y_position, double x_velocity = 0, double y_velocity = 0);
	//constructor of particle, parameter goes to member variable
	void pp(Particle particle);//print out information of particles
	void dp(Particle particle);//remove particle 
	void cp(bool TorF = true);//parameter: bool, if true, particle fixed, else not fixed 
};