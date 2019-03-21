/*
  e2x.c : compute e^x to the precision of EPSILON= 1e-6,
          NOT using the library function exp(),
          NOT using library math functions at all
  
  Anh Vo, anhvir@gmail.com, for comp20005 unimelb Workshop Week 4
  TOPIC: lean to use the while loop
  What's new: answering the questions posted in the previous version

  NOTES:
  The task is equivalent to:
  Compute S= 1 + x + x^2/2! + x^3/3! + ... +x^k/k!
    where k is the smallest integer that satisfies 
             | x^k / k! | < EPSILON
*/

/* DESIGN THOUGHTS:
We need to compute S= 1 + x + x^2/2! + x^3/3! + ...
We cannot just use one assignment for that, right?
But we can:
   - Start with, say, S= 0 
   - add up one (appropriate) member, say p, to S
How about:
   - fisrt set p = 1, then p is the first member
   - set S= p       , the the first member is accumulated to S
and then we can REPEAT the following process:
   - change p so that the new p equal to the next member
   - add p to S

We refine and detail our above thought as follows:
   p= 1;    // first member
   S= 1;    // now S includes first member
   loop:    // NOT forever, but stop when |p| < EPSILON
      p=  (next member)   (***)
      S= S + p;    // accumulate p to S
   endloop
   output S     

Great! For the loop we can use the "while" statement.
The only problem is (***). Look at the expression of S, when
we move, say from p= x^2/2! to the next_p= x^3/3! we need
just to multiply p with x/3, that is, next_p= p * x /3.

How can we have that 3? Now, look at the whole C program below
(There are some notes at the end of this file, don't ignore them)
*/



#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-6

int main(int argc, char *argv[]) {
    double s=0, x, p;
    int i;
    
    // Part 1: input data
    printf("Computing e^x. Enter value for x: ");
    if ( scanf("%f",&x) != 1 ) {
        printf("Please rerun and enter a real number such as 1.2\n");
        exit(EXIT_FAILURE);
    }
 
	    // Part 2: process computing s= e^x
/*(1)*/    i= 0;
/*(2)*/    p= 1;   // now i=0 and the i-th member is x^0/0! ie 1
/*(3)*/    s= p;
/*(4)*/    while ( p > EPSILON || p < -EPSILON ) {  // why so complicated?
/*(5)*/        i= i+ 1;         // goto next member
/*(6)*/        p= p * x / i;    // check in your paper if this's correct
/*(7)*/        s= s+p;          // add i-th elements to S
/*(8)*/    }   
        
          // Part 3: output result
/*(9)*/    printf("EPSILON= %f, e_to_x = %.6f\n", EPSILON, s);
    
    return 0;
}

/* QUESTIONS & ANSWERS:
  1. In (7), p is added to s. Should we remevoe (3)? 
     NO, the purpose of (3) is to keep the "loop invariant":
        "p is i-th member, S is the sum until the i-th element, inclusively"
     "loop invariant" is the thing we need to keep TRUE before entering the loop
         (7) makes the loop variant be correct before the the next round
     In more details:
       - just before (4): i=0 and the loop invariant
                        "p is 0-th member, S is sum until 0-th member"
       - at (5): i changed, so the loop invariant is no more correct
       - (6) and (7), in that order, make the loop invariant correct again
       - at (9) , the loop invariant is still correct, but now |p|<EPSILON
     So, we can see that our program is correct.  

  2. When designing, I used S, why did I used s instead in the C program?
     Oh no, we still can use S. But, as a rule for this course, we should not
         use capital letters for variable names!
 
  3. Regarding the guard in (4):
        p > EPSILON || p < -EPSILON 
     It seems to be longer than needed.
       5a) can we just write p > EPSILON ?
           NO, it's wrong if x<0
       4b) is there anyway to simplify that condition?
           YES, but we need to use a math function for absolute value.
           That function is fabs, and is defined in math.h, and implemented
           in math library. So in our program we need:
           #include <math.h>
           and chnage the abve condition to:
               fabs(p) > EPSILON

           And, for some old compiler, you need to compile with:
              gcc -Wall -o e2x e2x.c -lm
           where flag "-lm" specifies the math library (m for math).
           But note that many modern compilers don't require that, and it's
           ok if you write or don't write -lm

       NOTEL if we use math functions, then we can just use 
            s= exp(x);    
       to compute s, and delete lines 58-66. OMG! 

ADDITIONAL TASKS:
  4. Change program so that the precision become 1e-9 instead of 1e-6.

  5. Change the program so that it also outputs the number of time
     the while loop executed.
     Not terribly difficult here, just print out the value of i.
  
  6. Change the program so that, no matter what the value of EPSILON is, theloop will execute no more than 20 iterations (Yes, of course, please use #define for 20)

*/   


  
