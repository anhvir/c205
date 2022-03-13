/*
   min_max.c: computes the min and max value of 3 numbers 

   Author: 
     + Skeleton by Anh Vo, anhvir@gmail.com
     + Final vesrion by: <your name here>
*/

 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { 
	double a, b, c;    // variables for input data
	double min;        // variables for output

	/* Step 1: input data */
	printf("FINDING MIN OF THREE NUMBERS\n\n");
	printf("Enter 3 real numbers: ");

	// In the next line, replace XXX with a needed value!
	if ( scanf("%lf %lf %lf", &a, &b, &c) != XXX) {
		printf("Invalid input. Please try again.\n");
		exit( EXIT_FAILURE );
	}

	/* Step 2: Compute min and max, add your code here */
   


    /* Step 3: Output results */
	printf("Input values are %.2lf, %.2lf, and %.2lf\n", a, b, c);
	printf("min= %.2lf\n\n", min, max);

	return 0;
}
