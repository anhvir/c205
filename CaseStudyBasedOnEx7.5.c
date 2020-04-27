/* Ex 7.5
Suppose that a set of "student number, mark" pairs are provided,
one pair of numbers per line, with the lines in no particular order.
Write a program that reads this data and outputs the same data, 
but ordered by student number. For example:
  stud   mark
823678  66
765876  94
864876  48
785671  68
854565  89
On this input your program should output:

Enter as many as 1000 "studnum mark" pairs, ^D to end
5 pairs read into arrays
studnum  mark
765876  94
785671  68
823678  66
854565  89
864876  48

------------------------
In this Case Study:
  + using typedef
  + using struct
  + recall: using selection sort
  + recall: usng redirection
------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000


typedef struct {
	int stud;
	int mark;
} mark_t;
int read_mark(mark_t A[]);
void print_mark(mark_t A[], int n);


int main(int argc, char *argv[]) {
	mark_t A[SIZE];
	int n= 0;
 	n= read_mark(A);
 	print_mark(A,n);  	
	
	return 0;
}

int read_mark(mark_t A[]) {
	int i;
	int stud, mark;
	for (i=0; i<SIZE && scanf("%d %d", &stud, &mark)==2;  i++ ) {
		A[i].stud = stud; 
		A[i].mark = mark;
	}
	return i;
}

void print_mark(mark_t A[], int n) {
	int i;
	for (i=0; i<n; i++) {
		printf("%7d %7d\n", A[i].stud, A[i].mark);
	}
}


	