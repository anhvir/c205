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
	float a, b, x;    

	/* Step 1: input data */
	scanf(&a);
	scanf("%f", b);

	/* Step 2: Computation */
	x= -b/a;

	/* Step 3: output solution */
	printf("Solution for %.2fx + %.2f = 0 is x= %.2f\n", a, b, x);
   
	return 0;
}
