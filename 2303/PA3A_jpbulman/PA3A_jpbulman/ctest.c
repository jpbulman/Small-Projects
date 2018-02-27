#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

//JP Bulman

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * Add your own @author line below.
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;           // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("For string /%s/, mystrlen1() returns %ld\n", p1, mystrlen2(p1));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2, a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);


	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("Using strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0) mystrncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);




	printf("\n___Testing of mystrlen___\n");
	char hwCharArray[20] = "Hello World!";

	int strlen1HW = mystrlen1(hwCharArray);

	printf("First mystrlen1 is tested with a char array\n");

	printf("The length of '%s' is %i characters\n",hwCharArray,strlen1HW);

	printf("Second, mystrlen2 is tested with a char pointer\n");

	char* assignment3CharPointer = "Assignment 3!";

	int strlen1A3 = mystrlen1(assignment3CharPointer);

	printf("The length of 'Assignment 3!' is %i characters\n",strlen1A3);

	char c[0] = "";

	printf("Now the functions can be tested with an empty string\n");

	int mtStringLen = mystrlen1(c);
	int mtStringLen2 = mystrlen2(c);

	printf("The length of '' using mystrlen1 is %i\n",mtStringLen);
	printf("The length of '' using mystrlen2 is %i\n",mtStringLen2);



	//strcpy
	printf("\n___Testing of mystrcpy___\n");
	char testArray[20] = "This is a test";

	printf("The value of 'testArray' is '%s'\n",testArray);
	printf("Now copying 'Cows go Moo' into 'testArray'\n");

	char *f = mystrcpy(testArray,"Cows go Moo");

	printf("The value of 'testArray' is now '%s'\n",testArray);

	printf("The value of the return pointer of mystrcpy is '");

	int len;
	len = strlen(f);
	for(int i =0;i<=len;i++,*f++){
	printf("%c",*f);
	}
	printf("'\n");



	//strncpy
	printf("\n___Testing of mystrncpy___\n");
	char testArray2[20] = "This is a test";

	printf("The value of 'testArray2' is '%s'\n",testArray2);
	printf("Now copying 4 bytes (less than) of 'Cows go Moo' into 'testArray2'\n");

	char *m = mystrncpy(testArray2,"Cows go Moo",4);

	printf("The value of 'testArray2' is now '%s'\n",testArray2);

	printf("The value of the return pointer of mystrncpy is '");

	len = strlen(m);
	for(int i =0;i<=len;i++,*m++){
	printf("%c",*m);
	}

	printf("\n");

	char testArray3[20] = "This is a test";

	printf("The value of 'testArray3' is '%s'\n",testArray3);
	printf("Now copying 30 bytes (more than) of 'Cows go Moo' into 'testArray3'\n");

	char *morethan = mystrncpy(testArray3,"Cows go Moo",30);

	printf("The value of 'testArray3' is now '%s'\n",testArray3);

	printf("The value of the return pointer of mystrncpy is '");

	len = strlen(morethan);
	for(int i =0;i<=len;i++,*morethan++){
	printf("%c",*morethan);
	}

	printf("\n");

	char testArray4[20] = "This is a test";

	printf("The value of 'testArray4' is '%s'\n",testArray4);
	printf("Now copying 14 bytes (equal to) of 'Cows go Moo' into 'testArray4'\n");

	char *equalTo = mystrncpy(testArray4,"Cows go Moo",14);

	printf("The value of 'testArray4' is now '%s'\n",testArray4);

	printf("The value of the return pointer of mystrncpy is '");

	len = strlen(equalTo);
	for(int i =0;i<=len;i++,*equalTo++){
	printf("%c",*equalTo);
	}

	printf("\n");



	//strcat
	printf("\n___Testing of mystrcat___\n");
	char fooArray[20] = "Foo bar baz";

	printf("The current value of 'fooArray' is '%s'\n",fooArray);

	printf("Now adding ' 3535' to 'fooArray'\n");

	char *moo = mystrcat(fooArray," 3535");

	printf("The value of the return pointer of mystrcat is '");

	int length = mystrlen1(moo);
	for(int i = 0;i<=length;i++,*moo++){
	printf("%c",*moo);
	}
	printf("\n");




	//strncat
	printf("\n___Testing of mystrncat___\n");
	char citiesArray[20] = "Boston and NYC ";
	printf("The value of 'citiesArray' is currently '%s'\n",citiesArray);
	printf("Now copying 20 bytes (more than) of 'boo' into '%s'\n",citiesArray);
	char* returner  = mystrncat(citiesArray,"boo",20);
	printf("The value of 'citiesArray' is now '%s'\n",citiesArray);

	printf("The value of the return pointer of mystrncat is '");

	int length0 = mystrlen1(returner);
	for(int i = 0;i<=length0;i++,*returner++){
	printf("%c",*returner);
	}
	printf("\n");

	char citiesArray1[20] = "Boston and NYC ";
	printf("The value of 'citiesArray1' is currently '%s'\n",citiesArray1);
	printf("Now copying 3 bytes (equal to) of 'boo' into '%s'\n",citiesArray1);
	char* returner1  = mystrncat(citiesArray1,"boo",3);
	printf("The value of 'citiesArray1' is now '%s'\n",citiesArray1);

	printf("The value of the return pointer of mystrncat is '");

	int length1 = mystrlen1(returner1);
	for(int i = 0;i<=length1;i++,*returner1++){
	printf("%c",*returner1);
	}
	printf("\n");

	char citiesArray2[20] = "Boston and NYC ";
	printf("The value of 'citiesArray2' is currently '%s'\n",citiesArray2);
	printf("Now copying 1 byte (less than) of 'boo' into '%s'\n",citiesArray2);
	char* returner2  = mystrncat(citiesArray2,"boo",1);
	printf("The value of 'citiesArray2' is now '%s'\n",citiesArray2);

	printf("The value of the return pointer of mystrncat is '");

	int length2 = mystrlen1(returner2);
	for(int i = 0;i<=length2;i++,*returner2++){
	printf("%c",*returner2);
	}


	printf("\n");



	//strndup
	printf("\n___Testing of mystrndup___\n");
	char* familyStr = "Joe Moe Roe";
	printf("The value of 'familyStr' is currently '%s'\n",familyStr);
	printf("Now copying 5 bytes (less than) of 'familyStr' into variable 's'\n");
	char* s  = mystrndup(familyStr,5);
	printf("The value of 's' is '%s",s);
	printf("\n");

	char* familyStr2 = "Joe Moe Roe";
	printf("The value of 'familyStr2' is currently '%s'\n",familyStr2);
	printf("Now copying 11 bytes (equal to) of 'familyStr2' into variable 's2'\n");
	char* s2  = mystrndup(familyStr2,11);
	printf("The value of 's2' is '%s",s2);
	printf("\n");

	char* familyStr3 = "Joe Moe Roe";
	printf("The value of 'familyStr3' is currently '%s'\n",familyStr3);
	printf("Now copying 20 bytes (great than) of 'familyStr3' into variable 's'\n");
	char* s3  = mystrndup(familyStr,20);
	printf("The value of 's2' is '%s'",s3);

	return 0;
}
