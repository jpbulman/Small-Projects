/*
 * Event.h
 *
 *  Created on: Feb 9, 2018
 *      Author: jpbulman
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "Customer.h"
#include "TellerQueue.h"

class Event {
public:
	//Default constructor
	Event();
	//Constructor taking in a time
	Event(float timeStamp);
	//Method to get the time of the event
	float getTime();
	//Destructor
	virtual ~Event();
	//Do the event's action
	void doAction();
	//Gets the customer (if teller returns 0)
	Customer getCust();

private:
	//Time of the event
	float time;

};

#endif /* EVENT_H_ */
