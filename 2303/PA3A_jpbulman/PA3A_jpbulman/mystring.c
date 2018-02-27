/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

//JP Bulman

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/**
 * Returns the length of a string
 * @param s The pointer to the string we want to find the length of
 * @return size Returns the length of the string
 */
size_t mystrlen1(const char *s){

	//Initial size is 0
	size_t size = 0;

	//Array counter
	int i = 0;

	//Loop Invariant: The size is increased by one each time as the loop moves along each part
	//of the string
	while(s[i]!='\0'){
		//Adds one to the size
		size+=1;
		//Moves to the next part of the string
		i++;
	}

	//Returns the lenght of the string
	return size;
}

/**
 * Returns the length of a string
 * @param s The pointer to the string of chars we want to find the length of
 * Returns the length of the string
 */
size_t mystrlen2(const char *s){

	//Size is zero before the loop
	int size = 0;

	//Loop Invariant: The size increases by one as the pointer is moved along the string of
	//chars
	while(*s!='\0'){
		//Adds one to the size
		size+=1;
		//Moves the pointer to the next byte (next char)
		s++;
	}

	//Returns the length of the string
	return size;
}

/**
 * Copies the string in src into dest, including the null terminator
 * @param dest The destination the copy is going to
 * @param src The string to be copied
 * @return Returns a pointer to the new dest char
 */
char *mystrcpy(char *dest, const char *src){

	//Creates a placeholder pointer to dest since it is being operated on in the function
	char *holder = dest;

	//Loop Invariant: The pointers move to the next char each iteration, and then are copied
	//byte by byte into dest until all of src has been copied in
	for(;*src!='\0';src++,dest++){
		*dest=*src;
	}

	//Adds the null terminator to the end
	*dest='\0';

	//Returns the pointer to dest
	return holder;
}

/**
 * Takes the src string and appends it onto the end of dest
 * @param dest The string to be appended
 * @param src The string to append on to dest
 * @return returns the pointer to the char for the new dest
 */
char *mystrcat(char *dest, const char *src){

	//Creats a placeholder pointer to dest while it is being worked on
	char *holder = dest;

	//Moves the current pointer to dest to the end in order to add the string on
	//Loop Invariant: Until the null terminator has been reached, the pointer is moved to the
	//next byte
	while(*dest!='\0'){
		dest++;
	}

	//Length of the source string
	int length = mystrlen1(src);

	//i is an integer counter that is used to access parts of the array from src
	//Loop Invariant: The value of the current pointer to dest is changed to the ith element
	//of src until all of src has been concatinated to the end
	for(int i=0;i<length;i++,*dest++){
		*dest=src[i];
	}

	//Add a null terminator to the end
	*dest = '\0';

	return holder;
}

/**
 * Appends 'n' bytes of the string src onto dest
 * @param dest The string src will be appended on to
 * @param src The string to be appended on to dest
 * @param n The number of bytes of string src to be put on to dest
 * @return Returns a pointer to the new char pointer
 */
char *mystrncat(char *dest, const char *src, size_t n){

	//Pointer made as a placeholder
	char *holder = dest;

	//Moves the current part of dest to the end where the string will be appended
	//Loop Invariant: Until the null terminator has been reached, the pointer is moved to the
	//next byte
	while(*dest!='\0'){
		dest++;
	}

	//Int made to determine how far in memory to go
	int max;

	//If the requested number of bytes is bigger than the actual size, set max to the size
	//so it does not go over
	if(n>sizeof(src)){max=sizeof(src);}
	//Other wise, set the max to the number of bytes requested
	else{max=n;}

	//i is an integer counter that is used to access parts of the src char array
	//Loop Invariant: The value of destination is the 'i'th value of the src until 'n' number
	//of bytes have been copied
	for(int i = 0;i<max;i++,*dest++){
		//Sets the value of the ith value of the source
		*dest=src[i];
	}

	//Add a null terminator to the end
	*dest = '\0';

	return holder;
}

/**
 * Copies n bytes of src into dest
 *@param dest The string to be copied over
 *@param src the string that is being copied
 *@param n The number of bytes of src that are being copied over
 *@return Returns a pointer to the new copied string
 */
char *mystrncpy(char *dest, const char *src, size_t n){

	//Creates a placeholder pointer
	char *holder = dest;

	//i is an integer counter
	//Loop Invariant: The value of the current pointer to src is made the value of dest until
	//the number of bytes has been reached
	for(int i = 0;i<=n;i++,src++,dest++){
		*dest=*src;
	}

	return holder;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/**
 * Duplicates 'n' bytes of string src
 * @param src The string to be duplicated
 * @param n The number of bytes of src to be duplicated
 * @return Returns a pointer to a char of the new duplicated string
 */
char* mystrndup(const char* src, size_t n) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrncpy(newstr, src, n);

  //Adds a null terminator to itself
  mystrcpy(newstr,newstr);

  return newstr;
}
