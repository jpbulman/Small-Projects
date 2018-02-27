/*
 * Event.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: jpbulman
 */

//#include <iostream>
//#include <cstdlib>
//using namespace std;

#include "Event.h"
#include "Customer.h"

/**
 * Returns the customer for the event, but since its the super class, returns null
 * @return Returns a null customer
 */
Customer Event::getCust(){
	return 0;
}

/**
 * Default constructor for an Event
 * @return void Does not return anything
 */
Event::Event(){
	time=0;
}

/**
 * Constructor that takes in a time
 * @param timeStamp the time the event starts
 * @return Does not return anything
 */
Event::Event(float timeStamp) {
	time=timeStamp;
}

/**
 * Gets the time of the event
 * @return time Returns the float representing the event's time
 */
float Event::getTime(){
	return time;
}

/**
 * Does the event's action
 * @return void Does not return anything
 */
void Event::doAction(){

}

/**
 * The destructor for an event
 * @return Does not return anything
 */
Event::~Event() {
	// TODO Auto-generated destructor stub
}

