#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100

int read_poly(double X[], double Y[]); 
void print_poly(double X[], double Y[], int n); 
double length(double x1, double y1, double x2, double y2);
double peri(double X[], double Y[], int n); 
 

int main(int argc, char *argv[]) {
	double X[MAX_N], Y[MAX_N];
	int n;

	n= read_poly(X,Y);
	print_poly(X, Y, n);
	printf("\nPerimeter= %.2lf\n", peri(X, Y, n));

	return 0;
}  

int read_poly(double X[], double Y[]) {
	int i;
	for (i=0; i<MAX_N && scanf("%lf %lf", &X[i], &Y[i])==2 ; i++);
	return i;
}


void print_poly(double X[], double Y[], int n) { 
	int i;
	printf ("Polygon has %d vertices:\n", n);  
	for (i=0; i<n; i++) {
		printf("( %.1lf, %.1lf )\n", X[i], Y[i] );
	}
}

// return length of segment (x1,y1) - (x2,y2)
double length(double x1, double y1, double x2, double y2) {
	double dx= x2-x1;
	double dy= y2-y1;
	return sqrt( dx*dx + dy*dy );
}

// return perimeter of polygon
double peri(double X[], double Y[], int n) {
	int i;
	double s=0;
	for (i=0; i<n; i++) {
		s += length(X[i], Y[i], X[(i+1)%n], Y[(i+1)%n]);
	}
	return s;
}
 

