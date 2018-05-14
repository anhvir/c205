/* Program for assignment1 COMP20005, Sem 1 2018
   Purpose: Analysing data about daily number of pedestrians
            at a train station in Melbourne
            to find its trend over time  
            Refer to the accompanied specs ass1.pdf for more details.
   Author: Anh Vo, anhvir@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DAYS 10000       // max number of data lines for the station
#define NGRPS 3              // number of  time groups
#define HEAD_LINES 2         // number of header lines in data file

typedef struct {             // datatype for 1 data record, incl:
	int yyyy, mm, dd;        //   - date 
	int day;                 //   - day in week (1 for sun, ..., 7 for sat
	int dcount;              //   - number of pedestrians on the date
} pcount_t;                 


int read_data(pcount_t pcs[]);
void stage_1(pcount_t pcs[], int n); 
void stage_2(pcount_t pcs[], int n); 
void stage_3(pcount_t pcs[], int n); 
void stage_4(pcount_t pcs[], int n); 

int main(int argc, char *argv[]) {
	pcount_t pcs[MAX_DAYS];   // array of all input data records
	int n;                    // number of data records
	n= read_data(pcs);
	stage_1(pcs, n);
	stage_2(pcs, n);
	stage_3(pcs, n);
	stage_4(pcs, n);

	return 0;
}

/* --------------- Stage 1 functions --------------------------------------- */

//  reads data records into array pcs[] and
//    returns the number of records 

int read_data(pcount_t pcs[]){
	int i;
	for (i=0; i<HEAD_LINES; i++)
		while( getchar()!= '\n'); 
	for (i=0; 
		 i<MAX_DAYS &&
		 scanf("%d%d%d%d%d",&pcs[i].yyyy, &pcs[i].mm, &pcs[i].dd,
		 		&pcs[i].day, &pcs[i].dcount)==5;
		 i++);
	return i;	
}


//  do stage1, ie printing the first and last records 

void stage_1(pcount_t pcs[], int n) {
	printf("\n");
	printf("S1: total data lines = %d days\n", n);
	printf("S1: first data line  = %02d/%02d/%4d, %d people counted\n",
            pcs[0].dd, pcs[0].mm, pcs[0].yyyy, pcs[0].dcount);
	printf("S1: last data line   = %02d/%02d/%4d, %d people counted\n",
            pcs[n-1].dd, pcs[n-1].mm, pcs[n-1].yyyy, pcs[n-1].dcount);
}


/* --------------- Stage 2 functions --------------------------------------- */
#define ZERO_YEAR 1989       // all data are supposed to be AFTER this year
#define BASE_FEB_LEN 28      // length of "normal" Feb
#define LONG 31              // length of a long month
#define SHORT 30             // length of a short month (exc. Feb)

//  returns TRUE if "year" is a leap year, false otherwise
//  Note: content based on prog 4.2 page 47 of Alistair's textbook

int is_leap_year(int year) {
	return (year % 4 == 0) && (year % 100 || year % 400==0);
}


//  returns number of days in month "month" of year "year"
//       "month" is integer from 1 (Jan) to 12 (Dec)
//  Note: content based on prog 4.2 page 47 of Alistair's textbook

int month_len(int month, int year) {
	if (month==4 || month==6 || month==9 || month==11)
		return SHORT;
	else if (month==2)
		return BASE_FEB_LEN + is_leap_year(year);
	else return LONG;
}


//  returns number of days in year "year"

int year_len(int year) {
	return 365 + is_leap_year(year);
}


//   returns number of days passed
//     since the first day of ZERO year to dd/mm/yyyy

int day_pos(int dd, int mm, int yyyy) {
	int pos= 0, m;
	int i;
	// 1. counts the days of years before yyyy
	for (i=ZERO_YEAR; i<yyyy; i++) pos += year_len(i);
	// 2. counts the day in yyyy that before month mm
	for (m=1; m<mm; m++) pos += month_len(m, yyyy);
	// 3. add the day in month mm of yyyy
	pos += dd;
	return pos;
}


//  returns number of days passed, inclusively, 
//    from the date in data record "d1" to the date in "d2"

int day_diff(pcount_t d1, pcount_t d2) {
	return day_pos(d2.dd,d2.mm,d2.yyyy) - day_pos(d1.dd, d1.mm, d1.yyyy) +1;
}
  
//  does stage 2, ie prints out the coverage ratio 

void stage_2(pcount_t pcs[], int n) {
	int range= day_diff(pcs[0], pcs[n-1]);
	float ratio= 100.0*n/range;
	printf("\n");
	printf("S2: range spanned    = %d days\n", range);
	printf("S2: coverage ratio   = %4.1f%%\n", ratio);  
}


