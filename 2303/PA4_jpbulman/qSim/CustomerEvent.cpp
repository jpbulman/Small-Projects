/*
 * CustomerEvent.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "CustomerEvent.h"
#include "Customer.h"

/**
 * Returns the customer in the event
 * @return Returns the customer within the event
 */
Customer CustomerEvent::getCust(){
	return eventCustomer;
}

/**
 * A constructor that takes in a customer and the timestamp of the event
 * @param c The customer for the event
 * @param timeStamp The time the event occurred
 * @return Does not return anything
 */
CustomerEvent::CustomerEvent(Customer c,float timeStamp):Event(timeStamp) {
	// TODO Auto-generated constructor stub
	eventCustomer=c;
}

/**
 * Gives the arrival time of the customer in the event
 * @return Returns the arrival of the customer in the form of a float
 */
float CustomerEvent::getTime(){

	return eventCustomer.getTime();
}

/**
 * The CustomerEvent destructor
 * @return Does not return anything
 */
CustomerEvent::~CustomerEvent() {
	// TODO Auto-generated destructor stub
	//delete &eventCustomer;
	//delete &time;
}

/**
 * Instantiates the customer action
 * @return void Does not return anything
 */
void CustomerEvent::doAction(){

}

