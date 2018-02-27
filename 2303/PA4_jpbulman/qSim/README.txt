Assignment 4
JP Bulman

The project

This program is designed to show the difference between a common line and individual lines in a bank style environment. In the project I have built, I have used several different classes to construct this scenario.
	
	Customer-Represents a customer that is to be served in the bank
	CustomerEvent-A subclass of Event that represents when a customer arrives at the bank
	Event-A parent class to represent a generic 'event' happening in the simulation
	eventLinkedList-An event queue (it was supposed to be called that, but Eclipse did not have a good refactoring 
		feature that would allow me to do this)
	Teller-Represents a service teller who attends to customers
	TellerQueue-A line that holds people for tellers

Although my program is not entirely functionaly, it is able to provide the basic outlines of the simulation (and if I had more time I could extend it for full functionality). There are two setups for each different situation: one simulation with multiple line and one with a common line. Each simulation has its own eventQueue, teller array, and either a single or multiple teller queues. The queues work with a linkedlist which use fields such as head and prev that are used to determine where to put items in the list. The queues have methods to add items to the list itself; every item is represented in the class as a struct. The main queues that are used in the project are the teller queues for the lines and then the event queue for the simulation. The event queue take is an Event so that both teller and customer events can be held in the queue. On the other hand, the teller queue represents a line, so it just holds customers.  

Running the project
Eclipse
	To run this project in eclipse, first download the .zip file, and the then go to 'File' and 'Import'. Create a new project with the archive by choosing 'Select archive file'. Browse to the location of the zip and then upload that. Once the project has been created, build it once, and then use the green arrow to run the program as a 'local c/c++ application'. The program should run accordingly, printing out the test cases and function capabilities.
	
Command line
	Extract the zip into a destination and then locate that destination in the terminal. Then, launch the makefile in the folder and make sure that it runs and links/creates the projects files together. Then, run the command 'gcc -Wall qSim.c' to make sure that everything is in order to run. Next, use 'make' to make the program, and the use the given ./qSim... command to run and test the program.
