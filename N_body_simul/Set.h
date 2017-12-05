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
	Particle *particle; //class variable particle saves instnace particle
	Force *force; // struct variable force saves struct force
	
	std::map<int , Particle* > indiv_set_info; //map indiv_set_info saves information of type Particle (class)
	std::map<int, Force*> force_info; //map force_info saves information of type Force (struct)
	std::map<int, std::map<int, Particle* >> all_set_info; //map all_set_info saves information of type map of Particle(already map)
public:
	Set();
	Set(int num);//constructor

	void Set::indiv_set_make(int part_num, int set_num, std::map<int,Particle_s> * particle_add, std::map<int, std::map<int, Particle_s>> set_info);
	/** this function help us to save particle into set
	/* int part_num : this int variable notice which particle to be added into set 
	/* int set_num : this int variable notice which set to have new particle
	/* std::map<int,Particle_s> * particle_add : this variable points to map of particle->makes set
	/* std::map<int, std::map<int, Particle_s>> set_info : this variable is a big map which takes set->makes map of map
	*/
	void Set::big_set_make(int set_num, std::map<int, std::map<int, Particle_s> > set_info); 
	/** this function will make a new set
	/* int set_num : key of set
	/* std::map<int, std::map<int, Particle_s>> set_info : this variable is map of map
	*/
	void ps(Set set);//print informaiton of the set
					 //void as();//make a set
	void to_set(int num);//add a particle to the set
	void de(Particle objParticle_);//delete a particle from the set
	void af(Force objForce_, double xForce, double yForce);//add a force to the set whose size is given as a vector (xForce, yForce)
	*/
};
