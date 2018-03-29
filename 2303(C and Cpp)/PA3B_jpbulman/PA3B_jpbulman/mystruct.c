/** mystruct.c
 * @author Mike Ciaraldi
*/

//JP Bulman

//Used for printing
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {

	//Creates a pointer to an employee
	struct Employee* JoeSchmoe;
	//Allocates memory for the struct
	JoeSchmoe = (struct Employee*)malloc(sizeof(struct Employee));
	//Assigns the birth year
	JoeSchmoe->birth_year=birth;
	//Assigns the start year
	JoeSchmoe->start_year=start;

	//Copies the name parameter into the name field with 99 bytes (leave one for terminator)
	strncpy(JoeSchmoe->name,name,99);
	//Add terminator at the end (99 is the end in zero-based indexing)
	JoeSchmoe->name[99]='\0';

	return JoeSchmoe;
}

/**
 * Gets a random integer from 0 to a max (inclusive)
 * @param max The maximum random number desired
 * @return Returns the random integer
 */
int getRandInt(int max){
	//Generates the random number
	int rnd = rand();
	//Makes the number be [0,max]
	rnd = (rnd%(max+1));
	return rnd;
}

/**
 * Gets a random capital alphabetical character using ASCII
 * @param void Function does not need anything passed in
 * @return randChar Returns a random capital alphabetical character (A-Z)
 */
char getRandChar(void){
	//Generates a random char [65,90]
	char randChar = getRandInt(25)+65;

	return randChar;
}

/**
 * Gets a random string of capital alphabetical characters
 * @param length The length of the desired string
 * @return Returns the random string
 */
char* getRandString(int length){

	//Creates a pointer to a char to hold the string
	char* theString;
	//Allocates memory according to the length (+1 to account for null terminator)
	theString = (char*)malloc(length+1);
	//Placeholder for the string while it is being operated on
	char* wop = theString;

	//i is an integer counter that is used to access pieces of 'theString'
	//Loop Invariant: A random character is generated each time and put into the according part
	//of the array
	for(int i=0;i<=length;i++){
		//Gets a random character
		char c = getRandChar();
		//Puts it into the string
		theString[i]=c;
	}

	//Adds a null terminator
	theString[length]='\0';

	//Returns a pointer to the new random string
	return wop;
}

/**
 * Makes an employee with random fields
 * @param void Function does not need anything passed in
 * @return Returns a pointer to a random employee
 */
struct Employee* makeRndEmployee(void){

	//Gets a random birth year [0,2017]
	int rndBirth = getRandInt(2017);
	//Gets a random start year [0,2017]
	int rndStrt = getRandInt(2017);
	//Gets a name made of 10 random characters
	char* rndName = getRandString(10);

	//Builds the employee with the information
	struct Employee* e = makeEmployee(rndBirth,rndStrt,rndName);

	//Returns the pointer to the employee
	return e;
}

/**
 * Makes an array of random Employees
 * @count The number of random employees wanted
 * @return Returns an array of random employees
 */
struct Employee** makeEmployeeArray(int count){

	//Creates an array of pointers to employees and allocates memory for it
	struct Employee** employeeList;
	employeeList = (struct Employee**)malloc((sizeof(struct Employee*))*count);

	//i is an integer counter used to allocate values to the array one by one
	//Loop Invariant: Each time, a random employee is generated and then put into the array
	for(int i=0;i<count;i++){
		struct Employee* e;
		e=makeRndEmployee();
		employeeList[i]=e;
	}

	return employeeList;
}

/**
 * Prints the elements of an array of pointers to Employee structs
 * @array The array to be printed
 * @count The number of elements in the array/to be printed
 * @return void Does not return anything because it is printed
 */
void printArrayOfEmployees(struct Employee** array,int count){

	//i is a counter to access parts of the array of pointes being passed in
	//Goes until i<count because arrays used zero based indexing
	//Loop Invariant: An employee is accessed from the array temporarily and is then printed
	for(int i=0;i<count;i++){
		struct Employee* e1;
		e1=array[i];
		printEmployee(e1);
	}

}

/**
 * Duplicates an array of pointers to employees
 * @param array The array to be duplicated
 * @param count The number of entries in the array
 * @return newArray Returns the duplicated array of pointers
 */
struct Employee** duplicateEmployeeArray(struct Employee** array,int count){

	//Creates an array of pointers and allocates memory for it
	struct Employee** newArray = (struct Employee**)malloc(sizeof(struct Employee*)*count);

	//i is an integer counter used to access parts of the arrays
	//Goes until i<count because arrays used zero based indexing
	//Loop Invariant: The new array is filled with the pointers in the old array one by one
	for(int i=0;i<count;i++){
		newArray[i]=array[i];
	}

	return newArray;
}

/**
 * Makes a deep copy of an array of pointers to employees
 * @param array The array to be deep copied
 * @param count The size of the array
 * @return Returns the deep copied array
 */
struct Employee** makeDeepCopy(struct Employee** array,int count){

	//Makes memory for the array
	struct Employee** employeeList = (struct Employee**)malloc(count*sizeof(struct Employee*));
	//Makes a holder
	struct Employee** holder = employeeList;

	//i is an integer counter used to access parts of the array
	//Loop Invariant: Allocates memory for each struct and then puts it in the new array
	for(int i = 0;i<count;i++){
		//Allocates memory
		employeeList[i]=(struct Employee*)malloc(sizeof(struct Employee));
		//Puts it into the array
		employeeList[i][0]=array[i][0];
	}

	//Returns the pointer to the array
	return holder;
}

/**
 * Prints the employees information to the console
 * @param e The employee that the information is wanted for
 * @return void Does not return anything because it is just printing
 */
void printEmployee(struct Employee *e) {

	//Prints the employees information
	printf("'%s' is an employee who was born in the year %i and started in %i\n",
			e->name,e->birth_year,e->start_year);

}

/**
 * Frees the values inside an array of pointers to employees
 * @param array The array that contains the values to be freed
 * @param count The number of entries in the array
 * @return void Does not return anything since the only thing that is occuring is the freeing
 */
void freeArrayValues(struct Employee** array,int count){

	//i is a counter that increments each time that is used to acess sequential parts of the
	//array
	//Loop Invariant: Goes through the array freeing one element at a time
	for(int i=0;i<count;i++){
		free(array[i]);
	}

}


