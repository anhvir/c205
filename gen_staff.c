/* Author: Anh Vo
	Date:  06/10/2015
		- generating list of N staff recodrs of the form
		firstname familyname employeenumber dateofcommncement status salary
		- for generating N staffs  and writing into file "filename", use:
		  staff_gen N  > filename
	
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define NAME_LEN_MAX 40
#define STAFF_ID_MIN 100
#define STAFF_ID_MAX 9999
#define SALARY_MIN 50000
#define SALARY_MAX 200000

#define N 30

typedef char name_t[NAME_LEN_MAX];

typedef struct {
	name_t given, family;
} fullName_t;


typedef struct {
	int dd, mm, yy;
} date_t;

typedef struct {
	fullName_t name;
	int id;				     /* staff number */
	date_t start;      /* date of commencement */
	int salary;        /* annual salary (AUD)  */
} staff_t;

void getFullName(fullName_t *pn); 
void getDate(date_t *pd);
void getStaff(staff_t *ps);
void printStaff(staff_t *ps);

int main(int argc, char *argv[]) {
  int n= N, i;
	staff_t s;

	if (argc==2) n= atoi( argv[1] );
	srand(time(NULL));               /* reset (seed) the random generator */
  
  for (i=0; i<n; i++) {
		getStaff(&s);
		printStaff(&s);
  }
  
  return 0;
}

/* generating a random full names into *pn,
   using a list of 20 most popular given names,
	 and   a list of 10 most popular family names.
	 the lists are copied from Internet [google it!]
*/
void getFullName(fullName_t *pn) {
	char gNames[30][NAME_LEN_MAX+1]= {	
		"Jack",	"William",	"Noah",	"Ethan",	"Oliver", 
		"Thomas",	"Cooper",	"James",	"Lucas",	"Lachlan",
		"Olivia",	"Charlotte",	"Mia",	"Ava",	"Chloe",
		"Amelia",	"Sophie",	"Emily",	"Ruby",	"Ella"
	};
	char fNames[10][NAME_LEN_MAX+1]= {
		"Smith",	"Jones",	"Williams",	"Brown",	"Wilson",
		"Taylor", "Morton", "White",	"Martin", "Anderson"
	};
	strcpy(pn->given, gNames[rand()%20]);
	strcpy(pn->family, fNames[rand()%10]);
}

void getDate(date_t *pd) {
  pd->dd= rand()%28+1;
  pd->mm= rand()%12+1;
  pd->yy= 1970 + rand()%25;  /* 1970-1994 */
}


void getStaff(staff_t *ps) {
	getFullName(&ps->name);
  ps->id = STAFF_ID_MIN + rand() % (STAFF_ID_MAX - STAFF_ID_MIN + 1);
	/* Note: staff ID should be unique,
				   but here we ignore this requirement!!! 
	*/
	getDate(&ps->start);
	ps->salary = SALARY_MIN + rand() % (SALARY_MAX - SALARY_MIN +1); 
}

void printStaff(staff_t *ps) {
	fullName_t *pn= &ps->name;
	date_t *pd= &ps->start;
	
	printf("%-10s %-10s %04d %02d/%02d/%02d %6d\n",
					pn->given, pn->family, ps->id,
					pd->dd, pd->mm, pd->yy % 100, ps->salary );
}


