/*
	scanf_test.c
	A program to play with and understand scanf better
	Anh Vo, anhvir@gmail.com, for use in unimelb comp20005 workshop week 3
*/
 
#include <stdio.h>

int main(int argc, char *argv[]) { 
	int a;
	double x;
	char c;
	
	int data_read;

	printf("Enter 1 integer: ");
	data_read= scanf("%d", &a);
	printf("Number of data items sucessfully read= %d\n", data_read);
	printf("Value = %d\n\n", a);  

	printf("Enter 1 integer and 1 float: ");
	data_read= scanf("%d %lf", &a, &x);
	printf("Number of data items sucessfully read= %d\n", data_read);
	printf("Value = %d %lf\n\n", a, x);  
   
	printf("Enter 1 integer, 1 letter and 1 float: ");
	data_read= scanf("%d %c %lf", &a, &c, &x);
	printf("Number of data items sucessfully read= %d\n", data_read);
	printf("Value = %d %c %lf\n\n", a, c, x);  
   
	return 0;
}
