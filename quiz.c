/* quiz used in Week 4 
   by anhvir@gmail.com for unimelb comp20005 Workshop Week 4
   
   note: not yet a great program, need some sort of auto-generating...
*/
   

#include <stdio.h>

void wait4enter();

int main() {
	int i, j, c, s;
	
	printf("NOTES: For each quiz, the question will be displayed first.\n"
		   "       You should try to work out the answer before "
			"pressing <Enter>\n Press <Enter> to continue..."); 
	while (getchar() != '\n');
	
	printf("\nQUIZ 2: What are the values of i, s, and c after the"
		" following statement: \n"
"	for (s=0, i=0, c= 0; i<5; i++) { \n"
"		s += i; \n"
"		c++; \n"
"	} \n" );

	printf("\n Answer to QUIZ 2:\n");	
	wait4enter();

	for (s=0, i=0, c= 0; i<5; i++) {
		s += i;
		c++;
	}
	printf("s=%d, i= %d, c= %d\n\n", s, i, c);

	printf("\n\n QUIZ 3: what's the output of:\n"
"	for (i=0; i<2; i++) { \n"
"		for (j=0; j<3; j++) { \n"
"			printf(\"%%d \", i*j); \n"
"		} \n"
"		printf(\"\\n\"); \n"
"	}\n");

	printf("\n QUIZ 3 output:\n");
	wait4enter();
	for (i=0; i<2; i++) { 
		for (j=0; j<3; j++) {
			printf("%d ", i*j);
		}
		printf("\n");
	}
		
	printf("\n QUIZ 4: what's the output of:\n"
"	for (i=0; i<5; i++) { \n"
"		for (j=0; j<4; j++) { \n"
"			if ( j >i ) continue; \n"
"			printf(\"%%d \", i*j); \n"
"		} \n"
"		printf(\"\\n\");  \n"
"		if (i==2) break; \n"
"	} \n" );
	
	printf("\n QUIZ 4 output:\n");
	wait4enter();
	for (i=0; i<5; i++) { 
		for (j=0; j<4; j++) {
			if ( j >i ) continue;
			printf("%d ", i*j);
		}
		printf("\n");
		if (i==2) break; 
	}
	return 0;
}


void wait4enter() {
	printf("                       press Enter to see solution ...");
	while (getchar() != '\n');
}
