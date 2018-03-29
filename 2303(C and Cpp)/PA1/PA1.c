#include <stdio.h>

//JP Bulman

/**
 * Prints the name of the month.
 * @param yearNumber, the year for the given month
 * @param monthNumber, the desired month to be printed
 * @return int, corresponds to the number of days in the month
*/
int printMonthName(int yearNumber,int monthNumber){

 //Switches the given month number to detemine which month name is being printed. 1 is January, 2 is February, etc.
 switch(monthNumber){

  case 1:
   printf("January %i\n", yearNumber);
   //Number of days in January
   return 31;
   //Stops the switch
   break;

  case 2:
   printf("February %i\n", yearNumber);

   //An equivalent of a boolean to determine if the year is a leap year, n!=0 is true, 0 is false
   //First tests to see if the year is divisible by 4
   //If it is, then it checks to see if it is not divisible by 100
   //If that fails, then it checks to see if it is divisible by 100 and 400
   int isLeapYear=0;
   if(yearNumber % 4 == 0){
     if(yearNumber % 100 != 0){isLeapYear = 1;}
     if(yearNumber % 100 == 0 && yearNumber % 400 == 0){isLeapYear = 1;}
   }

   //If it is a leap year, then return 29 days
   if(isLeapYear != 0){return 29; break;}

   //Otherwise, return 28
   return 28;
   break;

  case 3:
   printf("March %i\n", yearNumber);
   return 31;
   break;

  case 4:
   printf("April %i\n", yearNumber);
   return 30;
   break;

  case 5:
   printf("May %i\n", yearNumber);
   return 31;
   break;

  case 6:
   printf("June %i\n", yearNumber);
   return 30;
   break;

  case 7:
   printf("July %i\n", yearNumber);
   return 31;
   break;

  case 8:
   printf("August %i\n", yearNumber);
   return 31;
   break;

  case 9:
   printf("September %i\n", yearNumber);
   return 30;
   break;

  case 10:
   printf("Ocotber %i\n", yearNumber);
   return 31;
   break;

  case 11:
   printf("November %i\n", yearNumber);
   return 30;
   break;

  case 12:
   printf("December %i\n", yearNumber);
   return 31;
   break;

  //Returns 999 in any other case as a strong indicator something has gone wrong
  default: return 999;

  }

}


/**
 * Prints the given month
 * @param yearNumber, the year for the given month
 * @param monthNumber, the desired month to be printed
 * @param startingDay, the desired day for the month to start on
 * @return currentDayOfTheWeek, the day that the next month will start on
*/  
int printMonth(int yearNumber,int monthNumber,int startingDay){

  printf("\n");

  //Gets the number of days in the given month
  int numberOfDaysInMonth = printMonthName(yearNumber, monthNumber);

  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  //The current day of the week that is being viewed (0 is Sunday -> 6 is Saturday)
  int currentDayOfTheWeek = startingDay;

  //Loop to print the first day
  //Invariant: i increases by 1 and if the currentDayOfTheWeek is i, the day will be printed
  //i is a counter for the loop that represent the days of the week
 for(int i = 0; i<=6; i++){
  if(currentDayOfTheWeek==i){
  
  //Checks to see if it is the end of a week or not
  if(currentDayOfTheWeek==6){printf("  %i\n",1);currentDayOfTheWeek=-1;break;}
  else{printf("  %i",1);break;}
  
  }
  //Formats an empty day and moves on to the next one
  else{printf("     ");}
 }

  //After the first day is printed, the method needs to move on to the next day
  currentDayOfTheWeek++;

 //Prints the days out until the end of the month
 //currentNumberDay is the current numerical date, first day was printed, so it starts on 2
 //Invariant: The NumberDay moves up 1 and the current day is moved up by 1
 for(int currentNumberDay=2; currentNumberDay <= numberOfDaysInMonth; currentNumberDay+=1,currentDayOfTheWeek+=1){
 
  //Print formating is different for the first day of the week, uses 2 spaces instead of 4
  if(currentDayOfTheWeek==0){
   //Checks to see if the day is one or two digits long
   if(currentNumberDay<10){printf("  %i",currentNumberDay);}
   else{printf(" %i",currentNumberDay);}
  }
 
  //Checks to see if the day is at the end of a week (Saturday)
  else if(currentDayOfTheWeek==6){
   //Since currentDayOfTheWeek need to be a Sunday when increased, so it is given -1
   if(currentNumberDay<10){printf("    %i\n",currentNumberDay);currentDayOfTheWeek=-1;}
   else{printf("   %i\n",currentNumberDay);currentDayOfTheWeek=-1;}
  }
 
  //If it is not a special case, just print the day out standardly
  else{
   if(currentNumberDay<10){printf("    %i",currentNumberDay);}
   else{printf("   %i",currentNumberDay);}
  }

  //If it is the end of the month and there is not already a line break, make one
  if(currentNumberDay==numberOfDaysInMonth&&currentDayOfTheWeek!=-1){printf("\n");}

 }

 return currentDayOfTheWeek;
 
}


