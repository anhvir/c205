/*    
	Purpose : sorting arrays of integers 
   
	Started by: Anh Vo, anhvir@gmail.com, 20 Apr 2017
	Finished by: 

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000		/* maximal array size */ 

int readArray(int a[]); 
void printArray(char *title, int a[], int n);
void ins_sort(int a[], int n);
void sel_sort(int a[], int n);
void rec_sel_sort(int a[], int n);

int
main(int argc, char *argv[]) {
	int n=0;			/* current number of elements in array */
	int a[MAX_N];

	n= readArray(a);
	printArray("Original array", a, n);

	/* change the next 2 lines to switch to the appropriated sorting */	
	ins_sort(a,n);
	printArray("Insertion Sort. Sorted array= ", a, n);

	return 0;
}

/* reads array from stdin  
   returns the number of elements in the array
*/ 
int readArray(int a[]) {  
	int i;
	for (i=0; i<MAX_N && scanf("%d", &a[i])==1; i++);  /* empty body */
	return i;
}


/* print out the array a[n] after printing a title
*/  
void printArray(char *title, int a[], int n) {
	int i;
	printf("%s:\n", title);
	for (i=0; i<n; i++) printf ("%3d", a[i]);
	printf("\n\n");
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

/* sorting elements of a[] in increasing order
   using selection sort    
*/	
void sel_sort(int a[], int n){
	int i, j;
	for (i=n-1; i>0; i--) {    /* perform n-1 round         */
		/* in round i, examine all (unsorted) elements of a[0..i]  	*/
		/*             and find imin so that a[imin] is the largest */


		/* then swap a[min] and a[i] to place the largest at the end */

		/* now, a[i] is in its final position of the sorted array    */
	}
}

/* sorting elements of a[] in increasing order
   using recursive selection sort 

   Logic: to sort n elements of a[]:
		- first, arrange the largest to the last position
		- then, sort n-1 elements of a[], using the same method   
	   
*/	
void rec_sel_sort(int a[], int n){
	int i, imin;

	/* examine all n elements of a[], 
		and find imin so that a[imin] is the largest */

	/* swap a[min] and a[n-1] to place the largest at the end */

	/* now, the last element is the largest, call rec_sel_sort,
	   again to apply the same logic to the first n-1 elements */
 
}
