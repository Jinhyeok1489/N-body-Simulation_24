#pragma once
#include <string> //string class for set class
#include "particle.h"// particle class for set class
#include "force.h"// particle class for set class

using namespace std;

class Set//make a set of particles
{
private:
	Particle objParticle[];//particle instance
	Force objForce[];//force instance
					 //string setName;// name of a set

public:
	Set();//constructor
	void ps();//print informaiton of the set
	//void as();//make a set
	void ae(Particle objParticle_);//add a particle to the set
	void de(Particle objParticle_);//delete a particle from the set
	//void af(Force objForce_, double xForce, double yForce);//add a force to the set whose size is given as a vector (xForce, yForce)
};
