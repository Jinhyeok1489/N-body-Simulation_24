#pragma once
#include <string> //string class for set class
#include <map>
#include "particle.h"// particle class for set class
#include <iostream>
//#include "force.h"// particle class for set class

struct Force {
	int num;
	double force[2]; //force! [0]: x_component, [1]: y_component
};
class Set//make a set of particles
{
private:
	Particle *particle;
	Force *force;
public:
	Set(int num);//constructor
	void ps(Set set);//print informaiton of the set
					 //void as();//make a set
	void to_set(int num);//add a particle to the set
	void de(Particle objParticle_);//delete a particle from the set
	void af(Force objForce_, double xForce, double yForce);//add a force to the set whose size is given as a vector (xForce, yForce)
};
