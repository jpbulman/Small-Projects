/*
 * CustomerEvent.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#ifndef CUSTOMEREVENT_H_
#define CUSTOMEREVENT_H_

#include "Customer.h"
#include "Event.h"

class CustomerEvent: public Event {
public:
	//Constructor that takes in a customer and a time stamp
	CustomerEvent(Customer c,float timeStamp);
	//Destructor
	virtual ~CustomerEvent();
	//Overrides the parent class to get the time
	virtual float getTime();
	//Overrides the parent class and does the action
	virtual void doAction();
	//Overrides the parent class and gets a customer
	virtual Customer getCust();

private:
	//The customer for the event
	Customer eventCustomer;
	//The time the event occurs
};

#endif /* CUSTOMEREVENT_H_ */
