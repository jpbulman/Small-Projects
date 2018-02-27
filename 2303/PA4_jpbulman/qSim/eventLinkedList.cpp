/*
 * eventLinkedList.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: jpbulman
 */

#include "eventLinkedList.h"

#include "Event.h"
#include <cstddef>
#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * Constructor for the queue
 * @return Does not return anything
 */
eventLinkedList::eventLinkedList() {
	//Makes an empty list item
	listItem* nothing = new listItem();
	//Makes a null/dummy event
	Event e(0);
	//Sets the values of the list item to 0
	nothing->next = 0;
	nothing->prev = 0;
	nothing->event = e;
	//Sets the current event and the head to the dummy values
	currItem = nothing;
	head = nothing;
}

/**
 * Adds an event to the queue
 * @return void Does not return anything
 */
void eventLinkedList::addToList(Event e) {

	//Sets the temporary/current item to what the head of the queue is
	currItem = head;

	//Generates a list item for the event e that will be later added into the list
	listItem* addTo = new listItem();
	//Sets the event of the list item to the passed in event
	addTo->event = e;

	//If the head is null
	if (head->event.getTime() == 0) {
		addTo->next = 0;
		addTo->prev = 0;
		head = addTo;
	}
	//If the head value is greater than the pass in the event
	else if (head->event.getTime() > e.getTime()) {
		//Sorting the list by smallest time at the front, so if head is greater, the
		//new event is the head
		//The new list items next item will be null (since its the front of the list)
		addTo->next = 0;
		//The new list items previous item is now the head
		addTo->prev = head;
		//Now the heads next item is the new item
		head->next = addTo;
		//Fix the head to the new list item
		head = addTo;
	}
	//If the head value is equal to the value of the passed in event
	else if (head->event.getTime() == e.getTime()) {
		//Puts the new item behind the head since the head was already in the list
		//Sets the new list item's next item to be the head
		addTo->next = head;
		//Sets the new list item's previous item to what the heads previous item was
		addTo->prev = head->prev;
		//The previous item's next item of the head is the new item
		head->prev->next = addTo;
		//The item behind head is now the new value
		head->prev = addTo;
	}
	//If the head is less than the passed data
	else if (head->event.getTime() < e.getTime()) {

		//If the head is the only element
		if (head->prev == 0) {
			addTo->prev = 0;
			addTo->next = head;
			head->prev = addTo;
		}
		else {

			//Iterates through the list until it finds what two items the list item will go inbetween
			//Loop Invariant: Advances down the list until the current item being looked at is the first of the two inbetweeens,
			//or when the last element is reached
			while (currItem->prev->event.getTime() <= e.getTime()) {
				currItem = currItem->prev;

				if (currItem->prev == 0) {
					break;
				}

			}

			//Now inserts it between the current and current prev items
			//Set the next item of the new item to be the current item
			addTo->next = currItem;
			addTo->prev = currItem->prev;
			//If we are at the last element
			if (currItem->prev != 0) {
				currItem->prev->next = addTo;
			}
			currItem->prev = addTo;

		}

	}

	//Reset the current item to the top of the list
	currItem = head;

}

/**
 * Removes the head from the list
 * @return Does not return anything
 */
void eventLinkedList::removeHeadFromList() {

	//If the head exists
	if(head){
		//If the previous item exists, then make its next 0
		if(head->prev){head->prev->next = 0;}
		//Do the action
		head->event.doAction();
		//Make the new head
		head = head->prev;
		//Reset current item
		currItem = head;
	}

}

/**
 * Gets the value of the first item in the queue
 * @return Does not return anything
 */
float eventLinkedList::getFirstTime() {
	if(currItem){return currItem->event.getTime();}
	else{return 0;}
}

/**
 * Prints the queue
 * @return Does nor return anything
 */
void eventLinkedList::printList() {

	//Loop Invariant: While an item exists, print it out and move on to the next one
	while (currItem) {
		std::cout << currItem->event.getTime() << std::endl;
		currItem = currItem->prev;
	}

}

/**
 * Gets the event on the head
 * @return Returns the event on the head of the queue
 */
Event eventLinkedList::headEvent(){
	return head->event;
}

/**
 * Returns the time of the head
 * @return Returns head value
 */
float eventLinkedList::getHeadVal() {
	return head->event.getTime();
}

/**
 * Destructor
 * @return Does not return anything
 */
eventLinkedList::~eventLinkedList() {
	// TODO Auto-generated destructor stub
}

