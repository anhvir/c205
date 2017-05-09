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
#include <string.h>   /* for working with string, for example:
                         strlen(s) will return the number of character in the string s
                         strcpy(s1, s2) will copy s2 to s1 
                      */

#define NAME_LEN_MAX 40

#define N_MAX 1000



typedef struct {
  	char given[NAME_LEN_MAX + 1];
	char family[NAME_LEN_MAX + 1];
} fullName_t;
/* example: if we declare:
 
  fullName_t myname;
  fullName_t *pn= &myname;
 
  then "myname" is a compound variable with two components:
    myname.given    which is a string of 40 characters maximal
    myname.family   which is a string of 40 characters maximal
  and I can, for example, write statements like:
    strcpy(myname.given, "Anh");
    strcpy(myname.family, "Vo");
  or
    scanf("%s %s", myname.given, myname.family);      note: & is not used because myname.given
                                                      is a string, and hence is a kind of address already
  Now consider pn, it a pointer, and it points to myname.
  So there are at least three equivalent ways to refer to m,y given name:
    myname.given
    (*pn).given             that is by definition of pointer, but looks ugly!
    pn->given               this is a beautiful shorthand of the above 
                            remember to use that kind of syntax when you have pointer to structures
 */
 




typedef struct {
	fullName_t name;
	int id;				     /* staff number */
	int salary;        /* annual salary (AUD)  */
} staff_t;
/* staff_t is a data type; each staff_t variable (say named st) has 4 components:
    st.name              which is struct of type fullName_t
		st.name.given      which is a string, representing gibven name
		st.name.family     which is a string, representing family name
	st.id                int number, representing staff ID
    st.salary            int number, representing salary
*/


/* datatype for a list of staff ----------------- */
typedef struct {
	int n;              /* number of staffs */
	staff_t ss[N_MAX];  /* array of staff   */
} staffList_t;

/* staffList_t object is a struct that has a array as a component,
   that array, in its turn, is an array of structs
*/

void createStaffList( staffList_t *psl );
void printStaffList( staffList_t *psl, char *title );
void sortStaffList( staffList_t *psl);

int
main(int argc, char *argv[]) {
	staffList_t myStaff;

	/* 1 ---------- creates the staff list myStaff */ 
	createStaffList( &myStaff );
	
	/* 2 ---------- print the staff list myStaff   */
	printStaffList( &myStaff, "ORIGINAL STAFF LIST" );
 
	/* 3 ---------- sorts the staff list           */ 
	sortStaffList( &myStaff );

	/* 4 ---------- print the staff list again, after sorting   */
	printStaffList( &myStaff, "ID-SORTED STAFF LIST" );

	return 0; 
}


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
	fullName_t *pn= &ps->name;   /* using pn as a surrogate for a pointer to ps->name */  
	
	printf("%-10s %-10s %04d  %6d\n",
					pn->given, pn->family, ps->id, ps->salary );
								/* so ps->given is equivalent to (pn->name)->given */
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

