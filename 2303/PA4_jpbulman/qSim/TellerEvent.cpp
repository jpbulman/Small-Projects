/*
 * TellerEvent.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#include "Teller.h"
#include "TellerEvent.h"

/**
 * Constructor for a TellerEvent that takes in a teller, and the time it happened
 * @param t The teller for the event
 * @param timeStamp The time the transaction ended
 * @return Does not return anything
 */
TellerEvent::TellerEvent(Teller t,float timeStamp):Event(timeStamp) {
	// TODO Auto-generated constructor stub
	eventTeller=t;
}

/**
 * Gets the end time of the teller event
 * @return Returns the end time of the event
 */
float TellerEvent::getTime(){
	return eventTeller.getStartTime();
}

/**
 * Does the action for the teller event
 * @return void Does not return anything
 */
void TellerEvent::doAction(){

}

/**
 * Destructor for the teller event
 * @return Does not return anything
 */
TellerEvent::~TellerEvent() {
	// TODO Auto-generated destructor stub
}

