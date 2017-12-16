#pragma once
#include <string> //string class for set class
#include <map>
#include "particle.h"// particle class for set class
#include <iostream>
#include <set>
//#include "force.h"// particle class for set class

struct Force {
	double force[2]{}; //force! [0]: x_component, [1]: y_component / force is always initialized as 0
};

struct GF //gravity force (girl friend)
{
	double gf[2] = {}; //x,y 로 작용하는 각각의 만유인력
};

class Set//make a set of particles
{
private:
	//std::map<int , Particle* > indiv_set_info; //map indiv_set_info saves information of type Particle (class)
//	std::map<int, std::map<int, Force *>> force_info;//map force_info saves information of type Force (struct)
	std::map<int, int> fs_relation; //map saves force_set information for convenient
	std::map<int, int> ps_relation; //this map saves relation between particle and set
	Force* temp = new Force; //temporary variable to make a force

public:
	std::map<int, std::map<int, std::map<int, Particle_s>::iterator>> all_set_info; //map all_set_info saves information of type map of Particle(already map)/////////////////////////////////수정
	std::map<int, std::map<int, Force *>> force_info;//map force_info saves information of type Force (struct): first int is force number, second int is set number//////////////////////수정

	Set();
	Set(int num);//constructor

	void Set::indiv_set_make(int set_num, int part_num, Particle* particle_all_, Set* set_all_);//////////////////////////////////수정
	/** this function help us to save particle into set
	/* int part_num : this int variable notice which particle to be added into set
	/* int set_num : this int variable notice which set to have new particle
	/* std::map<int,Particle_s> * particle_add : this variable points to map of particle->makes set
	/* std::map<int, std::map<int, Particle_s>> set_info : this variable is a big map which takes set->makes map of map
	*/
	void Set::big_set_make(const int set_num, Set* set_all_);////////////////////////////////////////////////////수정
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

	void Set::print_force(int num);/////////////////////////////////////////////////////////수정
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

	bool Set::checkbelong(int part_num);
	/** this function check if specific part already belong to set
	/* part_num : name of particle
	/* bool: particle already belong to-> true, else->false
	*/



	//이거 내가 추가한거 일단 알아보기 쉽게 한글로 주석달게 나중에 영어로 바꾸든가 하자


	void Set::gravity();//만유 인력을 추가시켜주는 함수

	std::map<int, GF> gf_info;//하나의 물체가 다른 물체들로 부터 생기는 모든 만유인력을 나타내는 map


};
