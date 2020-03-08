/*
   equation.c: solving equation ax + b = 0 where a, b are real numbers
   Author: 
     + Skeleton by Anh Vo, anhvir@gmail.com
     + Final vesrion by: 
   Last updated: 
*/

/* 
   Notes:
     + This program might have errors and/or be incomplete
     + Your task is to make it working nicely
*/
 
#include <stdio.h>

int main(int argc, char *argv[]) { 
	int a, b;
	double x;    

	printf("=========== Solving equation ax + b = 0 ==========\n");

	/* Step 1: input data */
	printf("Enter value for a, b: "); 
	scanf(a, b);

	/* Step 2: Computation */
	x= -b/a;

	/* Step 3: output solution */
	printf("Solution for %dx + %d = 0 is x= %.2f\n", a, b, x);
   
	return 0;
}
