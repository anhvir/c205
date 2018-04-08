/*    
	Purpose : using array (with random values) 
   
	Skeleton by: Anh Vo, anhvir@gmail.com, 05 Apr 2017
	Finished by:

	Instructions:
		- compile and try the program
		- implement points ****1**** and *****2*****  
		- implement point ****3**** if you can
*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

void buildArray(int a[], int n); 
void printArray(char *title, int *a, int n);
int sum(int a[], int n); 

int
main(int argc, char *argv[]) {
	int a[N];

	buildArray(a, N);
	printArray("Original array", a, N);

	/* ****1**** */
    /* squareArray(a, N); */    
    /* YOU HAVE TO WRITE function squareArray
		that chang each element of array to
		its squared value, and call it here   */
	printArray("New array", a, N);

    printf("sum of array elements= %d\n", sum(a, N));

	/* ****2**** */
	/* printf("sum of even elements of array= %d\n", sumEven(A, n); */
	/* YOU HAVE TO WRITE function sumEven that returns the sum of 
		the elements which are even */
	
	/* ****3****: write and call a function to sort the array
					in increasing order  */ 

	return 0;
}

/* fill in array a[n] with random values from 1 to 20 
   (note the way array name a and value n are declared in function header)
*/ 
void buildArray(int a[], int n) {  
	int i;
	for (i=0; i<n; i++) {
		a[i]= rand()%20 + 1;  /* rand() returns a random integer */ 
	}
}


/* print out the array after printing a title,
   Note that here "int *a" is another way for writing "int a[]"
*/  
void printArray(char *title, int *a, int n) {
	int i;
	printf("%s: ", title);
	for (i=0; i<n; i++) printf ("%3d", a[i]);
	printf("\n\n");
}

/* returns sum od elements of arrays a */
int sum(int a[], int n) {
	int i, sum=0;
	for (i=0; i<n; i++) {
		sum += a[i];
	}
	return sum;
}
