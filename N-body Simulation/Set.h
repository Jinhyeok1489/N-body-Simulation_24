#pragma once
#include <string> //string class for set class
#include <map>
#include "particle.h"// particle class for set class
#include <iostream>
//#include "force.h"// particle class for set class

struct Force {
	double force[2]{}; //force! [0]: x_component, [1]: y_component / force is always initialized as 0
};
class Set//make a set of particles
{
private:
	//std::map<int , Particle* > indiv_set_info; //map indiv_set_info saves information of type Particle (class)
//	std::map<int, std::map<int, Force *>> force_info;//map force_info saves information of type Force (struct)
	std::map<int, int> fs_relation; //map saves force_set information for convenient
	Force* temp = new Force; //temporary variable to make a force
public:
	std::map<int, std::map<int, Particle_s>> all_set_info; //map all_set_info saves information of type map of Particle(already map)
	std::map<int, std::map<int, Force *>> force_info;//map force_info saves information of type Force (struct)
	Set();
	Set(int num);//constructor

	void Set::indiv_set_make(int part_num, int set_num, Particle ** particle_add, Set* set_info);
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
	void Set::print_set(int num);
	/** this function prints out information of set
	/* int num : key of set
	*/
	void Set::delete_p_to_s(int set_num, int part_num);
	/** this function deletes particle from the set, never its existence
	/* int set_num: key of set
	/* int part_num: key of particle
	*/

	void Set::impose_force(int force_num, int set_num, double x_comp, double y_comp);
	/** this function make us a new force
	/* int force_num: name of force, key of force
	/* int set_num: name of set, where to force is imposed
	/* double x_comp: x component of force
	/* double y_comp: y component of force
	/* Return type: int type which points where force is imposed
	*/

	void Set::print_force(int force_num);
	/** this function prints out information of force
	/* int force_num: name of force, key of force
	*/

	void Set::delete_force(int force_num);
	/** this function deltes force and memory delocation
	/* int force_num: name of force, key of force
	*/

	/*
	void ps(Set set);//print informaiton of the set
					 //void as();//make a set
	void to_set(int num);//add a particle to the set
	void de(Particle objParticle_);//delete a particle from the set
	void af(Force objForce_, double xForce, double yForce);//add a force to the set whose size is given as a vector (xForce, yForce)
	*/
};
