#include "Set.h"
#include <map>


Set::Set(int num)
{
	std::cout << "Set " << num << " added";
}

Set::Set() {};

void Set::indiv_set_make(int part_num, int set_num, std::map<int, Particle_s>* particle_add, std::map<int, std::map<int, Particle_s>> set_info)
{
	set_info[set_num].insert(std::make_pair(part_num, (*particle_add)[part_num]));
	//this function add particle to set!
}

void Set::big_set_make(int set_num, std::map<int, std::map<int, Particle_s>> set_info)
{
	std::map<int, Particle_s> temp;

	set_info.insert(std::make_pair(set_num, set_info[set_num]));
}



/*
void Set::to_set(int num)
{
	all[num];
}

void Set::set_make(int num, std::map<int, Particle_s> particle_info)
{
	
	Set::set_info.insert(std::make_pair(num, particle_info[num]));
}
*/
