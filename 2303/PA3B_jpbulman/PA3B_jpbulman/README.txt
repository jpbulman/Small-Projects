JP Bulman
PA3A

This program is designed to show the use of structs using the 'Employee' struct and the respective added functions. An employee is a struct that has three fields: an integer for the birth year, an integer for the starting year, and a string for the name of the employee. An employee can be created using the 'makeEmployee' function and then filling in its respective arguments. To generate an employee with random fields, the 'makerRndEmployee' function can be used. There are more functions extending the structs with different features such as making an array of pointers to structs and more. Tests are provided to show all of the functionality of the types and functions (including the extra credit deep copy function).

Running the project
Eclipse
	To run this project in eclipse, first download the .zip file, and the then go to 'File' and 'Import'. Create a new project with the archive by choosing 'Select archive file'. Browse to the location of the zip and then upload that. Once the project has been created, build it once, and then use the green arrow to run the program as a 'local c/c++ application'. The program should run accordingly, printing out the test cases and function capabilities.
	
Command line
	Extract the zip into a destination and then locate that destination in the terminal. Then, launch the makefile in the folder and make sure that it runs and links/creates the projects files together. Then, run the command 'gcc -Wall structest.c' to make sure that everything is in order to run. Next, use 'make ./struct.c' to run the program in the terminal.
