/*
   equation2.c: solving equation ax + b = 0 where a, b are real numbers

   THE TASK: Change the program so that it works, and then works 
             correctly for all real values of a,b  

   Author: 
     + Skeleton by Anh Vo, anhvir@gmail.com
     + Final vesrion by: <your name here>
   
   
*/

 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	double a, b, x;    

	/* Step 1: input data */
	printf("SOLVING EQUATION ax + b = 0\n");
	printf("Enter 2 numeric value for a, b: ");

	// In the next line, replace XXX with a needed value!
	if ( scanf("%lf %lf", &a, &b) != XXX) {
		printf("Invalid input. Please try again.\n");
		exit( EXIT_FAILURE );
	}

	/* Step 2: Computation & output */
	// This part is troublesome if a is 0.0
	// You need to change it so that it works in all values of a, b
	x= -b/a;
	printf("Solution for %.2lfx + %.2lf = 0 is x= %.2lf\n", a, b, x);
   
	return 0;
}
