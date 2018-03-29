/*
 * TellerQueue.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: jpbulman
 */

#include "TellerQueue.h"

#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Default constructor for a line
 * @return Does not return anything
 */
TellerQueue::TellerQueue() {
	//Makes a dummy person to initialize the line
	personInLine* nothing = new personInLine();
	//All fields for the dummy value are set to 0
	Customer cust(0);
	nothing->ahead=0;
	nothing->prev=0;
	nothing->c=cust;
	head=nothing;
	currPerson=nothing;
	shortestLine=0;
}

/**
 * Returns the number representing which line is the shortest
 * @return Returns the number for the shortest line
 */
int TellerQueue::shortestLineNum(){
	return shortestLine;
}

/**
 * Gets the length of a line
 * @return Returns the number of people in the line
 */
int TellerQueue::getLength(){

	//Intializes starting length to 0
	int currLength = 0;

	//Loop Invariant: While there is a person in the line, count them and then move to the next person in line
	while(currPerson){
		currLength++;
		currPerson=currPerson->prev;
	}

	return currLength;
}

/**
 * Update the statues to what line is the shortest
 * @param i The number representing the line that is now the shortest
 * @return void Does not return anything since it is updating information
 */
void TellerQueue::updateShortestLine(int i){
	shortestLine=i;
}

/**
 * Adds a customer to the line
 * @param c The customer to put in line
 * @return void Does not return anything
 */
void TellerQueue::addToLine(Customer c){

	//Loop Invariant: Goes through the line until the current person is the last one in line
	while(currPerson->prev!=0){
		currPerson=currPerson->prev;
	}

	//Makes a new person in line
	personInLine* addTo = new personInLine();
	//Assigns the customer
	addTo->c=c;

	//Since its at the end, no on is behind them
	addTo->prev=0;
	//Ahead of them is the last person
	addTo->ahead=currPerson;

	currPerson->prev=addTo;

}
/**
 * Gets the frontmost customer
 * @return Returns the customer at the front of the line
 */
Customer TellerQueue::getFrontCust(){
	return head->c;
}

/**
 * Destructor
 * @return Does not return anything
 */
TellerQueue::~TellerQueue() {
	// TODO Auto-generated destructor stub
}

