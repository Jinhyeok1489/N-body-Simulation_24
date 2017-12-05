#include "Set.h"
#include <map>


Set::Set(int num)
{
	std::cout << "Set " << num << " added";
}

Set::Set() {};

void Set::indiv_set_make(int set_num, int part_num, Particle** particle_add, Set* set_info)
{
	set_info->all_set_info[set_num].insert(std::make_pair(part_num, (*particle_add)->part_info[part_num]));
	//this function add particle to set!
}

void Set::big_set_make(const int set_num, std::map<int, std::map<int, Particle_s> > set_info)
{
	set_info.insert(std::make_pair(set_num, set_info[set_num]));
}

void Set::print_set(int num)
{
	std::cout << "----------Set " << num << " ----------\n";
	std::map<int, Particle_s>::const_iterator iter;
	for (iter = all_set_info[num].begin(); iter != all_set_info[num].end(); ++iter)
	{
		std::cout << "Particle: " << iter->first << "\n";
		std::cout << "\tMass: " << iter->second.mass << "\n";
		std::cout << "\tLocation: (" << iter->second.position[0] << "," << iter->second.position[1] << ")\n";
		std::cout << "\tVelocity: (" << iter->second.velocity[0] << "," << iter->second.velocity[1] << ")\n\n";
	}
}

void Set::delete_p_to_s(int set_num, int part_num)
{
	all_set_info[set_num].erase(part_num);
}

void Set::impose_force(int force_num, int set_num, double x_comp, double y_comp)
{ 
	temp->force[0] = x_comp;
	temp->force[1] = y_comp;
	//gives force to each componet for the temporary variable
	force_info[force_num].insert(std::make_pair(set_num, temp));
	//align force to set
	fs_relation.insert(std::make_pair(force_num, set_num));
}

void Set::print_force(int force_num)
{
	double force0 = force_info[force_num][fs_relation[force_num]]->force[0];
	double force1 = force_info[force_num][fs_relation[force_num]]->force[1];
	std::cout << "Force " << force_num << " applied to set " << fs_relation[force_num]<< ": (" << force0<<","<<force1<<") \n\n";
}

void Set::delete_force(int force_num)
{
	force_info.erase(force_num);
	delete temp;
}

//void Set::


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