/* -------------  Stage 3 functions ---------------------------------------- */ 

//  prints a line for stage 3 ouput
//     - for month "mm" year "yyyy", which as "days" records and
//       "mcount" pedestrians in total
void print_line(int mm, int yyyy, int days, int mcount) {
	printf("S3: %02d/%4d %2d/%2d days covered, "
           "average count = %5.1fk\n",
			mm,yyyy,days,month_len(mm,yyyy), mcount/1000.0/days); 
}


//  does stage 3, ie prints monthly statistics

void stage_3(pcount_t pcs[], int n) {
	int mm=pcs[0].mm, yyyy= pcs[0].yyyy, mcount=0, days=0, i;
	// (mm, yyyyy) represents the ID of the current group for statistics
	// days and mcount are number of days and total dcount of (mm,yyyy)
	
	printf("\n");
	for (i=0; i<n; i++) {
		if ( mm==pcs[i].mm && yyyy==pcs[i].yyyy ) {   // same group 
			mcount += pcs[i].dcount; 
			days++;
		} else {
			print_line(mm, yyyy, days, mcount);
			mm= pcs[i].mm;      // sets new group   
			yyyy= pcs[i].yyyy;
			mcount= pcs[i].dcount; 
			days= 1;
		}
	}
	print_line(mm, yyyy, days, mcount);  // last group not yet printed 
	                                      //     inside the loop

}


/* -------------------- Stage 4 functions ---------------------------------- */		

#define DIW 7           // number of days per week

typedef enum {          // for the name of day in week
	                    // sun=1 to comply with the data
	sun=1, mon, tue, wed, thu, fri, sat
} dow_t;

typedef struct {       // information for 1 group, needed for stage 4:
	int days;          //   - total days covered in the groups
	int count;         //   - total dcount of the group
} gdata_t;


//  prints summary data for each group
//    start[i] is start point of group i in data array pcs[]
 
void print_sum(pcount_t pcs[], int start[]) {
	int g=0;                      // group id

	printf("\n");	 	
	for ( ; g<NGRPS ; g++) {
		pcount_t *p1= pcs + start[g];         // first data of group g
		pcount_t *p2= pcs + start[g+1] - 1;   // last data of group g
		printf("S4: group %d data, %02d/%02d/%4d to"
				" %02d/%02d/%4d, %d data records\n", g,
				p1->dd, p1->mm, p1->yyyy, 
				p2->dd, p2->mm, p2->yyyy, start[g+1]-start[g]);
	}	
}


//  prints a bar of round(x) characters '*', then a newline
//
void print_bar(double x) {
	int n= (int) (x+0.5) ;
	int i;
	for (i=0; i<n;i++) printf("*");
	printf("\n");
}


//  prints weekday details for all groups
 
void print_details(gdata_t s[][NGRPS]) {
	// define an array for weekday names, where Sun has index 1
	char *days[]={"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	int d;       // day id
	int g;       // group id
	for (d=sun; d<=sat; d++) {
		printf("\n");
		for (g=0; g<NGRPS; g++) {
			double ratio= s[d][g].count/1000.0/s[d][g].days;
			printf("S4: %s, g%d = %4.1fk |", days[d], g, ratio);
			print_bar(ratio);
		}
	}
}


//   does stage 4
//     - data pcs[] is divided into NGRPS equal-size groups
//     - print group statics for each day of week
 
void stage_4(pcount_t pcs[], int n){
	int start[NGRPS+1];  // start index of each group in array pcs[] 
						 //    note that the last elem is sentinel, value n 	
	gdata_t s[DIW+1][NGRPS]= {{{0,0}}};  // summary data per weekday
                                         //   and per group
	int g;                               // group ID
	int i;

	// 1. buiding start[ ]
	for (g=0; g<NGRPS; g++) start[g]= n*g/NGRPS;
	start[NGRPS]= n;                     // sentinel

	// 2. print group summary
	print_sum(pcs, start);

	// 3. collects into s[][] group details by group, then by weekday
	g=0;	    					     // starts from group 0
	for (i=0; i<n; i++) {
		int d= pcs[i].day;               // sets day id
		if (i >= start[g+1] ) g++;       // change group ID accordingly 
		s[d][g].days++;		
		s[d][g].count += pcs[i].dcount;
	}
	
	// 4. print group, day statistics
	print_details(s);		
}

/* --------------------------------- THE END --------------------------------*/
/*                             Programming is fun                            */