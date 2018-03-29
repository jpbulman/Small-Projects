/*
 * Customer.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Customer.h"

/**
 * The default constructor for customer
 * @return Returns nothing
 */
Customer::Customer(){
	arrivalTime=0;
}

/**
 * A constructor for a customer taking in a float that is the simulation time
 * @param simulTime The simulation time given in the main function
 * @return Constructor does not return anything
 */
Customer::Customer(float simulTime) {
	//Generates a random arrival time for the customer to show up
	float arrTime = (simulTime * (rand()/float (RAND_MAX)));
	//Sets the arrivalTime field to the random variable
	arrivalTime=arrTime;
}

/**
 * Gives the customers arrival time
 * @return Gives back a float representing the time the customer arrives
 */
float Customer::getTime(){
	return arrivalTime;
}

/**
 * The destructor for customer
 * @return Does not return anything
 */
Customer::~Customer() {
	// TODO Auto-generated destructor stub
	//delete &arrivalTime;
}

