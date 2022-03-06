/*--------------------------------------------------------------------
   equation.c: solving equation ax + b = 0 where a, b are real numbers
   Author: comp20005 students in the first programming workshop 
   Last updated: MAR/2022 

 
   Notes:
     + This program is under construction and might contain errors
--------------------------------------------------------------------*/
 
#include <stdio.h>

int main(int argc, char *argv[]) { 


	// Declarations
	double a, b;
	double x;    

	printf("=========== Solving equation ax + b = 0 ==========\n");

	// Step 1: input data 
	scanf(a, b);

	// Step 2: Computation 
	x= -b/a;

	// Step 3: output solution 
	printf("%f", a, b, x);
   
	
	return 0;
}
