
I designed this program using basic ideas from class inheritance and polymorphism. The Doodlebugs and Ants are both represented with their own class, but also with a super class called Organism. This allows them to both have shared field names and methods and makes it easier to operate on them while they are in a board. The board itself is represented by a class that has a private field which is a two-d array of pointers to Organisms. The board class has most of the primary methods such as printBoar and moveChars, and holds most of the data for the statistics. Essentially, the program starts (in PA5.cpp) by making a board with the proper parameters given in by the user (or default ones if necassary). The board constructor will generate a random board with the specified number of Doodlbugs and Ants in it; before moving the board, the program checks for pausing and then adjusts accordingly. Next, the program moves the characters (Organisms) on the board, and then prints out the result. It does this until the total number of given (or default) number of time steps have been reached. 

Important functions
	move-Returns an int representing where to go 0-stay 1-up 2-right 3-down 4-left
	breed-Retursn an int representing where the org should breed (same directions as above)
	
Classes
	PA5-The main class
	Board-Represents a playble board
	Organism-Super/parent class for Doodlebug and Ant
	Ant- An Ant
	Doodlebug-A Doodlebug


Running the project
Eclipse
	To run this project in eclipse, first download the .zip file, and the then go to 'File' and 'Import'. Create a new project with the archive by choosing 'Select archive file'. Browse to the location of the zip and then upload that. Once the project has been created, build it once, and then use the green arrow to run the program as a 'local c/c++ application'. The program should run accordingly, printing out the test cases and function capabilities.
	
Command line
	Extract the zip into a destination and then locate that destination in the terminal. Then, launch the makefile in the folder and make sure that it runs and links/creates the projects files together. Then, run the command 'gcc -Wall PA5.cpp' to make sure that everything is in order to run. Next, use 'make' to make the program, and the use the given ./PA5... command to run and test the program.


TEST CASES:

./PA5 10 5 5 11 12 0

Results in:

-oo--ooo--
-o----o---
--oo--ooo-
o--o-o----
-o---o----
-o-oo-oo-o
---ooooo--
---ooo--o-
----oo-oo-
----o-oo-o

Gridsize: 10 Number of Doodlebugs: 5 Number of ants: 5 Time steps: 11 Seed: 12 Pause: 0
The number of steps taken was: 11
The total number of Ants was: 40
The total number of remaining Ants was: 40
The total number of Doodlebugs was: 5
The total number of remaining Doodlebugs was: 0


./PA5 12 3 3 11 0 0

Results in:

------------
------------
------------
-------o----
------------
------o-o---
---------o--
-----o-o----
-----o--o---
---------oo-
------------
-------o--o-

Gridsize: 12 Number of Doodlebugs: 3 Number of ants: 3 Time steps: 11 Seed: 0 Pause: 0
The number of steps taken was: 11
The total number of Ants was: 14
The total number of remaining Ants was: 12
The total number of Doodlebugs was: 3
The total number of remaining Doodlebugs was: 0

