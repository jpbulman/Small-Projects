/** mystruct.h
 * @author Mike Ciaraldi
 * Sample structs
*/

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee *makeEmployee(int birth, int start, const char* name);
struct Employee* makeRndEmployee(void);
struct Employee** makeEmployeeArray(int count);
struct Employee** duplicateEmployeeArray(struct Employee** array,int count);
void freeArrayValues(struct Employee** array,int count);
void printArrayOfEmployees(struct Employee** array,int count);
void printEmployee(struct Employee *e);
int getRandInt(int max);
char getRandANChar(void);
char* getRandString(int length);
struct Employee** makeDeepCopy(struct Employee** array,int count);
