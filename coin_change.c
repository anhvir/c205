/* coin_change.c : a skeleton, the first example of using arrays
                   based on exercise 6.9
                   
   anhvir@gmail.com. for unimelb COMP20005 workshop week 6
*/

/* INTRODUCTION TO ARRAY: 
   When we declare
        int A[10];
   we have A as an array of 10 elements, that means:
     - we have 10 "int" variables with the name A[0], A[1], A[2], ..., A[9]
       the value 0, 1, ... 9 themselves are called INDEX
     - we can use an "int" variable for index, for example, if declared:
         int i = 4;
       then A[i] refers to A[4], A[i+1] refers to A[5], A[i-2] to A[2]
     - a beautiful thing is that we can use a loop to process array:
         for (i=0; i<10; i++) {
            A[i]= i+1;
         }
       will set A[0] to 1, A[1] to 2, ..., A[9] to 10
     - now, if we want to compute s= sum of elements of A, we do:
         int s= 0;
         for (i=0; i<10; i++) {
            s += A[i];
         }
   Carefully read print_change (below) to see the application of array
   for this exercise 6.9.
*/  


#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 99
#define N_COINS 6   /* 6 diffrent coins: 1, 2, 5, 10, 20, 50 */

int try_one_coin(int *cents, int coin);
void print_change(int cents);

int main(int argc, char *argv[]) {
	int cents;
	printf("Enter amount in cents: ");
	if (scanf("%d", &cents) != 1 || cents<MIN || cents>MAX ) {
		printf("Please enter integer between %d and %d\n", MIN, MAX);
		exit(EXIT_FAILURE);
	}
	print_change(cents);
	return 0;
}

int try_one_coin(int *cents, int coin) {
	printf("try_one_coin not yet implemented, do it now!\n");
	exit(EXIT_FAILURE);
}


/* print_change will print changes for the amount "cents"
   LOGIC:
   As we did ewrlier for ex 3.6, we need to try "cents" with coin 50,
   then with coins 20, 10, 5, 2 ,1. In ex 3.6 we did that one by one,
   in a boring and awful method.
   But now, we can build an array of coin values, say coins[0] is 50,
   coins[1] is 20 etc. Then, if we make a loop with i= 0, 1, ... we
   will have coins[i] having value 50, 20, ...
   Try to understand the code below:
*/ 
void print_change(int cents) {
	int coins[N_COINS]= {50, 20, 10, 5, 2, 1};
	/* here we declared and initialized value for coins[],
       note that we need to use { and } in initializing array values */
	int i, j, ncoins;
	printf("The chnages for %d cents are:\n", cents);
	for (i=0; i<N_COINS; i++ ) {
		/* now coins[i] is the coin we consider, starting from coins[0]
           with is 50  */
		ncoins= try_one_coin(&cents, coins[i]); /* dealing with coins[i] */
		/* now print "ncoins" apperances of "coins[i]" */
		for (j=0; j<ncoins; j++) {
			printf("%d", coins[i]);
			if (j<ncoins-1 || cents>0) {  /* print "," when needed */
				printf(", ");
			} 
		}
	}
	printf("\n");
}



