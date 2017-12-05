#pragma once

#include "Force.h"
#include "Particle.h"
#include "Set.h"
#include "Time.h"

/* This class takes class force, particle, set as its data member*/
class Control
{
private:
	Set memory; //variable 'memory' saves information of set, particle, force
public:
	/*These functions will receive constructors of class force, particle, set*/
	void ap(int particle_num, double mass_, double x_pos, double y_pos, double x_vel = 0, double y_vel = 0); //add a particle
	void Control::ap(int particle_num, double* list); // add a particle overloaded
	void as(double* set); //add a set
	void ae(double* set, double* particle); //add a particle to a set
	void af(double force, double* set, double x_force, double y_force); //add a force to a set


	void pm();
	/**
	* print out memory usage(number of particles,sets, forces
	* @param			nothing(void) because this function belongs to class Control
	* @return			nothing(void)
	*/
	void pa();
	/**
	* print out all information of memory(particles, sets, forces)
	* @param			nothing(void) because this function belongs to class Control
	* @return			nothing(void)
	*/
	void da();
	/**
	* delete all particles, sets and forces (memory)
	* @param			nothing(void) because this function belongs to class Control
	* @return			nothing(void)
	*/
	void ru(double duration);
	/**
	* run the simulation for 'duration' seconds
	* @param			duration
	* @return			nothing(void)/just run the simulation
	*/
	void rv(double duration);
	/**
	* run the simulation for duration seconds and print out information for every ticks
	* @param			duration
	* @return			nothing(void)/just run the simulation and print information
	*/
	void qq();
	/**
	* (1) stop the simulation
	* (2) delete all the particles, sets and forces
	* (3) print memory
	* @param			nothing(void)
	* @return			nothing(void)/just print the information
	*/
};