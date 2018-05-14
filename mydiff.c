/*  mydiff.c
	by Anh Vo, anhvir@gmail.com, for COMP20005 assignment 2 2018
	last updated: 13/05/2018 
	Purpose:
		List the differences between 2 ass2-output files
	Notes:
		The proram does not consider extra lines at the end of the longer file 

	DISCLAIMERS:
		This program might contain errors, no guarantee of any kind is implied.
		Use it at your own risk.
		Anh Vo will not bear any responsibility for any possible outcome
		resulting from the use of this program.
		
		If you have suggestions please send to anhvir@gmail.com. Thanks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 500       // max lines per file
#define MAX_LINE_LEN 100
#define TRUE 1
#define FALSE 0

typedef struct {							// a solution: 
	int n;									//  - total non-blank lines
	int blanks;	 							//  - total blankslines, excluding: 
	int pre_blanks;							//      - blanklines at beginning
	char lines [MAX_LINES] [MAX_LINE_LEN];	//  - the non-blank lines
} soln_t;

void read_soln(soln_t *soln, char *fname);

int main(int argc, char *argv[]) {
	soln_t am, me;			// Solutions of Alistair Moffat and Me :-)
	int bad=0;				// Number of bad lines
	int i, n, ib;
	int fault[MAX_LINES];	//  TRUE if the lines are not identical in 2 files
	
	// 1. Reads input solutions
	if (argc != 3){
		fprintf(stderr,"Usage  : %s my_filename sample_filename\n"
			           "Example: %s my_test0-120.txt test0-120-out.txt\n",
			argv[0], argv[0]);
		exit(EXIT_FAILURE);
	}
	read_soln(&me, argv[1]);	// get my solution
	read_soln(&am, argv[2]);	// get Alistair's solution

 	// 2. Compares all non-blank lines
	for (n=0; n<am.n && n<me.n; n++) {
		if ( strcmp(am.lines[n], me.lines[n]) ) {
			bad++;
			fault[n]= TRUE;
		} else
			fault[n]= FALSE;
	}
	
	// 3. Outputs different non-blank lines, one by one
	for (i=ib=0; ib<bad && i<am.n && i<me.n; i++) {
		if (fault[i]) 
			printf("< %s\n> %s\n\n",me.lines[i], am.lines[i]); 
    }

	// 4. Outputs summary
    if (am.n==me.n && !bad 
		    && am.pre_blanks==me.pre_blanks &&  am.blanks == me.blanks) {
		printf("Everythings seem Ok\nI am genious!\n\n"); 
		return 0;
	}

	printf("Warnings: something wrong in my work\n");
	if (me.n < am.n) { 
		printf("   - SEVERE: mine has %d fewer non-blank lines than expected\n",
				 am.n-me.n);
		printf("   NOTE: this mydiff command DOES NOT list missing lines\n"
			   "         perhaps use the standard diff command to see them\n");	
	} else if (me.n > am.n) 
		printf("   - SEVERE: mine has %d more non-blank lines than expected\n",
				 me.n-am.n );
	if (bad) 
		printf("   - SEVERE: %d of my non-blank lines are incorrect\n", bad);
	if (me.pre_blanks != am.pre_blanks) 
		printf("   - I have %d blanklines at the beginning but expected %d\n", 
				 me.pre_blanks, am.pre_blanks);
	if (me.blanks != am.blanks) 
		printf("   - I have %d blanklines in total but expected %d\n", 
				 me.blanks+me.pre_blanks, am.blanks+am.pre_blanks);

	printf("\n");
	return 0;
} 

/*----------------------- functions for reading data ------------------------*/

//      chops off all the tailing invisible chars
void chop(char *s) {
	char *p= s + strlen(s) - 1;
	while (p>=s && isspace(*p)) *p-- = '\0';
}
	 
// read whole soln or student outputs for all tests into s
void read_soln(soln_t *soln, char *fname) {
	int inbody= FALSE;
	FILE *f;
	char line[MAX_LINE_LEN];		
	
	if ( !(f=fopen(fname,"r")) ) {
		fprintf(stderr, "Wrong file name %s\n", fname);
		exit(EXIT_FAILURE);
	}

	soln->n= soln->blanks= soln->pre_blanks= 0;
	while ( fgets(line, MAX_LINE_LEN, f) ) {
		chop(line);
		if (!*line) 
			if (inbody) 
				soln->blanks++;
			else
				soln->pre_blanks++;
		else {
			strcpy(soln->lines[soln->n++], line);
			inbody= TRUE;
		}
	}
	fclose(f);
}	

/*------------------------- Progamming is fun! ------------------------------*/		
