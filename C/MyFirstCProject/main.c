#include <stdio.h>

//Macro
#define FALSE 0;

int firstInt = 0;
char Char1 = 1;
unsigned int We = 123;
double aboutPi = (double)22/7;

// type name[size]
int myFirstArray[10];

int main() {
    printf("Hello, World!\n");

    //%d means to print a the following int
    printf("%d\n",firstInt+Char1+We);

    //To print floats and doubles, use %f
    printf("%f", aboutPi);

    return 0;
}