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

	scanf(&a);
	scanf("%f", b);

	x= -b/a;

	printf("Solution x= %.2d\n", x);
   
	return 0;
}
