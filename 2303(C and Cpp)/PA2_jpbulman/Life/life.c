//JP Bulman
/* Game of Life
 */

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

/**
 * Translates the x's in the given grid by a given x and y amount and puts the new board onto
 * the new grid parameter
 * @param rows The number of rows the grids have
 * @param The number of columns the grids have
 * @param xNum The number of x spaces to move the 'x's over
 * @param yNum The number of y spaces to move the 'x's over
 * @param originalGrid The original board that needs translating
 * @param newGrid The new board that will have the translated version of the original board
 * @return void, since the centered board is written onto 'newGrid', nothing is returned
 */
void translateGrid(int rows, int columns,int xNum,int yNum,
		char** originalGrid,char** newGrid){

	//I is a counter for the y coordinate
	//Loop Invariant: Each iteration either moves an x to the needed space, or places a space
	//if the cell is unoccupied
	for(int i=0;i<rows;i++){

		//J is a counter for the x coordinate
		//Loop Invariant: Each iteration reads the original grid and writes to the new one based
		//on what is in the cell
		for(int j=0;j<columns;j++){

			//If the current cell being looked at is an x
			if(originalGrid[i][j]=='x'){
				//Make the new and translated space an 'x'
				newGrid[i+yNum][j+xNum]='x';
			}
			//This fills in the extra spaces and prevents overlap between x's and spaces
			else if(newGrid[i][j]!='x'){newGrid[i][j]=' ';}

		}

	}

}

/**
 * Centers the shape of x's on a board
 * @param rows The number of rows in the grids
 * @param columns The number of columns in the grids
 * @param originalGrid the original not centered board
 * @param newGrid The new board with a centered shape of x's
 * @return void The function returns nothing because it writes the centered board onto newGrid
 */
void center(int rows, int columns,char** originalGrid,char** newGrid){

	//X position as the method traverses through the board
	int currXPos = 0;
	//Y position as the method traverses through the board
	int currYPos = 0;

	//The farthest x point where an x has been found on the board
	int largestXPos=0;
	//The closest x point where an x has been found on the board
	int minXPos=100;
	//The farthest y point where an x has been found on the board
	int largestYPos=0;
	//The closest y point where an x has been found on the board
	int minYPos=100;

	//I is a counter for the y coordinate
	//Loop Invariant: Checks if the newest position is an x and if it is further or closer
	//than the current maxes and mins
	for(int i=0;i<rows;i++){
		//J is a counter for the x coordinate
		//Loop Invariant: Checks if the newest position is an x and if it is further or closer
		//than the current maxs and mins
		for(int j=0;j<columns;j++){

			//If an x is found on the original board
			if(originalGrid[i][j]=='x'){

				//Is the current x position farther out than the current max?
				if(currXPos>largestXPos){
					//Updates the max to the current position
					largestXPos=currXPos;
				}

				//Sees if the x position is closer in than the current min
				if(currXPos<minXPos){
					//Updates the min
					minXPos=currXPos;
				}

				//Checks to see if the current y is greater than the max y
				if(currYPos>largestYPos){
					//If so, it updates the max y to the current y
					largestYPos=currYPos;
				}

				//If the current y is less than the current minimum
				if(currYPos<minYPos){
					//Updates the minimum to the current position
					minYPos=currYPos;
				}

			}

			//Go to the right one space for the next iteration
			currXPos++;
		}
		//Go down one space after reaching the end of a row
		currYPos++;
		//Reset the x position to 0 once the end of the row has been reached
		currXPos=0;
	}

	//Length of the shape of x's is the farthest x point minus the closest x point
	int xLength = largestXPos-minXPos;
	//Height of the shape of x's is the farthest y point minus the closest y point
	int yLength = largestYPos-minYPos;

	//The x distance that the x's need to be translated
	int xToTranslate = 0;
	//If the length of the empty space between the shape and the borders is divisible by 2,
	//then make the translate distance the difference divided by 2
	if((columns-xLength)%2==0){xToTranslate=((columns-xLength)/2);}
	//Same as above, but subtracts one first so that the number is evenly divisible by 2
	else{xToTranslate=(((columns-1)-xLength)/2);}

	//The y distance that the x's need to be translated
	int yToTranslate = 0;
	//If the length of the empty space between the shape and the borders is divisible by 2,
	//then make the translate distance the difference divided by 2
	if((rows-yLength)%2==0){yToTranslate=((rows-yLength)/2);}
	//Same as above, but subtracts one first so that the number is evenly divisible by 2
	else{yToTranslate=(((columns-1)-yLength)/2);}

	//Once the distances have been calculated, then translate the shape onto 'newGrid'
	translateGrid(rows,columns,xToTranslate,yToTranslate,originalGrid,newGrid);

}

