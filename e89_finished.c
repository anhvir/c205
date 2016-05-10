/*  Author: COMP20005 Class
		Date: 09/05/2016
    Demonstrating:
   		Nested structures & array of struct.
			Sorting.
		Based on Exercise 8.9
		Supposing that input data in the format:
		   givenname firstname staffID dd/mm/yy salary

*/

#include <stdio.h>
#include <string.h>   /* for working with string, for example:
                         strlen(s) will return the number of character in the string s
                         strcpy(s1, s2) will copy s2 to s1 
                      */

#define NAME_LEN_MAX 40

#define N_MAX 100



typedef struct {
    char given[NAME_LEN_MAX];
	char family[NAME_LEN_MAX];
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
	int dd, mm, yy;
} date_t;

typedef struct {
	fullName_t name;
	int id;				     /* staff number */
	date_t start;      /* date of commencement */
	int salary;        /* annual salary (AUD)  */
} staff_t;
/* staff_t is a data type; each staff_t variable (say named st) has 4 components:
    st.name              which is struct of type fullName_t
		  st.name.given      which is a string, representing gibven name
		  st.name.family     which is a string, representing family name
		st.id                int number, representing staff ID
    st.start             which is a struct of type date_t 
      st.start.dd        int number, representing day
      st.start.mm        int number, representing month
      st.start.yy        int number, representing year
    st.salary            int number, representing salary
*/


/* datatype for a list of staff ----------------- */
typedef struct {
	int n;              			/* number of staffs */
	staff_t ss[N_MAX];        /* array of staff   */
} staffList_t;


void printStaff(staff_t *ps); 
void createStaffList( staffList_t *psl );
void printStaffList( staffList_t *psl, char *title );
void sortStaffList( staffList_t *psl);
void swap(staff_t *a, staff_t *b); 

int
main(int argc, char *argv[]) {
 	staffList_t myStaff;

  /* 1 ---------- creates the staff list myStaff */ 
	createStaffList( &myStaff );
	
	/* 2 ---------- print the staff list myStaff   */
	printStaffList( &myStaff, "ORIGINAL STAFF LIST" );
 
  /* 3 ---------- sorts the staff list           */ 
	sortStaffList( &myStaff );

	/* 2 ---------- print the staff list again, after sorting   */
	printStaffList( &myStaff, "ID-SORTED STAFF LIST" );

	return 0; 
}


/* print one staff, which is pointed to by ps */ 
void printStaff(staff_t *ps) {
	fullName_t *pn= &ps->name;   /* see createStaffList for more comments */  
	date_t *pd= &ps->start;
	
	printf("%-10s %-10s %04d   %02d/%02d/%02d    %6d\n",
					pn->given, pn->family, ps->id,
					pd->dd, pd->mm, pd->yy % 100, ps->salary );
}

/* create a staff list by reading from stdin */
void createStaffList( staffList_t *psl ) {
	int i;
  for (i=0; i<N_MAX; i++) {
		staff_t *ps= &psl->ss[i];    /* ps, pn, pd are used here */
		fullName_t *pn= &ps->name;   /*    for covenience !      */
		date_t *pd= &ps->start;
		if ( scanf("%s %s %d %d/%d/%d %d", 
		           given, family, &id, 
							 &dd, &mm, &yy, &salary) != 7) {
			break;
			        /* note that if we haven't use pd (for example) we have
							   to write &psl->ss[i].start.mm
								 instead of              pd->mm  
							*/
		}
	}
	psl->n= i;
}

void printStaffList( staffList_t *psl, char *title ) {
	int i;
	/* first, print the title and the header lines   ---------------------  */
	printf("      %s\n", title);
	printf("The list currently has %d staff\n\n", psl->n);
	printf("Given & Family Names   ID  DateCommenced Salary\n");
	printf("--------------------  ---- ------------- ------\n");
	/* then, wlks thru the array psl->ss[] and print staff by staff ------  */
  for (i=0; i<psl->n; i++ ) {
		printStaff( &psl->ss[i] );
	}
	printf("\n");
}

/* swap two staff  */
void swap(staff_t *a, staff_t *b) {
	staff_t tmp= *a;
	*a= *b;
	*b= tmp;
}

/* sort the array psl->ss[] in increasing order of id,
   using selection sort 
*/
void sortStaffList( staffList_t *psl) {
	int n= psl->n;         /* for convenience, n= number of staff */
}

