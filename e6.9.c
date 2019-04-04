/* Bad version for Exercise 6.9: Calculating change


   Exercise 3.6: Calculating change
   This is an ugly program, and if arrays and loops are used it can be made
   much more elegant, see Chapter 7.
   Alistair Moffat, March 2013.

   Modified by Anh Vo, to make a start for Ex 06-09
   REQUIREMENT: Change the program to fit the requirement of Ex 6.9, ie:
     - not using coins 2 and 1 cents
     - round the amount to the closest multiple of 5
     - use functions to avoid duplicated segments of code
 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHANGE 99


#define COIN1 50
#define COIN2 20
#define COIN3 10
#define COIN4 5
#define COIN5 2
#define COIN6 1

int round_to_five(int);

int
main(int argc, char *argv[]) {

	int amount;

	/* get the input value */
	printf("Enter amount in cents: ");
	if (scanf("%d", &amount)!=1 || (amount<0) || (amount>MAX_CHANGE)) {
		/* the if statement is introduced in Chapter 3 */
		printf("Error in input\n");
		exit(EXIT_FAILURE);
	}


	printf("the coins required to make %d cents are:\n      ", amount);

    /* first round up amount to the closest multiple of five  */
	amount= round_to_five(amount);

	/* now try all the coins, one by one, noting that some coins have
	   to be tried twice, and so for simplicity, this program in fact
	   tries every coin twice. Note that highly repetitive code is a
	   sure sign that there is a better way!
       Implement a better way by using function.		
	*/

	while (amount>=COIN1) {
		printf("%d", COIN1);
		amount -= COIN1;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	while (amount>=COIN2) {
		printf("%d", COIN2);
		amount -= COIN2;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	while (amount>=COIN3) {
		printf("%d", COIN3);
		amount -= COIN3;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	while (amount>=COIN4) {
		printf("%d", COIN4);
		amount -= COIN4;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	while (amount>=COIN5) {
		printf("%d", COIN5);
		amount -= COIN5;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	while (amount>=COIN6) {
		printf("%d", COIN6);
		amount -= COIN6;
		if (amount > 0 ) {
			printf(", ");
		}
	}

	printf("\n\n");
	return 0;
}


// round up "amount" to the nearest multiple of five
// and return that value  
int round_to_five(int amount){
	/* FIXME: fill in the needed code */

	fprintf(stderr, "round_to_five not yet implemented\n");
	return amount;
}
