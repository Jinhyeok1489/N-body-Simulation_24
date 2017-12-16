#include "Time.h"
#include <iostream>

using namespace std;

Time::Time() //constructor
{
	//initialization: tick with 1.0sec, cur_t with 0.0sec, vis with false
	tick = 1.0;
	cur_t = 0.0;
	vis = false;
	cg = false;
}

void Time::ct(double tick_) //change timetick(sec)
{
	if (tick_ == 0.0) //error handling: tick is zero
	{
		cout << "Error: The tick(" << tick << "s) is zero.";
		return;
	}
	tick = tick_;
}

void Time::pt() // print current time
{
	cout << "Current Time is " << cur_t << "s" << endl;
}


void Time::ru(double duration, Set* set_all_)
{
	double fir_t = cur_t;
	double ne_t = cur_t; //initiallize next time
	
	while (true)
	{
		ne_t = (cur_t + tick < duration + cur_t ? cur_t + tick : duration + cur_t);	//time tick & checking operation for last time
		map<int, map<int, map<int, Particle_s>::iterator>>::iterator it_all_set;
		for (it_all_set = (set_all_->all_set_info).begin(); it_all_set != (set_all_->all_set_info).end(); it_all_set++)	//scan all set
		{
			int set_num = it_all_set->first;	//set number
			map<int, map<int, Particle_s>::iterator> i_set = it_all_set->second;	//current set

			if (vis)	//rv option for print time and set
			{
				pt();
				set_all_->print_set(set_num);
			}

			//find all the forces and sum
			double force_x = 0.0;
			double force_y = 0.0;
			map<int, map<int, Force *>>::iterator it_force;
			for (it_force = (set_all_->force_info).begin(); it_force != (set_all_->force_info).end(); it_force++)	//scan all force
			{
				map<int, Force *>::iterator it_set_force = (it_force->second).find(set_num);	//find force which imposed to set_num_
				if (it_set_force != (it_force->second).end())
				{
					force_x += it_set_force->second->force[0];
					force_y += it_set_force->second->force[1];
				}
			}

			set_all_->gravity();	//run gravity
			map<int, map<int, Particle_s>::iterator>::iterator it_all_pa;
			for (it_all_pa = i_set.begin(); it_all_pa != i_set.end(); ++it_all_pa)	//scan particle
			{
				int pa_num = it_all_pa->first;	//particle number
				Particle_s cur_pa_struct = it_all_pa->second->second;	//current particle struct
				Particle_s ne_pa_struct;		//next particle struct
				ne_pa_struct.cp = cur_pa_struct.cp;
				
				if (!cur_pa_struct.cp)	//option for cp command: fixation of particle
					continue;

				double grav_x = 0.0;
				double grav_y = 0.0;
				if (cg)	//option for cg command: gravity on
				{
					grav_x = set_all_->gf_info[pa_num].gf[0];	//load gravity
					grav_y = set_all_->gf_info[pa_num].gf[1];
				}


				double cur_v_x = cur_pa_struct.velocity[0];	//current value
				double cur_v_y = cur_pa_struct.velocity[1];
				double cur_p_x = cur_pa_struct.position[0];
				double cur_p_y = cur_pa_struct.position[1];
				double m = cur_pa_struct.mass;
				if (m == 0.0)	//escape for mass is zero
					continue;
				
				double ne_v_x = ((force_x + grav_x) / m)*tick + cur_v_x;	//next value
				double ne_v_y = ((force_y + grav_y) / m)*tick + cur_v_y;
				double ne_p_x = ne_v_x*tick + cur_p_x;
				double ne_p_y = ne_v_y*tick + cur_p_y;

				ne_pa_struct.velocity[0] = ne_v_x;	//assign next struct
				ne_pa_struct.velocity[1] = ne_v_y;
				ne_pa_struct.position[0] = ne_p_x;
				ne_pa_struct.position[1] = ne_p_y;
				ne_pa_struct.mass = m;

				it_all_pa->second->second = ne_pa_struct;	//reassign value
			}

			if (ne_t == duration + fir_t) //rv option for last time
			{
				if (vis)
				{
					cout << "Current Time is " << ne_t << "s" << endl;
					set_all_->print_set(set_num);
				}
			}

		}
		cur_t = ne_t;
		if (cur_t == duration + fir_t)
			break;
	}
}


