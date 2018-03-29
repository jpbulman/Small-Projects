#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");

	printEmployee(e);

	//Another example employee to test makeEmployee and printEmployee
	struct Employee *JP;
	JP = makeEmployee(1999, 2018, "JP Bulman");
	printEmployee(JP);

	//Another example employee to test makeEmployee and printEmployee
	struct Employee *Roger;
	Roger = makeEmployee(1944,1965, "Roger Daltrey");
	printEmployee(Roger);

	//An employee to test with 0 as the birth and start years and then an empty string for name
	struct Employee *blank;
	blank = makeEmployee(0,0,"");
	printEmployee(blank);

	//An employee with a null terminator as a name
	struct Employee *nullMan;
	nullMan = makeEmployee(1234,5678,"\0");
	printEmployee(nullMan);

	printf("\n");

	//Test to check functionality of making a random employee
	struct Employee *rndPerson;
	rndPerson = makeRndEmployee();
	printEmployee(rndPerson);

	printf("\n");

	//Free all the examples now that they are done being used
	free(nullMan);free(e);free(JP);free(Roger);free(blank);free(rndPerson);

	//Create an array of pointers
	struct Employee** rndEmployeeArray;
	//Fills the array with pointers to random employees using 'makeEmployeeArray' with size 10
	rndEmployeeArray=makeEmployeeArray(10);
	//Print the array of pointers to employees
	printArrayOfEmployees(rndEmployeeArray,10);

	printf("\n");

	//Create another array of pointers
	struct Employee** rndEmployeeArrayCopy;
	//Create a copy of the previous array of pointers
	rndEmployeeArrayCopy = duplicateEmployeeArray(rndEmployeeArray,10);
	//Print the duplicate to verify functionality
	printArrayOfEmployees(rndEmployeeArrayCopy,10);

	printf("\n");

	//Makes a deep copy using the extra credit function
	struct Employee** employeeArray = makeDeepCopy(rndEmployeeArray,10);

	printArrayOfEmployees(employeeArray,10);

	//Free all the values within the arrays now that they are not being used
	freeArrayValues(rndEmployeeArray,10);
	freeArrayValues(rndEmployeeArrayCopy,10);

	return 0;
}
