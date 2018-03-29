/*
 * eventLinkedList.h
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#ifndef EVENTLINKEDLIST_H_
#define EVENTLINKEDLIST_H_

#include "Event.h"
#include "CustomerEvent.h"

class eventLinkedList {

	struct listItem{
		//The current event the list item is holding
		Event event;
		//The next item in the list
		listItem *next;
		//The
		listItem *prev;
	};

public:
	//Default constructor
	eventLinkedList();
	//Destructor
	virtual ~eventLinkedList();
	//Adds an event to the list
	void addToList(Event e);
	//Removes the head of the list
	void removeHeadFromList();
	//Prints the list
	void printList();
	//Gets the time value of the first event
	float getFirstTime();
	//Gets the time value of the head
	float getHeadVal();
	//Returns the event on the head
	Event headEvent();

private:
	//The head of the list
	listItem* head;
	//The current item being looked at in the list
	listItem* currItem;

};

#endif /* EVENTLINKEDLIST_H_ */
