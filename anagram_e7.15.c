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

	/* TASK 1: Find all anagram pair from the set of strings in ss */


	/* TASK 2 (chalenging): print only the maximal set of anagrams */

	return 0;
}

/* return true if a and b is an anagram pair, false otherwise
   note: the function will NOT change the input string a and b
*/ 
int is_anagram(char* a, char* b) {

	return 0;
}
