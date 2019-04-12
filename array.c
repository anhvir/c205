/*    
	Purpose : using array (with random values) 
   
	Skeleton by: Anh Vo, anhvir@gmail.com, 05 Apr 2017
	Finished by:

	Instructions:
		- compile and try the program
		- implement points ****1**** and *****2*****  
		- implement point ****3**** if you can

    Note: NO CHANGE from last week
*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

int readArray(int a[]); 
void printArray(char *title, int a[], int n);
int sum(int a[], int n); 
void ins_sort(int a[], int n);

int
main(int argc, char *argv[]) {
	int a[N];
	int n;

	n= readArray(a);
	printArray("Original array", a, n);

	/* ****1**** */
    /* squareArray(a, N); */    
    /* YOU HAVE TO WRITE function squareArray
		that chang each element of array to
		its squared value, and call it here   */
	printArray("New array", a, n);

    printf("sum of array elements= %d\n", sum(a, n));

    printf("\n SORTING:\n");
	ins_sort(a,n);
	printArray("\nSorted array:", a, n);


	/* ****2**** */
	/* printf("sum of even elements of array= %d\n", sumEven(A, n); */
	/* YOU HAVE TO WRITE function sumEven that returns the sum of 
		the elements which are even */
	
	/* ****3****: write and call a function to sort the array
					in increasing order  */ 

	return 0;
}


/* reads array from stdin  
   returns the number of elements in the array
*/ 
int readArray(int a[]) {  
	int i;
	for (i=0; i<N && scanf("%d", &a[i])==1; i++);  /* empty body */
	return i;
}


/* print out the array after printing a title,
   Note that here "int *a" is another way for writing "int a[]"
*/  
void printArray(char *title, int a[], int n) {
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





/* swapping values of two integer locations
*/
void swap(int *pa, int *pb) {
	int t= *pa;
	*pa= *pb;
	*pb= t;
}

/* sorting elements of a[] in increasing order
   using insertion sort    
*/	
void ins_sort(int a[], int n){
	int i, j;
	for (i=1; i<n; i++) {  /* perform n-1 rounds  			*/     
		/* in round i, insert a[i] to the sorted a[0..i-1] 	*/
		/*             so that a[0..i] becomes sorted       */ 
		for (j=i-1; j>=0 && a[j] > a[j+1]; j--) {
			swap( &a[j+1], &a[j] );
		}

		/* the following 5 lines just print out interim results
		   and make no change to the arry or the sorting process
		   of course, these lines should be removed from the final code	*/
		printf ("Step %2d: ",i);
		for (j=0; j<=i; j++) printf(" %2d", a[j]);
		printf("  ||  ");
		for (   ; j<n; j++) printf(" %2d", a[j]);
		printf("\n");

	}
}

