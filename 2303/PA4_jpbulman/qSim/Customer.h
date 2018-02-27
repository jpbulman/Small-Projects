/*
 * Customer.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
public:
	//Prototypes for functions
	Customer();
	Customer(float simulTime);
	float getTime();
	virtual ~Customer();

private:
	//The customers arrival time
	float arrivalTime;

};

#endif /* CUSTOMER_H_ */
