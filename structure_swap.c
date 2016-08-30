#include <stdio.h>   github.com/anhvir/c205/structure_swap.c
#include <stdlib.h>

struct student {      
	char name [30];
	int age;
	char position[50];
	int score;
};
/* "struct student" is a compounded datatype,
  called "structure". It has 2 elements, identified as
  "name" (which is a string of 29 chars max) , and
  "age", which is an int                */

/*
typedef struct student student_t;
*/
/* here we defined a datatype "student_t"
   which is EQUIVALENT to "struct student"   */


void st_swap(struct student *p1, struct student *p2);


int main( int argc, char *argv[] ) {
	struct student s1= {"Putin", 19, "PM", 70},
			  s2= {"Obama", 20, "President", 75};
    /* think about s1 and s2 as 2 objects, 
   		each has a name and an age
	*/
 
	printf ("Student 1: name= %s,  age= %d\n",
		    s1.name, s1.age);
	/* s1.name refers to the component "name" of object s1
   		"s1.name" is a (string) variable by itself!
   		similarly, s1.age is a variable (of type "int" )
	*/
 
	printf ("Student 2: name= %s,  age= %d\n\n",
		    s2.name, s2.age); 
	
	st_swap( &s1, &s2 );

	printf("\nAfter swapping: \n");
	printf ("Student 1: name= %s,  age= %d\n",
		    s1.name, s1.age);
 
	printf ("Student 2: name= %s,  age= %d\n\n",
		    s2.name, s2.age); 

	
	return 0;
}	

void st_swap(struct student *p1, struct student *p2) {
	struct student tmp= *p1;
	*p1= *p2;
	*p2= tmp;
}