/**
 * Reads the grid from the file and initializes the array with the file's board
 * @param input The file that contains the desired game of life to play
 * @param rows The number of rows the game is to be played on
 * @param columns The number of columns game is to be played on
 * @param grid The array that needs to be filled with the game from the .txt
 * @return 0 if the parameters are insufficient and 1 if the function works correctly
 */
int readGrid(FILE *input, int rows, int columns, char** grid) {
	//The current character from the file
	int s;
	//The current number of maximum columns (changes when a row with more characters is found)
	int currentNumberOfColumns = 0;
	//Number of items that have been accounted for in the row
	int currentNumberOfItemsInRow = 0;
	//Total number of rows
	int numberOfRows = 0;

	//Analyzes the next character (as an it) in the file until it reaches the end
	//Loop invariant: S is the next character (as an int) in the file and is checked to see what
	//it is while keeping track of and updating column and row data
	while ((s = fgetc(input)) != EOF) {

		//If the users gives arguments that do not work with the given file
		if (columns < currentNumberOfColumns||(numberOfRows > rows)) {
			printf("Specified # of params is insufficient\n");
			return 0;
		}

		//If the int is 'x' (ASCII #120)
		if (s == 120) {
			grid[numberOfRows][currentNumberOfItemsInRow] = 'x';
		}
		//If the int is 'o' (ASCII #111)
		if (s == 111) {
			grid[numberOfRows][currentNumberOfItemsInRow] = ' ';
		}

		//If the character is at the end of the line (\n is 10)
		if (s == 10) {
			//The end of a line increases the number of rows
			numberOfRows++;

			//If the row size is bigger than the current max row size
			if (currentNumberOfItemsInRow > currentNumberOfColumns) {
				currentNumberOfColumns = currentNumberOfItemsInRow;
			}
			//Resets the number of items in the row, as it is going on to the next row
			currentNumberOfItemsInRow = 0;
		} else {
			//Go to the next char(int) and increase the count by 1
			currentNumberOfItemsInRow++;
		}

	}

	//Returns 1 as 'worked correctly'
	return 1;
}

/**
 * Gets the contents of a cell
 * @param x The x coordinate of the desired cell
 * @param y The y coordinate of the desired cell
 * @param rows Number of rows in entire grid
 * @param columns Number of columns in the entire grid
 * @param grid The board to be analyzed
 * @return Either a blank, if the space is outside the board, or the contents, if it is inside
 */
char getItem(int x, int y, int rows, int columns, char** grid) {
	//If the coordinates are outside the given box then a blank is returned
	//It is assumed that anything outside the board is a blank
	if (x > columns - 1 || y > rows - 1 || y < 0 || x < 0) {
		return ' ';
	} else {
		//The contents if it is inside
		return grid[y][x];
	}
}

/**
 * Determines if all spaces in the grid are unoccupied
 * @param rows The number of rows in the board
 * @param columns The number of columns in the board
 * @param grid The board to be checked
 * @return 1 if none of the spaces are occupied, 0 if any are taken
 */
int isEveryoneDead(int rows, int columns, char** grid) {
	//i is the counter for the y coordinate
	//Loop Invariant: I is used as the y coordinate each time to check for the given char
	for (int i = 0; i < rows; i++) {
		//j is the counter for x
		//Loop Invariant: J is used as the x coordinate each time to check for the given char
		for (int j = 0; j < columns; j++) {

			//Checks to see if the square is occupied
			if (getItem(j, i, rows, columns, grid) == 'x') {
				//If it is occupied, then not everyone is dead, return false
				return 0;
			}

		}
	}

	//If it goes through all parts of the array and finds nothing, return true
	return 1;
}

/**
 * Determines if the two boards are equal in contents
 * @param rows The number of rows in the grids
 * @param columns The number of columns in the grids
 * @param gridA The first board to be compared
 * @param gridB The second board to be compared
 * @return 1 if they are equal and 0 if they are not equal
 */
