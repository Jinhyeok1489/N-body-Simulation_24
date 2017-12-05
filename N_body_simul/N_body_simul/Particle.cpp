#include "Particle.h"

Particle::Particle(int num, double mass_, double x_position, double y_position, double x_velocity, double y_velocity)
{
	Particle_s temp;
	temp.mass = mass_;
	temp.position[0] = x_position;
	temp.position[1] = y_position;
	temp.velocity[0] = x_position;
	temp.velocity[1] = y_velocity;

	Particle::part_info.insert(std::make_pair(num, temp));
}
Particle::Particle() {};
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
void Particle::var_set(double* list)
{
	Particle_s temp;
	temp.mass = list[1];
	temp.position[0] = list[2];
	temp.position[1] = list[3];
	temp.velocity[0] = list[4];
	temp.velocity[1] = list[5];
	Particle::part_info.insert(std::make_pair(list[0], temp));
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
	if (this->part_info[num].mass != 0) //suppose that there's no particle if mass is 0
	{
		this->part_info.erase(num);
		std::cout << "Particle " << num << " deleted \n\n";
	}
	else
		std::cout << "Particle NOT FOUND!\n\n";
}

