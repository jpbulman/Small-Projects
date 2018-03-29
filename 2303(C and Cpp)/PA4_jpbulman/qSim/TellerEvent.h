/*
 * TellerEvent.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#ifndef TELLEREVENT_H_
#define TELLEREVENT_H_

#include "Teller.h"
#include "Event.h"

//Makes TellerEvent a subclass of Event
class TellerEvent: public Event {
public:
	//Constructor for TellerEvent
	TellerEvent(const Teller t,float timeStamp);
	//Overrides the parent class and returns the time
	virtual float getTime();
	//Destructor
	virtual ~TellerEvent();
	//Overrides the parent class and does the event action
	virtual void doAction();

private:
	//The teller for the event
	Teller eventTeller;

};

#endif /* TELLEREVENT_H_ */
