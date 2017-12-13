#include "Set.h"
#include <map>
#include <math.h>


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
	std::cout << "Force " << force_num << " applied to set " << fs_relation[force_num] << ": (" << force0 << "," << force1 << ") \n\n";
}

void Set::delete_force(int force_num)
{
	force_info.erase(force_num);
	delete temp;
}



//이거 내가 추가한거 일단 알아보기 쉽게 한글로 주석달게 나중에 영어로 바꾸든가 하자
void Set::gravity()//만유 인력을 추가시켜주는 함수
{
	double g = 9.8; //중력가속도

	double m1; //물체1 과 2의 질량, 위치들
	double m2;//
	double x1;//
	double y1;//
	double x2;//
	double y2;//////////
	
	double gfx;//x 방향의 만유인력
	double gfy;//y 방향의 만유인력
	
	double r2;//두 물체 사이 거리의 제곱
	double r;//두 물체 사이 거리

	int num1;//물체 1의 번호
	int num2;//물체 2의 번호

	std::map<int, std::map<int, Particle_s>>::const_iterator iter2;
	std::map<int, Particle_s>::const_iterator iter;
	std::map<int, GF>::const_iterator iter_g;

	for (iter2 = all_set_info.begin(); iter2 != all_set_info.end(); ++iter2)
	{
		num1 = iter2->first;

		for (iter = all_set_info[num1].begin(); iter != all_set_info[num1].end(); ++iter) //물체 1의 질량, 위치
		{
			m1 = iter->second.mass;

			x1 = iter->second.position[0];
			y1 = iter->second.position[1];
		}


		for (iter2 = all_set_info.begin(); iter2 != all_set_info.end(); ++iter2)
		{
			num2 = iter2->first;

			for (iter = all_set_info[num2].begin(); iter != all_set_info[num2].end(); ++iter)//물체 2의 질량, 위치
			{
				m2 = iter->second.mass;

				x2 = iter->second.position[0];
				y2 = iter->second.position[1];
			}


			r2 = pow(x1 - x2, 2) + pow(y1 - y2, 2);//두 물체 사이 거리를 계산

			gfx = m1*m2*g/r2*fabs(x1 - x2)/sqrt(r2);//x 방향 만유인력
			gfy = m1*m2*g/r2*fabs(y1 - y2)/sqrt(r2);//y 방향 만유인력

			
			temp->gf[0] = gfx;
			temp->gf[1] = gfy;
			gf_info[num2].insert(temp);//gfx, gfy를 임시로 만든 배열에 대입하고 map gf_info에 추가
		
		}

		for (iter_g = gf_info.begin(); iter_g != gf_info.end(); ++iter)
		{
			all_gf_info[num1].insert(std::make_pair(iter_g->first, iter_g->second);//all_gl_info 에 추가
		}
	
	
	}
	
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
