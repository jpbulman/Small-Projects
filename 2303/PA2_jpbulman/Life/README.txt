JP Bulman
Game of Life

This program is designed to simulate the John Conway's game of life. The user can run throught the terminal by first setting the directory to the folder with the life.c program, and then using the following command

	./life rows columns generations inputFile [print] [pause]\n
	
Where rows is an integer that is the number of rows the user wants to play the game on, columns is an intger that is the number of desired columns for the game board, generations is an integer that is the number of turns/generations of the game the user wants to play, inputFile is the file that contains the initial game state, [print] is an optional argument if the user wants each generation to be printed, and finally, [pause] is if the user wants to pause between each generation.

When the program is launched, the first thing that happens is the arguments from the command line are read and checked. If there is a insufficient number of arguments or if the ones passed are incorrect, then a friendly error message prints and the program exits. If the arguments load correctly, then a board is made with the txt's configuration into an array which is top and left justified. The board is then changed with a center method where the x's in the configuration are centered to play the game. Then, two more arrays are allocated/made in order to keep track of previous generations, and to swap the current state and the next state; it then prints this initial configuration out to the board. Once this is completed, the program jumps into a loop to start printing out the next generations. It firsts checks to see if all the organisms are dead and then calculates the next generation if there are some still alive. Then, the program checks previous generations to see if there are any repeats, if there are, the program tells the user and exits. Next, the program sees if the users wants to pause before moving forward, and then checks if the user wants the grid to be printed. Finally, at the end, the program swaps the grids around so that when the loops goes back to the top, the grids are in the right priority.


LOOP INVARIANTS

translateGrid
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: J is a counter for the x coordinate, the loop checks to see if there i an x, if so, it makes a new x in the translates spot in the new array
	
	
center
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: J is a counter for the x coordinate, when the loop goes through the array, it keeps track of row and column data in order to be used later in the center function.
	
	
readGrid
	While loop: S is the next character that is read until the end of the file, the loop checks what character is read, and then does an action depending on the character is
	
	
isEveryoneDead
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: J is a counter for the x coordinate, the loop checks to see if the current cell being analyzed has a cell or not, if it does, then the method returns false. Otherwise, if it gets through the entire array, it returns true
	

boardsAreEqual
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: J is a counter for the x coordinate, it then checks the x and y of each array and sees if they are equal
	

printGrid
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: The x and y coordinate are given to the array, and then the contents are printed
	
	
nextGenerations
	Outer loop: I is a counter for the y coordinate as the innner loop traverses through the array
	Inner loop: J is a counter for the x coordinate, the x and y are plugged into the array and the contents are checked. If the cell is occupied, then it checks its neighbors and determines if it lives or dies, if unoccupied, it determines if it should be a new organism or not
	

main
	Generations loop: Terminating conditions are checked, if any are met, the program exits, otherwise, printing/pausing is continued

