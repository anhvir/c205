/*
   structs.c : examples to explain:
                  - how to define a new data type
                  - how to define and use a multi-component data type

   anhvir@gmail.com, for unimelb comp20005 workshop Week 7
   Notes:
     - the material is not yet covered in the lectures,
     - it is provided in a hope that you can apply in Assignment 1
       but you certainly don't have to: assigment 1 can be done
       without reading/understanding this meterial

*/


#include <stdio.h>
#include <stdlib.h>

/* DEFINING NEW DATATYPES ------------------------
   We know datatypes such as int, float, char, double.
   If we want, we can define a new datatype, by using "typedef" statement:
      typedef <description of new datatype> <name of new datatype> ;
   For example, if we want to have a datatype "integer", which is just
   equivalent to "int", we can use:
      typedef int interger;
   Note that we normally define new datatypes as global objects, so that
   we can use everywhere in our .c file.
   After defining, "integer" can be used, and is as a surrogate for "int".

   DEFINING A MULTI-COMPONENT DATATYPE

   WHY? Imagine that we need to process a number of student records,
   and each student record can include stdudent ID, name, ATAR score,
   starting year at uni, and many other components.
   Then, it would be much more covenient if we can pack all of the
   above components into one object, and hence when refer to student
   "a" we can have actually have each of these coponents.

   HOW? We will employ "typedef" of course.
   In this example, we will define a datatype callled "student_t" that
   have (for simplicity, only) 3 components: student ID, ATAR score,
   and year of joining the university.
*/   

#define N 10   
typedef int integer;    // now "integer" is defined

typedef /*START*/ struct {
   int id;        // student's id
   float atar;    // ATAR score
   int year;      // year to join uni
} /*END*/ student_t;

/* Note: in the 2nd "typedef", the part between START and END
         is the description of our new datatype. You can see that the
         "struct {" and "}" are the formal things we have to write,
         and the other things are just description of components.
         And "student_t" is the neme of our new datatype.
         We say that "student_t" is a "structure", or "struct" type. 
 
   Note 2: C gurus often use suffix "_t" to denote "type", that's
           why we employ "student_t"
      
*/   

int read_students( student_t ss[] ); 
student_t best_student( student_t ss[], int n);
                  
int main(int argc, char *argv[]) {
	integer n;      // declare "n" as an integer (or, just an "int")
    student_t s;    // s is of datatype "student_t", s is a struct variable
                    /* NOW, that means that we have 3 variables:
                        s.id    which is an int
                        s.atar  which is a float
                        s.year  which is an int
                    The dot operator "." is used to access a component 
                    of struct. */

    student_t students[N];
                    // "students" is an array of N elements,
                    //  each is a struct of 3 components

	n= read_students( students );
	s= best_student(students, n);  // note that we have to suply n here 
	printf("The best student: id= %d  ATAR= %.2f\n", s.id, s.atar);
	
	return 0;
}

/* reads a list of at most N student records, and store them in the
   array "s", returns number of students read    */ 
int read_students( student_t ss[] ){
	int i;
	for (i=0;
         i<N && scanf("%d %f %d", &ss[i].id, &ss[i].atar, &ss[i].year)==3;
         i++ ) {
		 /* note that the loop body is empty */
	}
	
	return i;
}

/* From the array ss[] of n students,
   return student with highest  ATAR score,
   if there are more than 1 students share the highest score,
      returns the first one (ie the one with lower index) */
student_t best_student(student_t ss[], int n) {
	student_t smax= ss[0];  // supposing that the first is the best!
	int i;
	for (i=1; i<n; i++) {   // now check other students
		if (ss[i].atar > smax.atar)   // if found a better
			smax= ss[i];              // then store that instaed
	}
	return smax;
}
/* note here that function can return a hole structure !  */


