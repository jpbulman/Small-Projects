/*
 * Teller.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Teller.h"

/**
 * Returns the idle time
 * @return Gives the idle time of the teller
 */
float Teller::getIdlTime(){
	return idleTime;
}

/**
 * Constructor for a teller
 * @param avgService A float representing the average time it should take a teller to serve a customer
 * @param startTime The time the teller starts
 * @return Does not return anything
 */
Teller::Teller(float avgService,float startTime) {
	//Symbolic constant for upper limit (exclusive)
	const int RND_IDLE_LIMIT = 1601;
	//Generates the random number
	int rnd = rand();
	//Makes the number be [0,1600]
	rnd = (rnd%(RND_IDLE_LIMIT));
	idleTime=rnd;

	//Constant for the rnd number generator
	const int multipleService = 2;

	//Generates a random service time for the teller based on the average
	float servTime = multipleService*avgService*(rand()/float(RAND_MAX));
	//Sets the service time
	serviceTime=servTime;

	//Sets the start time
	strtTime=startTime;
	//Makes teller available to serve
	isAvail=true;

}

/**
 * Method to get the start time of the teller
 * @return strtTime Returns the start time of the teller
 */
float Teller::getStartTime(){
	return strtTime;
}

/**
 * Default constructor
 * @return Does not return anything
 */
Teller::Teller() {
	// TODO Auto-generated constructor stub
	idleTime=0;
	serviceTime=0;
	strtTime=0;
	isAvail=true;
}

void Teller::startServ(){
	isAvail=false;
}

/**
 * Returns if the teller is available to serve a customer or not
 * @return isAvail Returns the boolean indicating the tellers availability
 */
bool Teller::isTellerAvail(){
	return isAvail;
}

/**
 * Returns the service time of the teller
 * @return Returns the teller's service time
 */
float Teller::getServT(){
	return serviceTime;
}

/**
 * Destructor for a Teller
 * @return Does not return anything
 */
Teller::~Teller() {
	// TODO Auto-generated destructor stub
}