/**
 * Gets the starting day of a given year
 * @param yearNumber, the year for the wanted day
 * @return currentDay, the day of the week that the year starts on
*/ 
int startingDayOfYear(int yearNumber){

   //Keeps track of what year is currently being analyzed
   int currentYear = 1582;
   //1582 started on a Friday (5), but the loop immediately increments, so 4 is the initial
   int currentDay = 4;

  //To determine the day if the year is after 1582
  if(yearNumber>=1582){

   //Loop that works forwards from 1582 to determine the starting day of a year
   //Invariant: The currentYear is incremented by 1 until it reaches the year we want
   //Each time, it checks to see if the day should be increased by 1 or 2
   for(currentDay=4;currentYear<=yearNumber;currentYear++){

    //If the next year is a leap year, the current day should be increased by 2
    if((currentYear-1) % 4 == 0){
       if((currentYear-1) % 100 != 0){currentDay+=2;}
       else if((currentYear-1) % 100 == 0 && (currentYear-1) % 400 == 0){currentDay+=2;}
       else{currentDay+=1;}
    }
    else{currentDay++;}

    //Special cases when Friday(5) or Saturday(6) happen adjacent to a leap year
    if(currentDay==7){currentDay=0;}
    if(currentDay==8){currentDay=1;}

   }

  }

  //To determine the day if the year is before 1582
  else{

   //Loop that works backwards from 1582 to determine the starting day of a year
   //Invariant: The currentYear is decreased by 1 until it reaches the year we want
   //Each time, it checks to see if the day should be increased by 1 or 2
   for(currentDay=6;currentYear>=yearNumber;currentYear--){

    //If the previous year is a leap year, the current day should be increased by 2
    if((currentYear+1) % 4 == 0){
       if((currentYear+1) % 100 != 0){currentDay-=2;}
       else if((currentYear+1) % 100 == 0 && (currentYear-1) % 400 == 0){currentDay-=2;}
       else{currentDay-=1;}
    }
    //If it is not a leap year, increase the current day by 1
    else{currentDay--;}

    //Special cases
    if(currentDay==-1){currentDay=6;}
    if(currentDay==-2){currentDay=5;}

   }

  }
  
return currentDay;

}

/**
 * Gets the starting day of a given year
 * @param yearNumber, the year to be printed
 * @param startDay, the day the year starts on
 * @return void, does not return anything
*/ 
void printCalendar(int yearNumber, int startingDay){

 //Prints out the month each iteration
 //currentMonth is the current month in the loop to be printed
 //Invariant: Mutates the starting day for the next month and currentMonth is increased by 1
 for(int currentMonth=1;currentMonth<=12;currentMonth++){
   startingDay = printMonth(yearNumber,currentMonth,startingDay);
 }

}


int main(void){

//The year the user wants to see the calendar for
int userYear;

printf("Please enter year for this calendar:- ");
scanf("%i",&userYear);

//Error message if the year is invalid (less than or equal to 0)
if(userYear<=0){
printf("You entered a year less than or equal to 0 \n");
return 0;
}

printf("\n\n  ***    Calendar for %i   ***\n",userYear);
printCalendar(userYear,startingDayOfYear(userYear));

return 0;
}
