#pragma once
#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

struct Particle_s {
	double mass;
	double position[2] = {}; //[0]: x component, [1]: y component
	double velocity[2] = {}; //[0]: x component, [1]: y component
	bool cp = true;//fixation///////////////////////////////////////////////////////////////////////////////////////����
};

class Particle//saves characteristic of particles 
{
private:
public:
	std::map<int, Particle_s> part_info;////////////////////////////////////////////////////////////////////////////////����
	//Particle(int num, double mass_, double x_position, double y_position, double x_velocity = 0, double y_velocity = 0);
	//constructor of particle, parameter goes to member variable
	Particle();

	void print_particle(int num);//print out information of particles
	void delete_particle(int num); //this function removes particle
	//void cp(bool TorF = true);//parameter: bool, if true, particle fixed, else not fixed ///////////////////////////����
	void print_all(); //this function prints all of the information of particle
	void Particle::var_set(double* list);
};
