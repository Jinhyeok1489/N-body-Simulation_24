#pragma once

#include "force.h"
#include "particle.h"
#include "set.h"
#include "time.h"

/* This class takes class force, particle, set as its data member*/
class Control
{
private:
	Set memory; //variable 'memory' saves information of set, particle, force
public:
	/*These functions will receive constructors of class force, particle, set*/
	void ap(double mass_, double x_position, double y_position, double x_velocity = 0, double y_velocity = 0);
	//add a particle
	void as(double* set); //add a set
	void ae(double* set, double* particle); //add a particle to a set
	void af(double force, double* set, double x_force, double y_force); //add a force to a set
	//set에 속하지 않은 particle들도 (예를 들어) null 이라는 이름의 set에 다 때려박으면 되겠지 싶다.

	void pm(Set memory);
	/**
	 * print out memory usage(number of particles,sets, forces
	 * @param memory	class array saves information of set, particle, force
	 * @return			nothing(void)
	 */
	void pa(Set memory);
	/**
	* print out all information of memory(particles, sets, forces)
	* @param			memory class arrays saves information of set, particle, force
	* @return			nothing(void)
	*/
	void da(Set memory);
	/**
	* delete all particles, sets and forces (memory)
	* @param			memory
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