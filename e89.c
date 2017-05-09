/*  Author: COMP20005 Class
		Date: May 2017

	SORRY, this one is not a finished version as it name suggests
			I just add some more comments in comparison with e89.c
			you need to finish it by yourself

	Demonstrating:
	A) nested strucs and arrays, in particular:
		- array of structs
   		- struct with arrays as components
   		- struct with structs as components
    B) Sorting arrays of structs
		
	NOTES: Based on Exercise 8.9, with a bit of change:
	A) Supposing that input data dexribing statt in the format:
		givenname surname staffID salary
		(attention: only one single word for givenname,
					one single word for surname
					date of birth (required by e8.9) was skipped) )
	B) Struct with arrays as componenst is implemented here,
		but is not actually required for Ex 8.9 

	QUESTIONS? You can send question about this progrm to:
		anhvir@gmail.com

		with subject: COMP20005 question.
		

*/

#include <stdio.h>
#include <string.h>

#define NAME_LEN_MAX 40

#define N_MAX 1000



typedef struct {
  	char given[NAME_LEN_MAX + 1];
	char family[NAME_LEN_MAX + 1];
} fullName_t;

typedef struct {
	fullName_t name;
	int id;			/* staff number */
	int salary;     /* annual salary (AUD)  */
} staff_t;


/* datatype for a list of staff ----------------- */
typedef struct {
	int n;              /* number of staffs */
	staff_t ss[N_MAX];  /* array of staff   */
} staffList_t;


int
main(int argc, char *argv[]) {
	staffList_t myStaff;

	/* 1 ---------- creates the staff list myStaff  */
	
    /* 2 ---------- print the staff list myStaff    */  
 
    /* 3 ---------- sorts the staff list            */

	/*4 ---------- print the staff list again, after sorting   */

	return 0; 
}

















void createStaffList( staffList_t *psl );
void printStaffList( staffList_t *psl, char *title );
void sortStaffList( staffList_t *psl);

/***********************  PART 1: INPUT STAFF LIST ************************/

/* create a staff list by reading from stdin */
void createStaffList( staffList_t *psl ) {
	int i;
	for (i=0; 
		i<N_MAX && 1 /* Replace 1 by your scanf  */ ;
		i++) {               /* empty loop body, can be just replaced with ; */
	}
}


/***********************  PART 2: PRINT STAFF LIST ************************/

/* print one staff, which is pointed to by ps */ 
void printStaff(staff_t *ps) {
}

/* print the whole staff list (after printing a title) */ 
void printStaffList( staffList_t *psl, char *title ) {
	int i;
	/* first, print the title and the header lines   ---------------------  */
	printf("      %s\n", title);
	printf("The list currently has %d staff\n\n", psl->n);
	printf("Given & Family Names   ID   Salary\n");
	printf("--------------------  ----  ------\n");
	/* then, wlks thru the array psl->ss[] and print staff by staff ------  */
	printf("printing NOT YET implemented \n");
    
	printf("\n");
}


/***********************  PART 4: SORTING ************************/

void swap(staff_t *a, staff_t *b) {
	printf("swap NOT YET implemented \n");
}

/* sort the array psl->ss[] in increasing order of id,
   using insertion sort 
*/
void sortStaffList( staffList_t *psl) {
	printf("sorting NOT YET implemented \n");
}

