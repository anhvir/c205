/*
	scanf_test.c
	A program to play with and understand scanf better
	Anh Vo, anhvir@gmail.com, for use in unimelb comp20005 workshop week 3
*/
 
#include <stdio.h>

#define BIG 1000


int main(int argc, char *argv[]) { 
	int a=0;
	double x=0;
	char c=0;
	
	int n3= BIG;

	printf("Enter 1 integer, 1 letter and 1 float: ");
	n3= scanf("%d %c %lf", &a, &c, &x);
	printf("\nNumber of data items sucessfully read, n3= %d\n", n3);
	printf("Values:  integer a= [%d] letter c=[%c] float x=[%lf]\n\n", a, c, x);  
   
	printf("Exercises:\n");
	printf("\t1. Explain: Why above outputs? In particular, why n3 is 3?\n");
	printf("\t2. Try the program with some other inputs, such as: \n");
	printf("\t\t 12A6.5\n");
	printf("\t\t 12  A   6.5\n");
	printf("\t\t 12.4A6.5\n");
	printf("\t\t 123A\n");
	printf("\t\t 123Ax\n");
	printf("\t\t 123 A x\n");
	printf("\t\t A12B3\n");
	printf("\tand each time explain the outputs\n");
	return 0;
}
