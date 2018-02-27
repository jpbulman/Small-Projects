JP Bulman
PA3A

This program is designed to replicate the standard c-library string operation functions. The ones made in this program are strlen (made in two different ways), strcpy, strcat, strncpy, strncat, strdup (two different ways), and strndup. These include all of the ups and downs of the normal functions as well. Meaning functions like strncpy will not add a null terminator to the end, just like the library functions. To build these functions, I mostly used loop structures that would do the necasssary function until it reached a null terminator, it which it would then finish. However, in certain functions, I had to check for other things first or use a counter instead (sometimes the strings would not have terminators). In lots of the functions, I also had to make a pointer to the dest parameter in order to preserve a correct value to return after the dest was operated on.

Running the project
Eclipse
	To run this project in eclipse, first download the .zip file, and the then go to 'File' and 'Import'. Create a new project with the archive by choosing 'Select archive file'. Browse to the location of the zip and then upload that. Once the project has been created, build it once, and then use the green arrow to run the program as a 'local c/c++ application'. The program should run accordingly, printing out the test cases and function capabilities.
	
Command line
	Extract the zip into a destination and then locate that destination in the terminal. Then, launch the makefile in the folder and make sure that it runs and links/creates the projects files together. Then, run the command 'gcc -Wall ctest.c' to make sure that everything is in order to run. Next, use 'make ./ctest.c' to run the program in the terminal.
