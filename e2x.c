/*
  e2x.c : Write and test a function that
          computes S= 1 + x + x^2/2! + x^3/3! + ... x^n/n!
          where n>0 and is the largest one that satisfies:
                    | x^n/n! | >= 10^(-6)
          You should not use any functions from math library.
          Note that n is NOT an input to this task.
  
  Note : The above requirement just means:
         compute e^x with the precision of EPSILON= 1e-6,
         
  
  Anh Vo, avo@unimelb.edu.au, for comp20005 unimelb Workshop Week 4
  TOPIC: learn to use the while loop
  What's new: answering the questions posted in the previous version

*/

/* DESIGN THOUGHTS for computing the sum
We need to compute S= 1 + x + x^2/2! + x^3/3! + ...
That is:
         S= p_0 + p_1 + p_2 + p_3 + ... + p_i + ...   
     where   p_0= 1
             p_1= x
             p_2= x^2/2!
             p_3= x^3/3!
             ...
             p_i= x^i/i!           
             ...

 
First idea:
    
   - start with S=0, i= 0, compute p= p_0
     Now we can add p to S, but prior to that we need
        to check that |p| >= EPSILON
        and we know that that should be a start of a loop
   - Organize the loop:
     The body of the loop should include
        + accumulate p to S
        + change i to next i by i=i+1, 
          now p became p_(i-1) becaused of changed i
        + change p so that it become new p_i
          and here is the end of loop body, 
          because now we want to continue from "accumulate p to S"


We refine and detail our above thought as follows:
   i= 0;
   p= 1;    // p= p_0= p_i

   while (???) {  // loop starts, ??? ==  true when |p| >= EPSILON
      S= S + p;   // accumulate p (current p_i) to S
      i++;        // advance i
                  // then change p to ensure p= p_i 
      p=  (next member p_i)   (***)
   }             
   output S;     

Great! For the loop we can use the "while" statement.
The only problem is (***). Look at the expression of S, when
we move, say from p= x^2/2! to the next_p= x^3/3! we need
just to multiply p with x/3, that is, next_p= p * x /3.

Math lovers: after "i++;", p is p_(i-1), so:
      p =  x^(i-1) / (i-1)!
and now we want p to be   x^i/i!
that can be done ith
      p = p * x / i;     

Now, look at the whole C program below
(There are some notes at the end of this file, don't just ignore them)
*/



#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-6

// function prototype, saying that the function has 1 double input
//     and return a double as its result
double e2x(double);  

int main(int argc, char *argv[]) {
    double x;
    
    // Part 1: input data
    printf("Computing e^x. Enter value for x: ");
    if ( scanf("%lf",&x) != 1 ) {
        printf("Invalid input.\n"
               "Please rerun and enter a real number such as 1.2\n");
        exit(EXIT_FAILURE);
    }
        
    // Part 2: compute & output result
    printf("EPSILON= %f, x= %f, e_to_x = %.6f\n", EPSILON, x, e2x(x));
    
    return 0;
}

// function implementation
double e2x(double x) {
	double s=0;    // for output
	double p;      // working variables
    int i;

    // process computing s= e^x
    i= 0;
    p= 1;   // now i=0 and the i-th member is x^0/0! ie 1

    while ( p >= EPSILON || p <= -EPSILON ) {  // while (|p| >= EPSILON)
        s= s+p;          // add i-th elements to S
        i= i + 1;        // goto next member
        p= p * x / i;    // 
    }  
 
    return s;      // finish function by stating the output
}
 
/* NOTES:

  1. Can I swap the order of lines 114-116?
     No, in general. The only possible swap is lines 114 and 115,
                     but that technically-correct swap is not logical
  
  2. Lines 110-113 could be replaced by a signle line:
     for (i=0, p=1; p>=EPSILON || p<=-EPSILON; ) {
     // note the empty update

  3. The whole loop in lines 110-117 could be replaced by:

     for (i=0, p=1; p>=EPSILON || p<=-EPSILON; i++, p *= (x/i) ) {
         s += p;
     }
       
  3. A bit ugly, but the whole loop in lines 110-117 could also be replaced by:

     for (i=0, p=1; p>=EPSILON || p<=-EPSILON; s+=p, i++, p *= (x/i) );
       
  
  4. The condition:
        p > EPSILON || p < -EPSILON 
     is probably longer than needed:
       4a) can we just write p > EPSILON ?
           NO, it's wrong if x<0
       4b) is there anyway to simplify that condition?
           YES, but we need to use a math function for absolute value.
           That function is fabs, and is defined in math.h, and implemented
           in math library. So in our program we need:
           #include <math.h>
           and change the abve condition to:
               fabs(p) >= EPSILON


       NOTEL if we are allowed to use math functions, then we can just use 
            s= exp(x);    
       to compute s, and delete the implementation of e2x(). OMG! 

  5. Is there any other way to write the above program?
     Yes, of course, there are plenty of different ways...

*/   


  
