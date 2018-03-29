/*
 * Teller.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#ifndef TELLER_H_
#define TELLER_H_

class Teller {
public:
	//Default constructor
	Teller();
	//Constructor taking in the idle time and a start time
	Teller(float iTime,float startTime);
	//Gets the tellers start time
	float getStartTime();
	//Destructor
	virtual ~Teller();
	//Determines the teller's availability to serve a customer
	bool isTellerAvail();
	//Gets the teller's service time
	float getServT();
	//Serves a customer
	void startServ();
	//Gets the idle time
	float getIdlTime();

private:
	//A float to represent the start of a transaction
	float strtTime;
	//How much time the teller will spend doing other tasks when there are no customers
	float idleTime;
	//How long it will take this teller to serve a customer
	float serviceTime;
	//Is the teller available to serve a customer?
	bool isAvail;

};

#endif /* TELLER_H_ */
