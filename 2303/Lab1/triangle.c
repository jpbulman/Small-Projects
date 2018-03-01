#include <stdio.h>
#include <math.h>

int main(void){

printf("Enter the x- and y- coordinates of point A:-");

double xA;
scanf("%lf", &xA );

double yA;
scanf("%lf", &yA );

printf("Enter the x- and y- coordinates of point B:- ");

double xB;
scanf("%lf", &xB);

double yB;
scanf("%lf", &yB);

printf("Enter the x- and y- coordinates of point C:- ");

double xC;
scanf("%lf", &xC);

double yC;
scanf("%lf", &yC);

double AB = sqrt(((xA-xB)*(xA-xB))+((yA-yB)*(yA-yB)));
double BC = sqrt(((xB-xC)*(xB-xC))+((yB-yC)*(yB-yC)));;
double CA = sqrt(((xC-xA)*(xC-xA))+((yC-yA)*(yC-yA)));;
printf("Length of AB is %lf \n",AB);
printf("Length of BC is %lf \n",BC);
printf("Length of CA is %lf \n",CA);

double circumference = AB+BC+CA;
printf("Circumference is %f \n", circumference);

double s = .5*circumference;
double area = sqrt((s)*(s-AB)*(s-BC)*(s-CA));

printf("Area is %f\n",area);

  return 0;
}