int boardsAreEqual(int rows, int columns, char** gridA, char** gridB) {

	//I is the y coordinate
	//Loop invariant: i is the y coordinate and the loop compares the contents each time
	for (int i = 0; i < rows; i++) {
		//Loop invariant: j is the x coordinate and the loop compares the contents each time
		for (int j = 0; j < columns; j++) {
			//If there is a mismatch between the items in the boards, then return 0 (false)
			if (gridA[i][j] != gridB[i][j]) {
				return 0;
			}

		}
	}

	//If all positions are gone through and none are mismatched, return 1 (true)
	return 1;

}

/**
 * Returns the number of occupied cells a space has next to it
 * @param x The x coordinate
 * @param y The y coordinate
 * @param rows The number of rows in the board
 * @param columns The number of columns in the board
 * @param grid The board to be analyzed
 */
int getNumberOfAliveNeighbors(int x, int y, int rows, int columns, char** grid) {
	//Starts off with 0 neighbors
	int currNumNeighbors = 0;

	//Because of arrays and the current setup, x+1 will go one right, and vice versa
	//BUT y+1 will go down because the array starts at the top left
	//This checks cells starting from the top left neighbor and goes clockwise until it
	//gets to the position of one before home

	//If the top left is filled, add 1 to the number of neighbors
	if (getItem(x - 1, y - 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Top middle
	if (getItem(x, y - 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Top right
	if (getItem(x + 1, y - 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Right middle
	if (getItem(x + 1, y, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Bottom right
	if (getItem(x + 1, y + 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Bottom middle
	if (getItem(x, y + 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Bottom left
	if (getItem(x - 1, y + 1, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Left middle
	if (getItem(x - 1, y, rows, columns, grid) == 'x') {
		currNumNeighbors += 1;
	}

	//Returns number of adjacent occupied cells
	return currNumNeighbors;
}

/**
 * Prints the passed grid
 * @param grid The grid to be printed
 * @param rows The number of rows it should be printed with
 * @param columns The number of columns it should be printed with
 * @return void, it is a print method, so nothing is returned
 */
void printGrid(char** grid, int rows, int columns) {
	//I is a counter for the y coordinate
	//Loop invariant: I is plugged in as the y and the resulting contents are printed
	//Line breaks occur each time the second loop ends
	for (int i = 0; i < rows; i++) {
		//J is a counter for the x coordinate
		//Loop invariant: J is plugged in as the x and the contents are printed
		for (int j = 0; j < columns; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * Writes the next generation onto a grid
 * @param originalGrid The grid to find the next generation of
 * @param newGrid The board the next generation will be written on
 * @param rows The number of rows the board has
 * @param columns The number of columns the board has
 * @return void, returns nothing since it is modifying variables
 */
void nextGeneration(char** originalGrid, char** newGrid, int rows, int columns) {

	//I is a counter for the y coordinate
	//Loop Invariant: The number of neighbors is checked for each cell to determine if it
	//should live, die, or become an organism
	for (int i = 0; i < rows; i++) {
		//J is a counter for the x coordinate
		//Loop Invariant: The number of neighbors is checked for each cell to determine if it
		//should live, die, or become an organism
		for (int j = 0; j < columns; j++) {

			//If the cell is occupied
			if (getItem(j, i, rows, columns, originalGrid) == 'x') {

				//The number of neighbors is switched
				int switcher = getNumberOfAliveNeighbors(j, i, rows, columns,originalGrid);

				switch (switcher) {

				//If the number of neighbors is 0,1,4,5,6,7,or 8, the cell dies
				case 0:
				case 1:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					//Organism dies and is replaced with a space
					newGrid[i][j] = ' ';
					break;
					//If the organism has 2 or 3 neighbors, it lives
				case 2:
				case 3:
					//Stays alive as an 'x'
					newGrid[i][j] = 'x';
					break;

					//If for some reason there are more than 8 neighbors or less than 0
				default:
					newGrid[i][j] = 'k';
					printf("Something went very, very, wrong");

				}

			}
			//If the cell is unoccupied
			else {

				//Number of neighbors to the empty cell
				int numberOfNs = getNumberOfAliveNeighbors(j, i, rows, columns,
						originalGrid);
				//If the cell has 3 neighbors, it will now become an organism
				if (numberOfNs == 3) {
					newGrid[i][j] = 'x';
				}
				//Otherwise, it stays empty
				else {
					newGrid[i][j] = ' ';
				}

			}

		}
	}

}

/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
 */

int main(int argc, char **argv) {
	printf("Game of Life\n");

	char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int rows; // Number of rows in the grid
	int columns; // Number of columns in the grid
	int gens; // Number of generations to produce
	int doPrint; // 1 if user wants to print each generation, 0 if not
	int doPause; // 1 if user wants to pause after each generation, 0 if not
	char **gridA; // A 2D array to hold the pattern

	// See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}

	/* Save the command-line arguments.
	 Also need to check if print and/or pause arguments were entered,
	 and if so, what they were.
	 A switch statement might be handy here.
	 */
	rows = atoi(argv[1]); // Convert from character string to integer.
	columns = atoi(argv[2]);
	gens = atoi(argv[3]);
	inputFileName = argv[4];

	//If at least one optional argument is presented
	if (argc > 5) {
		switch (*argv[5]) {
		//If it is 'n' (ASCII # 110)
		case 110:
			//Set doPrint to 0 (false)
			doPrint = 0;
			break;
		//If it is 'y' (ASCII # 121)
		case 121:
			//Set doPrint to 1 (true)
			doPrint = 1;
			break;
		//If the user enters an arg besides 'y' or 'n'
		default:
			printf("Error, wrong args\n");
			return 0;
		}

		//If both arguments are entered
		if (argc > 6) {
			switch (*argv[6]) {
			//If it is 'n' (ASCII # 110)
			case 110:
				doPause = 0;
				break;
			//If it is 'y' (ASCII # 121)
			case 121:
				doPause = 1;
				break;
			//If the user enters arguments besides 'y' or 'n'
			default:
				printf("Error, wrong args\n");
				return 0;
			}
		}

	}

	/* Here is how you would allocate an array to hold the grid.
	 */
	gridA = make2Dchar(rows, columns);
	// You should check that it succeeded.

	/* Eventually, need to try to open the input file.
	 */
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	//If the readGrid is unsuccessful, then exit
	if (readGrid(input, rows, columns, gridA) == 0) {
		return EXIT_FAILURE;
	}

	//Grid X is the board for the centered gridA to be written on
	char** gridX;
	gridX = make2Dchar(rows, columns);

	//Writes a centered version of A onto X
	center(rows,columns,gridA,gridX);

	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	 */

	//Since the function uses gridA, gridA needs to be centered
	gridA=gridX;

	//Print out the initial state
	printGrid(gridA, rows, columns);

	//Make a second array for swapping to the next generation
	char **gridB;
	gridB = make2Dchar(rows, columns);

	//Make a third array to keep track of previous generation for patterns
	char **gridC;
	gridC = make2Dchar(rows, columns);

	//I is a counter for each generation of the game
	//Loop Invariant: A new generation is made each time based on previous generation data.
	//The loop checks for certain terminating conditions as it goes on (death, patterns, etc),
    //and otherwise continues with the printing/pausing
	for (int i = 0; i < gens; i++) {

		//If all the spaces are empty, return and exit
        if(isEveryoneDead(rows,columns,gridA)!=0){
        	printf("Everyone has died :( \n");return 0;
        }

        //Writes over gridB with the newest generation
        nextGeneration(gridA, gridB, rows, columns);

        //Checks for patterns in the previous generations, if one is found, then the program
        //exits
        if(boardsAreEqual(rows,columns,gridB,gridA)!=0||
        	boardsAreEqual(rows,columns,gridB,gridC)){
        	printf("Repeated Pattern Reached\n");
        	printGrid(gridB,rows,columns);
        	return 0;
        }

        //If the user wanted to pause between generations
		if (doPause != 0) {
			//For the next character
			char enter;
			printf("Please hit enter:");
			//Gets the next character
			scanf("%c", &enter);
		}

		//If the user wants the generations printed
		if (doPrint != 0) {
			printGrid(gridB, rows, columns);
		}
		//Even if the parameters are no, the final state should be printed
		if(doPrint==0&&(i+1==gens)){printGrid(gridB,rows,columns);}

		//Grid C moves back a generation
		gridC=gridA;
		//A gets promoted to what is the current generation
		gridA=gridB;
		//Grid B is reset for the next iteration
		gridB = make2Dchar(rows,columns);

	}

	return EXIT_SUCCESS;
}
