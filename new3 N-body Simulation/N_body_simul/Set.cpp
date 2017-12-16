#include "Set.h"
#include <map>

Set::Set(int num)
{
	std::cout << "Set " << num << " added";
}

Set::Set() {};

void Set::indiv_set_make(int set_num, int part_num, Particle* particle_all_, Set* set_all_)//////////////////////////////////수정
{
	set_all_->all_set_info[set_num].insert(std::make_pair(part_num ,particle_all_->part_info.find(part_num)));
	//this function add particle to set!
	if (set_all_->ps_relation.find(part_num) == set_all_->ps_relation.end()) //if part_num was not found in set_all
		set_all_->ps_relation.insert(std::make_pair(part_num, set_num)); //add their relation
	else // else(if it already exist)
		set_all_->ps_relation[part_num] = set_num;
}

void Set::big_set_make(const int set_num, Set* set_all_)////////////////////////////////////////////////////수정
{
	set_all_->all_set_info.insert(std::make_pair(set_num, set_all_->all_set_info[set_num]));
}

void Set::print_set(int num)////////////////////////////////////////////////////////////////////////수정
{
	std::cout << "----------Set " << num << " ----------\n";
	std::map<int, std::map<int, Particle_s>::iterator>::iterator iter;
	for (iter = all_set_info[num].begin(); iter != all_set_info[num].end(); ++iter)
	{
		std::cout << "Particle: " << iter->first << "\n";
		std::cout << "\tMass: " << iter->second->second.mass << "\n";
		std::cout << "\tLocation: (" << iter->second->second.position[0] << "," << iter->second->second.position[1] << ")\n";
		std::cout << "\tVelocity: (" << iter->second->second.velocity[0] << "," << iter->second->second.velocity[1] << ")\n\n";
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

void Set::print_force(int force_num)///////////////////////////////////////////////////////////////////////수정
{
	double force0 = force_info[force_num][fs_relation[force_num]]->force[0];
	double force1 = force_info[force_num][fs_relation[force_num]]->force[1];
	std::cout << "Force " << force_num << " applied to set " << fs_relation[force_num] << ": (" << force0 << "," << force1 << ") \n\n";
	/*
	std::cout << "----------Force----------\n";

	std::map<int, std::map<int, Force *>>::iterator it_force;
	for (it_force = force_info.begin(); it_force != force_info.end(); ++it_force)
	{
		int force_num = it_force->first;
		double force0 = force_info[force_num][fs_relation[force_num]]->force[0];
		double force1 = force_info[force_num][fs_relation[force_num]]->force[1];
		std::cout << "Force " << force_num << " applied to set " << fs_relation[force_num] << ": (" << force0 << "," << force1 << ") \n";
	}
	std::cout << std::endl;
	*/
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

bool Set::checkbelong(int part_num)
{
	if (this->ps_relation[part_num] == 0)
		return false;
	else
		return true;
}

void Set::gravity()//만유 인력을 추가시켜주는 함수
{
	double G = 6.6738e-11; //gravitational constant[N*m^2*kg^-2] from Wikipedia/////////////////////////////////////////////////////////수정

	///////////////////////////////////////////////////////////////////////////////////////수정

	std::map<int, GF>::const_iterator iter_g;

	std::map<int, std::map<int, std::map<int, Particle_s>::iterator>>::iterator it_all_set;/////////////////////////////수정
	for (it_all_set = all_set_info.begin(); it_all_set != all_set_info.end(); ++it_all_set)	//scan all set
	{
		int cur_set_num = it_all_set->first;
		std::map<int, std::map<int, Particle_s>::iterator>::iterator it_cur_set_all_pa;
		for (it_cur_set_all_pa = all_set_info[cur_set_num].begin(); it_cur_set_all_pa != all_set_info[cur_set_num].end(); ++it_cur_set_all_pa)	//scan all particle in current set
		{
			int cur_pa_num = it_cur_set_all_pa->first;
			Particle_s cur_pa = it_cur_set_all_pa->second->second;	//current particle
			double cur_p_x = cur_pa.position[0];	//current position, mass
			double cur_p_y = cur_pa.position[1];
			double cur_m = cur_pa.mass;

			GF cur_pa_grav;
			cur_pa_grav.gf[0] = 0.0;
			cur_pa_grav.gf[1] = 0.0;
			std::map<int, std::map<int, std::map<int, Particle_s>::iterator>>::iterator it_all_set2;
			for (it_all_set2 = all_set_info.begin(); it_all_set2 != all_set_info.end(); ++it_all_set2)	//scan all set again
			{
				int cur_set_num2 = it_all_set2->first;
				std::map<int, std::map<int, Particle_s>::iterator>::iterator it_cur_set_all_pa2;
				for (it_cur_set_all_pa2 = all_set_info[cur_set_num2].begin(); it_cur_set_all_pa2 != all_set_info[cur_set_num2].end(); ++it_cur_set_all_pa2)	//scan all particle in current set2
				{
					int cur_pa_num2 = it_cur_set_all_pa2->first;
					Particle_s cur_pa2 = it_cur_set_all_pa2->second->second;	//current particle 2

					if (cur_pa_num == cur_pa_num2)	//escape for same particle
						continue;

					double cur_p_x2 = cur_pa2.position[0];	//current position, mass 2
					double cur_p_y2 = cur_pa2.position[1];
					double cur_m2 = cur_pa2.mass;

					double r_sq = pow(cur_p_x - cur_p_x2, 2) + pow(cur_p_y - cur_p_y2, 2);	//distance between two particle
					if (r_sq == 0.0)	//escape for same location
						continue;
					double grav = G*cur_m*cur_m2 / r_sq;
					double r_x = (cur_p_x2 - cur_p_x) / sqrt(r_sq);	//x of unit vector of r
					double r_y = (cur_p_y2 - cur_p_y) / sqrt(r_sq);	//y of unit vector of r
					double gfx = grav * r_x;//x 방향 만유인력
					double gfy = grav * r_y;//y 방향 만유인력

					cur_pa_grav.gf[0] += gfx;
					cur_pa_grav.gf[1] += gfy;

				}
			}
			gf_info.insert(std::make_pair(cur_pa_num, cur_pa_grav));

		}
	}
}
