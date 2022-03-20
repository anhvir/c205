/* quiz used in Week 4 
   by avo@unimelb.edu.au, for unimelb comp20005 Workshop Week 4
   
   note: not yet a great program,
		 we can probably improve it later when having time!  
*/
   

#include <stdio.h>


int main(int argc, char *argv[]) {
	int i, j, c, s;

	// ------------- PROCESSING 1 QUIZ -----------------
	// First, display the question 	
	printf("\nQUIZ 2: What are the values of i, s, and c after the"
		" following statement: \n"
"	for (s=0, i=0, c= 0; i<5; i++) { \n"
"		s += i; \n"
"		c++; \n"
"	} \n" );

	// Then, wait for users answering and pressing Enter
	printf("\n Write your answer in draft paper, then\n");	
	printf("              press Enter to see the correct answer ...");
	while (getchar() != '\n');

	// Run the code to display the correct answer
	for (s=0, i=0, c= 0; i<5; i++) {
		s += i;
		c++;
	}
	printf("s=%d, i= %d, c= %d\n", s, i, c);
	printf("\nHope you got it right!\n");
	printf("              press Enter to see the correct answer ...");
	while (getchar() != '\n');
	printf("\n");


	//---- The rest is just similar to the above ------------
	printf("\n\n QUIZ 3: what's the output of:\n"
"	for (i=0; i<2; i++) { \n"
"		for (j=0; j<3; j++) { \n"
"			printf(\"%%d \", i*j); \n"
"		} \n"
"		printf(\"\\n\"); \n"
"	}\n");

	printf("\n Write your answer in draft paper, then\n");	
	printf("                 press Enter to see answer ...");
	while (getchar() != '\n');
	for (i=0; i<2; i++) { 
		for (j=0; j<3; j++) {
			printf("%d ", i*j);
		}
		printf("\n");
	}
	printf("\nHope you got it right!\n");
	printf("              press Enter to see the correct answer ...");
	while (getchar() != '\n');
	printf("\n");
		
	// -------------------------------------------  
	printf("\n QUIZ 4: what's the output of:\n"
"	for (i=0; i<5; i++) { \n"
"		for (j=0; j<4; j++) { \n"
"			if ( j >i ) continue; \n"
"			printf(\"%%d \", i*j); \n"
"		} \n"
"		printf(\"\\n\");  \n"
"		if (i==2) break; \n"
"	} \n" );
	
	printf("\n Write your answer in draft paper, then\n");	
	printf("                 press Enter to see answer ...");
	while (getchar() != '\n');
	
	for (i=0; i<5; i++) { 
		for (j=0; j<4; j++) {
			if ( j >i ) continue;
			printf("%d ", i*j);
		}
		printf("\n");
		if (i==2) break; 
	}
	printf("\nHope you got it right!\n");
	printf("              press Enter to see the correct answer ...");
	while (getchar() != '\n');
	printf("\n");

	printf("\nTHE END\n\n");
	return 0;
}


