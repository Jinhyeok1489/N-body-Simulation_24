#include "Particle.h"
#include <memory>

using namespace std;

/*
Particle::Particle(int num, double mass_, double x_position, double y_position, double x_velocity, double y_velocity)//////////////////////////////////////////////////////////////////수정
{
	unique_ptr<Particle_s> temp{ new Particle_s };//smart pointer //////////////////////////////////////////////////////////////////수정
	
	//Particle_s temp;
	temp->mass = mass_;
	temp->position[0] = x_position;
	temp->position[1] = y_position;
	temp->velocity[0] = x_position;
	temp->velocity[1] = y_velocity;

	part_info.insert(std::make_pair(num, *temp));
}
*/

Particle::Particle() {};
void Particle::print_all()
{
	if (this->part_info.size() == 0)
		std::cout << "No particles\n\n";
	else
	{
		int i = 0;
		std::map<int, Particle_s>::iterator iter = this->part_info.begin();
		for (iter = this->part_info.begin(); iter != this->part_info.end(); ++iter)
			//by using iterator, print out every particles
		{
			std::cout << "Particle: " << iter->first << "\n";
			std::cout << "\tMass: " << iter->second.mass << "\n";
			std::cout << "\tLocation: (" << iter->second.position[0] << "," << iter->second.position[1] << ")\n";
			std::cout << "\tVelocity: (" << iter->second.velocity[0] << "," << iter->second.velocity[1] << ")\n\n";
		}
	}
}
/*
{
	int num = 0;
	Particle_s temp;
	temp.mass = 0;
	temp.position[0] = 0;
	temp.position[1] = 0;
	temp.velocity[0] = 0;
	temp.velocity[1] = 0;

	Particle::part_info.insert(std::make_pair(num, temp));
}
*/
void Particle::var_set(double* list)//////////////////////////////////////////////////////////////////수정
{
	unique_ptr<Particle_s> temp{ new Particle_s };//smart pointer //////////////////////////////////////////////////////////////////수정
	temp->mass = list[1];
	temp->position[0] = list[2];
	temp->position[1] = list[3];
	temp->velocity[0] = list[4];
	temp->velocity[1] = list[5];
	part_info.insert(std::make_pair((int)list[0], *temp));

}


void Particle::print_particle(int num)
//this function prints out information of particle
{
	std::cout << "Particle: " << num << "\n";
	if (this->part_info[num].mass != 0) //suppose that there's no particle if mass is 0
	{
		std::cout << "\tMass: " << part_info[num].mass << "\n";
		std::cout << "\tLocation: (" << part_info[num].position[0] << "," << part_info[num].position[1] << ")\n";
		std::cout << "\tVelocity: (" << part_info[num].velocity[0] << "," << part_info[num].velocity[1] << ")\n\n";
	}
	else
		std::cout << "Particle NOT FOUND!\n";
}

void Particle::delete_particle(int num) //this function deletes particle!
{
	if (this->part_info.find(num) == this->part_info.end())
		// if particle number was not found after serarching the map
		cout << "No particle with that name!\n\n";
	else // if particle was found in the map
	{
		this->part_info.erase(num);
		std::cout << "Particle " << num << " deleted \n\n";
	}
}

