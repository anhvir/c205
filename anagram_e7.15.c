/* 
	Skeleton for ex 7.15
   	Anh vo, anhvir@gmail.com, for unimelb COMP20005 Workshop Week 8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_LEN 80

int is_anagram(char*, char*);

/* TASK 1: Find all anagram pair from the set of strings in ss
   TASK 2 (chalenging): print only the maximal set of anagrams
           maximal= having highest number of strings,
                    on tie, prerernece is given to longer strings 
*/  

int main(int argc, char *argv[]) {
	// ss[] is an array of strings ie. ss[i] is a string,
	//   ie ss[i] is a sequence of chars, terminated with '\0'
	// NOTE: ss[] is NOT a 2D array of char!
	char *ss[MAX_N]= {   /* strings to test for anagramity */
		"luster",
		"cluster",
		"result",
		"revolt",
		"re sult",
		"ulster",
		"rustle",
		"programming is fun",
		"prof margin musing",
		"manuring from pigs"
		/* add some more strings to test */     

	};
	int n= 10;  /* number of strings in the above array */
	int i,j;
	/* Prints input strings */
	printf("*****Input strings:*****\n");
	for (i=0; i<n; i++) {
		printf("%s\n",ss[i]);
	}

	/* TASK 1: Find all anagram pair from the set of strings in ss */
	printf("\n******Anagram Pairs are:*******\n");
	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			if (is_anagram(ss[i],ss[j])) {
				printf("\"%s\" and \"%s\"\n", ss[i], ss[j]);
			}
		}
	}

	/* TASK 2 (chalenging): print only the maximal set of anagrams */

	return 0;
}

/* return true if a and b is an anagram pair, false otherwise
   note: the function will NOT change the input string a and b
*/ 
int is_anagram(char* a, char* b) {
	// IMPLEMENT ME!
	printf("is_anagram not yet implemented. Do It First!\n");
	return 0;
}
